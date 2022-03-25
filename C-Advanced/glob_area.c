/**
 * 内存四区之全局区分析
 */
#include <stdio.h>

char *get_str1() {
    char *p = "abcedf";//字符串放在全局区中的常量区
    return p;
}

char *get_str2() {
    char *q = "abcedf";//字符串放在全局区中的常量区
    return q;
}

int main() {
    char *p = NULL;
    char *q = NULL;
    p = get_str1();
    //%s:这里是指针指向内存区域的内容
    //%d %p:这里是 p 本身的值(内存地址)
    printf("p=%s,p=%p\n", p,p);//abcedf,0x100403000
    q= get_str2();
    printf("q=%s,q=%p\n", q,q);//abcedf,0x100403000
    //一样的
    return 0;
}