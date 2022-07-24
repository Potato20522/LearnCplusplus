#include <windows.h>
#include <stdio.h>

#define BUF_SIZE 256 //缓冲大小256

int main() {
    HANDLE hFileRead;
    DWORD nIn;//实际上读到的
    CHAR buffer[BUF_SIZE];//缓冲,256字节的字符数组

    //CreateFile既可以创建文件，又可以打开文件
    hFileRead = CreateFile(
            "E:\\Gitee\\LearnCplusplus\\C-study\\windows\\windows-api\\book1.txt",//文件名
            GENERIC_READ, //模式：读还是写
            FILE_SHARE_READ, //指定文件如何共享
            NULL,//安全属性，默认NULL
            OPEN_EXISTING,//打开已经存在的文件，而不是创建新的文件
            FILE_ATTRIBUTE_NORMAL,//设定文件的属性：常规
            NULL   //指定模板，这里没有
    );
    if (hFileRead == INVALID_HANDLE_VALUE) { //如果是一个无效的句柄，说明出错了
        printf("can not open file, Error:%lx\n", GetLastError());
        return -1;
    }
    //参数1：文件句柄，参数2：缓冲（想读多少）,参数3：最多读取多少,参数4：实际读取到多少个,参数5：没有用到
    while (ReadFile(hFileRead, buffer, BUF_SIZE, &nIn, NULL) && nIn > 0) {
//        printf("%s\n", buffer);
        printf("%s\n", buffer);
    }
    CloseHandle(hFileRead);//用完了要关掉句柄
    printf("hello\n");
    return 0;
}