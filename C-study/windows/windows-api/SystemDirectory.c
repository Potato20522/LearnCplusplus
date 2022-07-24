#include <windows.h>
#include <stdio.h>
//获取系统目录，并写入到文件中

int main(){
    //MAX_PATH=260,表示windows中文件的路径名最长是260，如C:\Program Files\filename.txt不能超过260
    TCHAR szSystemDir[MAX_PATH] ;
    GetSystemDirectory(szSystemDir, MAX_PATH);
    printf("%s\n", szSystemDir);//C:\Windows\system32

    HANDLE hFile;
    DWORD dwWritten;
    //文件名，模式：写，不共享，安全属性没有，总是创建文件，文件属性：常规，模板：无
    hFile = CreateFile("systemroot.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {//创建文件成功
        //文件句柄，写入的内容，写入的长度，真正写入的长度，是否覆盖：否
        if (!WriteFile(hFile, szSystemDir, lstrlen(szSystemDir), &dwWritten, NULL)) {
            return GetLastError();//写失败
        }
    }

    CloseHandle(hFile);//关闭句柄
    printf("OK\n");

    return 0;
}
