#include<iostream>
using namespace std;
class Person {
	friend ostream& operator<<(ostream& out, Person& p);
public:
	Person(int a, int b){
		this->m_A = a;
		this->m_B = b;
	}

	//成员函数 实现不了  p << cout 不是我们想要的效果
	//通常不会利用成员函数重载<<运算符，因为无法实现cout在左侧
	//void operator<<(Person& p){
	//}

private:
	int m_A;
	int m_B;
};

//全局函数实现左移重载
//ostream对象只能有一个
//ostream& out 引用就是起别名，所以这里叫什么名字无所谓
ostream& operator<<(ostream& out, Person& p) {
	out << "a:" << p.m_A << " b:" << p.m_B;
	return out;
}

void test() {
	Person p1(10, 20);
	cout << p1 << "hello world" << endl; //链式编程
}

int main() {
	test();
	system("pause");
	return 0;
}