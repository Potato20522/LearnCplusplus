/**
 * #warning 产生警告信息
 * 信息不需要使用双引号包围
 */
#include <stdio.h>
//例1
#ifdef __cplusplus //c++编译器宏
#warning 请使用g++,不能用gcc
#endif
//例2
#ifdef __linux__
#warning 请不要在linux系统下编译
#endif

int main(int argc, char *argv[]) {
#define CONST_NAME1 "CONST_NAME1"
    printf("%s\n", CONST_NAME1);
#undef CONST_NAME1 //这个去掉后，例3就能编译通过

//例3
#ifndef CONST_NAME1
#warning No defined Constant Symbol CONST_NAME1
#endif

#define CONST_NAME2 "CONST_NAME2"
    printf("%s\n", CONST_NAME2);
    printf("%s\n", CONST_NAME2);
    return 0;
}