/**
 * 栈的生长方向和内存存放方向
 * 栈：内存地址递减的
 * 堆：内存地址递增的
 * 栈中的数组：内存存放的方向递增
 * 堆中的数组：内存存放的方向递减
 * 也不绝对，和编译器有关
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a;
    int b;
    //&a = 00AFFC34, &b = 00AFFC28 栈：内存地址递减的
    printf("&a = %p, &b = %p\n",&a,&b);

    int buf[100];
    //buf:00AFFA90, buf+1:00AFFA94 栈中的数组：内存存放的方向递增
    printf("buf:%p, buf+1:%p\n",buf,buf+1);
    return 0;
}