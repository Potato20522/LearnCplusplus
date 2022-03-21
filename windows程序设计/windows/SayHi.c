#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow){
    //MB_OK替换成0也可以，1 就是出现两个按钮，一个确定，一个取消
    //使用 | 可以使用多个选项参数
    MessageBox(NULL, (LPCSTR) "这是第一个Windows程序", TEXT("打招呼"), MB_YESNO | MB_ICONASTERISK);
    return 0;
}

