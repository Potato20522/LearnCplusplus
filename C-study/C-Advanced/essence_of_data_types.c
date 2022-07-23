/**
 * 数据类型的本质: 固定内存大小的别名
 */
#include <stdio.h>

int main() {
    int a = 10;//告诉编译器，分配4个字节的内存
    int b[10]; //告诉编译器，分配4*10=40个字节的内存

    //打印地址,数组首元素地址，数组首地址，相等
    printf("b:%p, &b:%p\n",b,&b);//都是0xffffcc10

    //b+1:0xffffcc14, &b+1:0xffffcc38
    //数组首元素地址+1，加了4（int类型大小）
    //数组首地址+1，加了40（整个数组的大小），注意16进制转换
    //&运算符的优先级大于+号
    printf("b+1:%p, &b+1:%p\n",b+1,&b+1);

    printf("b:%p, b+1:%p, &b:%p, &b+1:%p \n", b, b + 1, &b, &b + 1);
    //b+1 和 &b + 1 的结果不一样，因为b和&b的数据类型不一样
    //b代表数组元素的首地址，&b代表整体数组的地址

    //指针类型长度，32位程序，长度4，64位程序，长度8
    char***********p=NULL;
    int *q = NULL;
    printf("%d,%d\n",sizeof(p), sizeof(q));//%lu: long unsigned
    return 0;
}