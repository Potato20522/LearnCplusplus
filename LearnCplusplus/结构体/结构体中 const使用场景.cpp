#include<iostream>
using namespace std;
//学生结构体定义
struct Student {
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
};

//const使用场景
void printStudent(const Student* stu) { //加const防止函数体中的误操作

	//stu->age = 100; //操作失败，因为加了const修饰
	cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;

}

int main() {
	Student stu = { "张三",18,100 };
	printStudent(&stu);

	system("pause");
	return 0;
}