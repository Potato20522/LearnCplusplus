#include<iostream>
using namespace std;

class Building;

class GoodGay{
public:
	GoodGay();
	void visit();
private:
	Building* building;
};

class Building{
	//告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
	friend class GoodGay;
public:
	Building();

public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};
//类外实现成员函数
Building::Building(){
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}
//类外实现成员函数
GoodGay::GoodGay(){
	building = new Building;
}

void GoodGay::visit(){
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void test01(){
	GoodGay gg;
	gg.visit();
}

int main() {
	test01();
	system("pause");
	return 0;
}