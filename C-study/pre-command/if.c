/**
* 条件编译命令
 * #if、#else，#elif及#endif
 * 1.#if的一般含义是如果#if后面的常量表达式为true，
 *   则编译它与#endif之间的代码，否则跳过这些代码。
 *   命令#endif标识一个#if块的结束。
 *   http://c.biancheng.net/c/ifdef/
*/

#include <stdio.h>

#define OS 1

int main() {
#if OS == 1
    printf("V1.0");
#elif OS == 2
    printf("V2.0");
#else
    printf("未知");
#endif
    return 0;
}