#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//指针也是一种数据类型,指针变量也是一种变量
int main() {
    int *p = NULL;
    char **********q = NULL;
    printf("sizeof(p)=%d,sizeof(q)=%d\n", sizeof(p), sizeof(q));//32位：4

    //指针指向谁，就把谁的地址赋值给指针
    int a = 100;
    int *p1 = NULL;
    p1 = &a;
    //通过*号找到指针指向的内存区域，操作内存
    *p1 = 22;//a和p1的值都变成22
    //*放在=左边，给内存赋值，写内存，
    //*放在=右边，取内存的值，读内存
    int b = *p1;//22

    return 0;

}