/**
 * 变量的本质: 一段连续内存空间的别名
 */
#include <stdio.h>

int main() {
    //变量相当于门牌号，内存相当于房间
    int a;
    int *p;

    //直接赋值
    a = 10;
    printf("a=%d\n", a);

    //间接赋值
    printf("a=%p\n", &a);//a=0xffffcc34
    p = &a;
    printf("p=%p\n", p);//p=0xffffcc34

    *p = 22;
    printf("*p = %d, a = %d\n", *p, a);//22,22
    return 0;
}