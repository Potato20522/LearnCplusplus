//Windows10系统开启UAC的方法 https://www.xitongcheng.com/jiaocheng/win10_article_42200.html
//运行UserAccountControlSettings.exe
#include <stdio.h>
#include <Windows.h>

BOOL EnablePrivileges(HANDLE hProcess, char* pszPrivilegesName);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
    // 修改当前进程令牌访问权限
    if (FALSE == EnablePrivileges(GetCurrentProcess(), SE_DEBUG_NAME)) {
        printf("Enable Privileges Error!\n");
    }
    else {
        printf("Enable Privileges OK!\n");
    }
    return 0;
}


void ShowError(char* pszText) {
    char szErr[MAX_PATH] = { 0 };
    wsprintf(szErr, "%s Error[%d]\n", pszText, GetLastError());
    MessageBox(NULL, szErr, "ERROR", MB_OK);
}

BOOL EnablePrivileges(HANDLE hProcess, char* pszPrivilegesName) {
    HANDLE hToken = NULL;
    LUID luidValue = { 0 };
    TOKEN_PRIVILEGES tokenPrivileges = { 0 };
    BOOL bRet = FALSE;
    DWORD dwRet = 0;


    // 打开进程令牌并获取具有 TOKEN_ADJUST_PRIVILEGES 权限的进程令牌句柄
    bRet = OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
    if (FALSE == bRet) {
        ShowError("OpenProcessToken");
        return FALSE;
    }
    // 获取本地系统的 pszPrivilegesName 特权的LUID值
    bRet = LookupPrivilegeValue(NULL, pszPrivilegesName, &luidValue);
    if (FALSE == bRet) {
        ShowError("LookupPrivilegeValue");
        return FALSE;
    }
    // 设置提升权限信息
    tokenPrivileges.PrivilegeCount = 1;
    tokenPrivileges.Privileges[0].Luid = luidValue;
    tokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    // 提升进程令牌访问权限
    bRet = AdjustTokenPrivileges(hToken, FALSE, &tokenPrivileges, 0, NULL, NULL);
    if (FALSE == bRet) {
        ShowError("AdjustTokenPrivileges");
        return FALSE;
    }
    else {
        // 根据错误码判断是否特权都设置成功
        dwRet = GetLastError();
        if (ERROR_SUCCESS == dwRet) {
            return TRUE;
        }
        else if (ERROR_NOT_ALL_ASSIGNED == dwRet) {
            ShowError("ERROR_NOT_ALL_ASSIGNED");
            return FALSE;
        }
    }

    return FALSE;
}