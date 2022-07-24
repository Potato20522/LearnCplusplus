#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
    int i;
    INT i2;

    char c;
    CHAR c2;

    wchar_t c3;
    WCHAR c4;

    TCHAR c5;

    //A版
    PCHAR a;//字符指针，P表示指针
    //W版
    PWCHAR a2;
    //T版
    PTCHAR a3;

    //A版
    PSTR b;//字符串指针,实际上和字符指针一样的
    LPSTR b2 = "string";//LPSTR中L写不写都行
    //W版
    PWSTR b3;
    LPWSTR b4 = L"string";
    //T版
    PTSTR b5;
    LPTSTR b6 = TEXT("string"); //TEXT会根据项目设置来选择是A版还是W版，即"string"或L"string"

    //A版
    PCSTR d;//typedef CONST CHAR *LPCSTR,*PCSTR 常量字符指针
    //W版
    PCWSTR d2;
    //T版
    PCTSTR d3;

    MessageBoxW(NULL, L"这是W版的MessageBox", L"Test", MB_OK);
    MessageBoxA(NULL, "这是A版的MessageBox", "Test", MB_OK);
    MessageBox(NULL, TEXT("这是T版的MessageBox"), TEXT("Test"), MB_OK);

    return 0;
}

