/**
 * 内存四区之栈区和堆区
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_str() {
    //"abcdefg"在全局区
    //对于数组，编译器会将全局区的"abcdefg"再拷贝一份到栈区的str[]
    char str[] = "abcdefg";//分配在栈区，函数执行完毕，局部变量就释放了
    //warning C4172: 返回局部变量或临时变量的地址: str
    return str;
}

char *get_str2() {
    char *temp = (char *) malloc(100); //堆区
    if (temp == NULL) {
        return NULL;
    }
    strcpy(temp,"asdfxgsdf");
    return temp;
}

int main() {
    char buf[128] = {0};
    //vs编译器下能打印出来是因为，已经把字符串拷贝拷贝出来了
    strcpy(buf, get_str());//不确定，有可能打印出来(vs)，还有可能编译报错(gcc)
    printf("buf=%s\n", buf);
    char *p = NULL;
    p = get_str();//vs-debug能正常显示，vs-release乱码
    printf("p=%s\n", p);

    p = get_str2();
    if (p != NULL) {
        printf("p=%s\n", p);
        free(p);//free不是清除数据，是置一个标志位，告诉操作系统这块内存可以用了。
        //p的指向还是不变的，还是可以用的，因此要给p指向空
        p = NULL;
        //一般，还要加一句：
        if (p != NULL) {
            free(p);
        }
    }
    return 0;
}