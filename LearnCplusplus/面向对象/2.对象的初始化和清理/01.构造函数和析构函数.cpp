#include<iostream>
using namespace std;
class Person{
public:
	//我们不提供的话，编译器会自动提供一个空实现的构造和析构
	//构造函数
	Person(){
		cout << "Person的构造函数调用" << endl;
	}
	//析构函数
	~Person(){
		cout << "Person的析构函数调用" << endl;
	}
};

void test01(){
	Person p;
}

int main() {
	test01();
	system("pause");
	return 0;
}