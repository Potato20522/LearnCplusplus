#include<iostream>
using namespace std;
//菱形继承导致数据有两份
class Animal{
public:
	int m_Age;
};

//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
//m_Age现在只有一份了
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

void test01(){
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}