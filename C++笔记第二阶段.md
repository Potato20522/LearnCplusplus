本阶段主要针对C++泛型编程和STL技术做详细讲解，探讨C++更深层的使用。

[《黑马》——C++提高编程_漏网小鱼的博客-CSDN博客](https://blog.csdn.net/ClaireSy/article/details/108423061)

# 模板

C++泛型的实现

## 模板的概念

模板就是建立**通用的模具**，大大**提高复用性**

模板的特点：

- 模板不可以直接使用，它只是一个框架
- 模板的通用并不是万能的

## 函数模板

- C++另一种编程思想称为 **泛型编程** ，主要利用的技术就是模板
- C++提供两种模板机制:**函数模板**和**类模板**

#### 函数模板语法

类比java的泛型函数

函数模板作用：

建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个**虚拟的类型**来代表。

**语法：**

```c++
template<typename T>
函数声明或定义
```

**解释：**

template — 声明创建模板

typename — 表面其后面的符号是一种数据类型，可以用class代替

T — 通用的数据类型，名称可以替换，通常为大写字母

```c++
#include<iostream>

using namespace std;

//交换整型函数
void swapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//交换浮点型函数
void swapDouble(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

//利用模板提供通用的交换函数
template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void test01() {
    int a = 10;
    int b = 20;

    //swapInt(a, b);

    //利用模板实现交换
    //1、自动类型推导
    mySwap(a, b);

    //2、显示指定类型
    mySwap<int>(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}

int main() {
    test01();
    return 0;
}
```

总结：

- 函数模板利用关键字 template
- 使用函数模板有两种方式：自动类型推导、显示指定类型
- 模板的目的是为了提高复用性，将类型参数化