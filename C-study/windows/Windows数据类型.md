# Windows数据类型

c语言数据类型

int float doule ...

windows数据类型：

windows把C语言中已经有的数据类型全部定义成了大写，比如：INT，FLOAT，然后又定义了大量的数据类型

BOOL,BYTE ,CHAR,CONST,DWORD,DWORD32,DWORD64,FLOAT,HANDLE,HICON, HINSTANCE, HKEY, HMODULE, HWND, INT,INT_PRT,....太多了

```c
#include <stdio.h>
#include <Windows.h>

int main() {
	LPSTR szString = TEXT("Windows data type:string");//CHAR*
	CHAR lpString[120];//char
	DWORD dwMax = 0xFFFFFFFF;//unsigned long 
	DWORD dwOne = 0x1;
	INT iMax = 0xFFFFFFFF;//有符号整数int ,-1
	INT iOne = 0x1;
	MessageBox(NULL, szString, TEXT("LPSTR"), MB_OK);
	//内存拷贝，参数1：目标，参数2：源
	CopyMemory(lpString, szString,lstrlen(szString)+1);	
	MessageBox(NULL, lpString, TEXT("CHAR[]"), MB_OK);
	if (dwMax > dwOne) {
		MessageBox(NULL, TEXT("DWORD类型的数据是0xFFFFFFFF>0x1"), TEXT("DWORD"), MB_OK);
	}

	if (iMax < iOne) {
		MessageBox(NULL, TEXT("INT类型的数据是0xFFFFFFFF<0x1"), TEXT("DWORD"), MB_OK);
	}

	//句柄类型
	HANDLE h;//句柄
	HICON hIcon;//图标句柄
	HINSTANCE hInstance;//程序实例句柄
	HKEY hKey;//操作注册表时的key句柄
	HMODULE hModule;//模块句柄
	HWND hWnd;//窗口句柄
	return 0;
}
```

所有的Windows数据类型都有W版和A版

# Windows数据类型与WIndows API函数的关系

看两个函数

```c
int MessageBoxW(
  HWND hWnd,
  LPCWSTR lpText,
  LPCWSTR lpCaption,
  UINT uType;
);

BOOL ReadFile(
  HANDLE hFile,
  LPVOID lpBuffer,
  DWORD nNumberOfBytesRead,
  LPDWORD lpNumberOfBytesRead,
  LPOVERLAPPED lpOverlapped,
);
```

