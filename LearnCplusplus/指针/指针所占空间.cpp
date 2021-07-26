#include<iostream>
using namespace std;
int main() {

	int a = 10;

	int* p; //int * p = &a;
	p = &a; //指针指向数据a的地址

	//32位编译器下指针占用4字节，不管是什么数据类型
	//64位编译器下指针占用8字节，不管是什么数据类型
	cout << *p << endl; //* 解引用
	cout << sizeof(p) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(float*) << endl;
	cout << sizeof(double*) << endl;

	//system("pause");

	return 0;
}