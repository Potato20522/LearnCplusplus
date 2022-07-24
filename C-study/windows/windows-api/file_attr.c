#include <windows.h>
#include <stdio.h>
DWORD ShowFileTime(PFILETIME lptime){
    FILETIME ftLocal;//转换以后的本地的文件时间
    SYSTEMTIME  st;//windows系统时间
    //1.文件时间转为本地的文件时间
    FileTimeToLocalFileTime(lptime,&ftLocal);
    //2.文件时间转为windows系统时间
    FileTimeToSystemTime(&ftLocal, &st);
    printf("%d年%d月%d日，%#02d:%#02d:%#02d\n", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    return 0;
}
int main() {
    WIN32_FILE_ATTRIBUTE_DATA wfad;
    if (!GetFileAttributesEx("E:\\Gitee\\LearnCplusplus\\C-study\\windows\\windows-api\\file_attr.c", GetFileExInfoStandard, &wfad)) {
        printf("获取文件属性失败:%d\n", GetLastError());
        return 1;
    }
    //wfad.ftCreationTime的类型是一个紧凑的时间类型，需要写个函数转化后才能看懂
    printf("创建时间:\t");
    ShowFileTime(&wfad.ftCreationTime);

    printf("访问时间:\t");
    ShowFileTime(&wfad.ftLastAccessTime);

    printf("修改时间:\t");
    ShowFileTime(&wfad.ftLastWriteTime);
    return 0;
}