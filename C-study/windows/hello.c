#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
    //参数1：父窗口句柄，没有父窗口就是NULL,
    //参数2：提示框内容,
    //参数3：标题栏,
    //参数4：按钮,MB_OK替换成0也可以，1 就是出现两个按钮，一个确定，一个取消,使用 | 可以使用多个选项参数
    MessageBox(NULL, "hello world", "Information", MB_YESNO | MB_ICONASTERISK);
    return 0;
}

