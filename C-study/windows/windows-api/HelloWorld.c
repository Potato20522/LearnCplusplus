#include <stdio.h>
// gcc -nostartfiles -e fn .\HelloWorld.c -o a -fno-exceptions -s
// -s参数或者strip a.exe
//#pragma comment(linker, "/entry:fn")
int fn(){
    puts("hello world");
    return 0;
}
