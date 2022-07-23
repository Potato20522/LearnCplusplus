/**
 * 静态局部变量
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *getA(){
    static int a = 10;
    return &a;
}


int main() {
    int *p = getA();
    return 0;
}