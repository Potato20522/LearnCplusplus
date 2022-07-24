# 宽字符

在C语言中，除了普通的，还有宽字符

| 原     | 宽      |
| ------ | ------- |
| char   | wchar_t |
| printf | wprintf |
| strlen | wcslen  |
| strcpy | wcscpy  |
| strcat | wcscat  |
| strcmp | wsccmp  |
| strsrt | wscstr  |
| ...... | ......  |
|        |         |

```c
#include <stdio.h>
#include <locale.h>
#include <string.h>
int main(){
    //Locale is C (C语言最小的编译环境中的地狱)
    printf("Locale is %s\n", setlocale(LC_ALL, NULL));

    //更改默认的地域，加了这个才能显示宽字符
    //参数2：表示设置当前windows默认的locale环境(936 GBK)
    setlocale(LC_ALL, "");

    //Locale is Chinese (Simplified)_China.936
    printf("Locale is %s\n", setlocale(LC_ALL, NULL));

    char c = 'A';
    printf("%c\n", c);

    wchar_t c2 = L'中';
    wprintf(L"%c\n", c2);

    char s[] = "hello";
    wchar_t s2[] = L"宽字符字符串";
    printf("%s\n", s);
    wprintf(L"%s\n", s2);
    printf("%d\n", strlen(s));
    printf("%d\n", wcslen(s2));


    return 0;
}
```



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

所有的Windows数据类型都有W版和A版（和字符相关的API函数）

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

微软在用C语言写Windows时，大量使用了windows自定义的数据类型，直接使用C语言的数据类型不多。

# 三种版本

微软把C语言的数据类型全部重新定义了，变成了大写，而且有多个版本

| A（ASCII版本） | W（宽字符） | T（通用版本） |
| -------------- | ----------- | ------------- |
| CHAR           | WCHAR       | TCHAR         |
| PCHAR          | PWCHAR      | PTCHAR        |
| PSTR           | PWSTR       | PTSTR         |
| PCSTR          | PCWSTR      | PCTSTR        |
| ...            | ...         | ...           |
| MessageBoxA    | MessageBoxW | MessageBox    |
| ...            | ...         | ...           |

T（通用版本），里面定义了宏，会根据项目的字符集设置，自动变成A版或W版



```c
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow){
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

    return 0;
}
```

WinMain函数也有多个版本

- A版 WinMain
- W版 wWinMain
- T版  _tWinMain

MessageBox的多个版本

```c

MessageBoxW(NULL, L"这是W版的MessageBox", L"Test", MB_OK);
MessageBoxA(NULL, "这是A版的MessageBox", "Test", MB_OK);
MessageBox(NULL, TEXT("这是T版的MessageBox"), TEXT("Test"), MB_OK);
```

**推荐用T版的API**
