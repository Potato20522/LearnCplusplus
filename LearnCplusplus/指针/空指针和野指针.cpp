#include<iostream>
using namespace std;

int main() {
	//1.空指针用于给指针遍历进行初始化
	int* p = NULL;
	//2.空指针是不可以进行访问的
	//0到255之间的内存编号是给系统占用的，因此不可以访问
	//cout << *p << endl;

    //指针变量p指向内存地址编号为0x1100的空间
	int* p2 = (int*)0x1100;

	//访问野指针报错 
	//cout << *p2 << endl;//引发了异常: 读取访问权限冲突。
	return 0;
}