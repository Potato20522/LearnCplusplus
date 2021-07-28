#include<iostream>
using namespace std;

class Building;
class GoodGay {
public:
	GoodGay();
	void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
	void visit2();
private:
	Building* building;
};

class Building {
	//告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
	friend void GoodGay::visit();
public:
	Building();
public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};

Building::Building() {
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

GoodGay::GoodGay() {
	building = new Building;
}

void GoodGay::visit() {
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void GoodGay::visit2() {
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	//cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void test01() {
	GoodGay gg;
	gg.visit();
}

int main() {
	test01();
	system("pause");
	return 0;
}