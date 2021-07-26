#include<iostream>
using namespace std;
//成员属性设置为私有
//1.可以自己控制读写权限
//2.对于写可以检测数据的有效性
class Person {
private:
	string m_name;
	int m_age;
	string m_lover;
public:
	void setName(string name) {
		m_name = name;
	}
	string getName() {
		return m_name;
	}
	int getAge() {
		m_age = 10;
		return m_age;
	}
	void setLover(string lover) {
		m_lover = lover;
	}
};
int main() {
	Person p;
	p.setName("张三");
	cout << "姓名为:" << p.getName() << endl;
	system("pause");
	return 0;
}