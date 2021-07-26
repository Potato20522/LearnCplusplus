#include<iostream>
using namespace std;

int main() {
	int a = 10;
	int * p;
	p = &a;
	cout << "a的地址为：" << &a << endl;
	cout << "指针p为：" << p << endl;
	*p = 100;
	return 0;
}