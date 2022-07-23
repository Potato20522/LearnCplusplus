#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01() {
    int a[] = {10, 7, 1, 9, 4, 6, 7, 3, 2, 0};
    //这样写a是数组类型，sizeof(a)就是元素个数*元素的字节数
    int n = sizeof(a) / sizeof(a[0]); //数组元素的个数
    printf("排序前：");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    //选择排序
    int temp = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {//升序
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("排序后：");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
/**
 * 这样写都对：
 * void print_array(int a[], int n)
 * void print_array(int a[1], int n)
 * 如果数组作为函数参数，数组形参退化为指针，所以形参里a[1]写成a[100]可以，随便写什么数
 * 方括号里数字是没有意义的
 * 还可以这样写：
 * void print_array(int *a, int n)
 * 那怎么知道它退化成指针了呢?利用：n = sizeof(a) / sizeof(a[0]);
 */
void print_array(int *a, int n) {
    //a，当作指针用，指针类型，32位的4个字节，64位8个字节
    //int 类型是4个字节，因此 n = 8 /4 =2
    n = sizeof(a) / sizeof(a[0]);
    printf("print_array:n=%d\n",n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
}

void sort_array(int a[], int n) {
    //选择排序
    int temp = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {//升序
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(void) {
    int a[] = {10, 7, 1, 9, 4, 6, 7, 3, 2, 0};
    int n = sizeof(a) / sizeof(a[0]); //数组元素的个数
    printf("排序前：\n");
    print_array(a, n);
    sort_array(a, n);
    printf("排序后：\n");
    print_array(a, n);
    printf("\n");
    return 0;
}