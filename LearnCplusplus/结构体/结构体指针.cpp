#include<iostream>
using namespace std;
//结构体定义
struct Student{
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

int main() {
	struct Student stu = { "张三",18,100, };
	struct Student* p = &stu;
	p->score = 80; //指针通过 -> 操作符可以访问成员

	cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

	system("pause");
	return 0;
}