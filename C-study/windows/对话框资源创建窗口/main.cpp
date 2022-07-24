#include <windows.h>
#include <stdio.h>
#include "resource.h"
INT_PTR CALLBACK MainDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	BOOL bRet = TRUE;
    //������Ϣ
    switch (uMsg) {
    case WM_CLOSE://�رմ���
        EndDialog(hwnd,0);//�˳���Ϣ
        break;
    case WM_LBUTTONDOWN:
        MessageBox(hwnd, L"hello����!", L"����", MB_OK);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDC_BUTTON1:
            MessageBox(hwnd, L"hello button1!", L"����", MB_OK);
            break;
        case IDC_BUTTON4:
            MessageBox(hwnd, L"hello button4!", L"����", MB_OK);
            break;
        default:
            bRet = FALSE;
            break;
        }
        break;
    default:
        //����Ҫ�������Ϣת��windows����
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
	return bRet;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MainDlgProc);
	return 0;
}