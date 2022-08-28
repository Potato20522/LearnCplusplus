//Windows10ϵͳ����UAC�ķ��� https://www.xitongcheng.com/jiaocheng/win10_article_42200.html
//����UserAccountControlSettings.exe
#include <stdio.h>
#include <Windows.h>

BOOL EnablePrivileges(HANDLE hProcess, char* pszPrivilegesName);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
    // �޸ĵ�ǰ�������Ʒ���Ȩ��
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


    // �򿪽������Ʋ���ȡ���� TOKEN_ADJUST_PRIVILEGES Ȩ�޵Ľ������ƾ��
    bRet = OpenProcessToken(hProcess, TOKEN_ADJUST_PRIVILEGES, &hToken);
    if (FALSE == bRet) {
        ShowError("OpenProcessToken");
        return FALSE;
    }
    // ��ȡ����ϵͳ�� pszPrivilegesName ��Ȩ��LUIDֵ
    bRet = LookupPrivilegeValue(NULL, pszPrivilegesName, &luidValue);
    if (FALSE == bRet) {
        ShowError("LookupPrivilegeValue");
        return FALSE;
    }
    // ��������Ȩ����Ϣ
    tokenPrivileges.PrivilegeCount = 1;
    tokenPrivileges.Privileges[0].Luid = luidValue;
    tokenPrivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    // �����������Ʒ���Ȩ��
    bRet = AdjustTokenPrivileges(hToken, FALSE, &tokenPrivileges, 0, NULL, NULL);
    if (FALSE == bRet) {
        ShowError("AdjustTokenPrivileges");
        return FALSE;
    }
    else {
        // ���ݴ������ж��Ƿ���Ȩ�����óɹ�
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