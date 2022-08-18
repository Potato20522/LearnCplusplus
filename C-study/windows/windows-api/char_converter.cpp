/**
* 字符转换
*/
#include <windows.h>
#include <stdio.h>
#include <locale.h>

int main() {
    //记录宽字符串里需要多少个字符
    int dwNum;
    setlocale(LC_ALL, "");
    char sText[] = "多字节字符串转宽字符串";
    //参数1：CP_ACP表示ANSI字符,参数2：控制标志，一般用不到，设为0就行,参数3：被转换的字符串
    //参数4： -1表示转换全部长度,参数5：NULL指针表示不进行转换,参数6：0表示我们这里用来计算需要多大的存储空间
    dwNum = MultiByteToWideChar(CP_ACP, 0, sText, -1, NULL, 0);
    wchar_t *pwText;
    pwText = new wchar_t[dwNum];
    if (!pwText) {//分配的内存失败了就结束
        delete[] pwText;
        return 1;
    }
    MultiByteToWideChar(CP_ACP, 0, sText, -1, pwText, dwNum);
    //宽字符用wprintf打印
    wprintf(L"M->W: %s\n", pwText);
    MessageBoxW(NULL, pwText, L"Test", MB_OK);
    delete[] pwText;

    //2.宽字符转为多字节字符
    wchar_t wText[] = L"宽字符串转多字节字符串";
    //CP_OEMCP windows默认使用的
    //需要多大的空间,最后两个用不到设为NULL
    dwNum = WideCharToMultiByte(CP_OEMCP, 0, wText, -1, NULL, 0, NULL, NULL);
    char *psText;
    psText = new char[dwNum];
    if (!psText) {
        delete[] psText;
        return 2;
    }
    WideCharToMultiByte(CP_OEMCP, 0, wText, -1, psText, dwNum, NULL, NULL);
    printf("W->M: %s\n", psText);
    MessageBoxA(NULL, psText, "Test", MB_OK);
    delete[] psText;
    return 0;
}