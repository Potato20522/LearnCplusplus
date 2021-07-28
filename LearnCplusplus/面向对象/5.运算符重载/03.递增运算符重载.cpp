#include<iostream>
using namespace std;
//重载递增运算符
//自定义整形
class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger() {
		num = 0;
	}
	//重载前置++运算符,返回引用为了一直对一个数据进行递增操作
	MyInteger& operator++() {
		num++;
		return *this;
	}
	//重载后置++运算符,一定要返回的是值
	//operator++(int) int代表占位参数，用于区分前置和后置递增
	MyInteger operator++(int) {
		//先记录当前结果
		MyInteger temp = *this;
		//后递增
		num++;
		//最后将记录结果做返回
		return temp;
	}
private:
	int num;
};

//重载<<运算符
ostream& operator<<(ostream& cout, MyInteger myint) {
	cout << myint.num;
	return cout;
}
void test01() {
	MyInteger myint;
	cout << ++myint << endl;
	cout << ++(++myint) << endl;
}
void test02() {
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main() {
	//test01();
	test02();
}