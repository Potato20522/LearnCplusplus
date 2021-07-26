#include<iostream>
using namespace std;
int* func(){
	//利用new关键字，可以将数据开辟到堆区
	//这里的指针本质也是局部变量，放在栈上，指针保存的数据放在堆区
	int* a = new int(10);//地址
	return a;
}

int main() {

	int* p = func();

	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}