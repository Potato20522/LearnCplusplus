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