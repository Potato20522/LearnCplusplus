# 预备

面向对象是一种思想，只要实现了封装、继承和多态这三大特征就是面向对象!

## 结构体包含函数

[C语言结构体中如何包含函数_魏波-CSDN博主-CSDN博客_c语言结构体函数](https://blog.csdn.net/weibo1230123/article/details/81532318)

## 封装属性和方法

[C语言实现面向对象（转） - 小时候挺菜 - 博客园 (cnblogs.com)](https://www.cnblogs.com/zzdbullet/p/10563075.html)

## 模拟继承

[用c模拟面向对象编程_学者的博客-CSDN博客](https://blog.csdn.net/u013749051/article/details/102797275)

[用C模拟面向对象2(模拟OOP)_学者的博客-CSDN博客](https://blog.csdn.net/u013749051/article/details/109686536)

```c
#include <stdio.h>

void baseShow() {
	printf("base");
}

struct Base {
	void (*show)() = baseShow;
};

struct Child {
	Base base;   //必须放在最前面
	//...其它成员
};


int main() {
	Child child;

	((Base*)& child)->show();
}