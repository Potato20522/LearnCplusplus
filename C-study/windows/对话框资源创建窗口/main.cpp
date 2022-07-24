#include <windows.h>
#include <stdio.h>
#include "resource.h"
INT_PTR CALLBACK MainDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	BOOL bRet = TRUE;
    //处理消息
    switch (uMsg) {
    case WM_CLOSE://关闭窗口
        EndDialog(hwnd,0);//退出消息
        break;
    case WM_LBUTTONDOWN:
        MessageBox(hwnd, L"hello窗口!", L"标题", MB_OK);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDC_BUTTON1:
            MessageBox(hwnd, L"hello button1!", L"标题", MB_OK);
            break;
        case IDC_BUTTON4:
            MessageBox(hwnd, L"hello button4!", L"标题", MB_OK);
            break;
        default:
            bRet = FALSE;
            break;
        }
        break;
    default:
        //不需要处理的消息转给windows处理
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
	return bRet;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MainDlgProc);
	return 0;
}