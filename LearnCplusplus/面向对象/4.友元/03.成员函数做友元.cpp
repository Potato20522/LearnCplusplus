#include<iostream>
using namespace std;

class Building;
class GoodGay {
public:
	GoodGay();
	void visit(); //ֻ��visit������ΪBuilding�ĺ����ѣ����Է�����Building��˽������
	void visit2();
private:
	Building* building;
};

class Building {
	//���߱�����  goodGay���е�visit��Ա���� ��Building�����ѣ����Է���˽������
	friend void GoodGay::visit();
public:
	Building();
public:
	string m_SittingRoom; //����
private:
	string m_BedRoom;//����
};

Building::Building() {
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
}

GoodGay::GoodGay() {
	building = new Building;
}

void GoodGay::visit() {
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << building->m_BedRoom << endl;
}

void GoodGay::visit2() {
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	//cout << "�û������ڷ���" << building->m_BedRoom << endl;
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