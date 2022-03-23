/**
 * 给类型起别名
 */
#include <stdio.h>

typedef unsigned int u32;

struct MyStruct{
    int a;
    int b;
};
//typedef通常和结构体一起使用，很方便
typedef struct MyStruct2{
    int a;
    int b;
} TMP;

int main(){
    u32 t;
    //定义结构体变量，一定要加上 struct 关键字
    struct MyStruct ml;
    //MyStruct ml2; //结构体变量不加struct，编译报错
    TMP m3; //使用typedef起别名后，就可以不用加struct

    return 0;
}