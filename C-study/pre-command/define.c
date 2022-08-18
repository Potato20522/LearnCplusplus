/**
 * define 仅仅是文本替换
 */
#define XYZ "test"
#define XYZ2 test2
#define LONG_STRING "this is a very long string\
that is used as an example"
#include <stdio.h>
int main() {
    printf("%s\n",XYZ);
    int XYZ2 = 1;
    printf("%s\n",LONG_STRING);
    return 0;
}


