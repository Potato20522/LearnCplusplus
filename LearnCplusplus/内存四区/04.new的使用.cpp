#include<iostream>
using namespace std;
//1.new的基本语法
int* func() {
	//在堆区创建整形数据
	//new返回的是 该数据类型的指针
	int* p = new int(10);
	return p;

}
void test01() {
	int* p = func();
	cout << *p << endl;
	//堆区的数据 由程序员管理开辟，程序员管理释放
	// delete关键字来释放
	delete p;
	//cout << *p << endl;//内存已经释放，再次访问就是非法操作，报错
}
//2.在堆区利用new开辟数组
void test02() {
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
	//释放数组时，要加[]才可以
	delete[] arr;
}
int main() {
	//test01();

	test02();

	return 0;
}