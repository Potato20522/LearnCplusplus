#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
    int i;
    INT i2;

    char c;
    CHAR c2;

    wchar_t c3;
    WCHAR c4;

    TCHAR c5;

    //A��
    PCHAR a;//�ַ�ָ�룬P��ʾָ��
    //W��
    PWCHAR a2;
    //T��
    PTCHAR a3;

    //A��
    PSTR b;//�ַ���ָ��,ʵ���Ϻ��ַ�ָ��һ����
    LPSTR b2 = "string";//LPSTR��Lд��д����
    //W��
    PWSTR b3;
    LPWSTR b4 = L"string";
    //T��
    PTSTR b5;
    LPTSTR b6 = TEXT("string"); //TEXT�������Ŀ������ѡ����A�滹��W�棬��"string"��L"string"

    //A��
    PCSTR d;//typedef CONST CHAR *LPCSTR,*PCSTR �����ַ�ָ��
    //W��
    PCWSTR d2;
    //T��
    PCTSTR d3;

    MessageBoxW(NULL, L"����W���MessageBox", L"Test", MB_OK);
    MessageBoxA(NULL, "����A���MessageBox", "Test", MB_OK);
    MessageBox(NULL, TEXT("����T���MessageBox"), TEXT("Test"), MB_OK);

    return 0;
}

