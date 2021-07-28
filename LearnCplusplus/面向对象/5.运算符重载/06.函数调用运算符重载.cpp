#include<iostream>
using namespace std;
class MyPrint{
public:
	void operator()(string text){
		cout << text << endl;
	}

};
void test01(){
	//重载的（）操作符 也称为仿函数
	MyPrint myFunc;
	myFunc("hello world");
}


class MyAdd{
public:
	//仿函数非常灵活，没有固定写法
	int operator()(int v1, int v2){
		return v1 + v2;
	}
};

void test02(){
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	//匿名对象调用  
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}