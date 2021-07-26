#include<iostream>
using namespace std;
//栈区数据注意事项--不要返回局部变量的地址
//栈区的数据由编译器管理开辟和释放
int* func(){//形参数据也会放在栈区
	int a = 10;//局部变量放在栈区，栈区的数据在函数执行完成后自动释放
	return &a;//返回局部变量a的地址
}

int main() {
	int* p = func();

	cout << *p << endl;//第一次可以打印正确的数字，因为编译器做了保留
	cout << *p << endl;

	system("pause");
	return 0;
}