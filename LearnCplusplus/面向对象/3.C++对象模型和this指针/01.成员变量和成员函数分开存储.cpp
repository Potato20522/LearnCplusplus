#include<iostream>
using namespace std;
class Person {
public:
	Person() {
		mA = 0;
	}
	//非静态成员变量占对象空间
	int mA;
	//静态成员变量不占对象空间
	static int mB;
	//函数也不占对象空间，所有函数共享一个函数实例
	void func() {
		cout << "mA:" << this->mA << endl;
	}
	//静态成员函数也不占对象空间
	static void sfunc() {
	}
};

int main() {
	//空对象占用1个字节，为了区分空对象占内存的位置,每个空对象也应该有个独一味二的内存地址
	Person p;
	cout << "sizeof Person=" << sizeof(Person) << endl;
	cout << "sizeof p=" << sizeof(p) << endl;
	system("pause");
	return 0;
}