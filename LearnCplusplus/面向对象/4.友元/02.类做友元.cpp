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
	//���߱����� goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������
	friend class GoodGay;
public:
	Building();

public:
	string m_SittingRoom; //����
private:
	string m_BedRoom;//����
};
//����ʵ�ֳ�Ա����
Building::Building(){
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
}
//����ʵ�ֳ�Ա����
GoodGay::GoodGay(){
	building = new Building;
}

void GoodGay::visit(){
	cout << "�û������ڷ���" << building->m_SittingRoom << endl;
	cout << "�û������ڷ���" << building->m_BedRoom << endl;
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