#include<iostream>
using namespace std;
//���ص��������
//�Զ�������
class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger() {
		num = 0;
	}
	//����ǰ��++�����,��������Ϊ��һֱ��һ�����ݽ��е�������
	MyInteger& operator++() {
		num++;
		return *this;
	}
	//���غ���++�����,һ��Ҫ���ص���ֵ
	//operator++(int) int����ռλ��������������ǰ�úͺ��õ���
	MyInteger operator++(int) {
		//�ȼ�¼��ǰ���
		MyInteger temp = *this;
		//�����
		num++;
		//��󽫼�¼���������
		return temp;
	}
private:
	int num;
};

//����<<�����
ostream& operator<<(ostream& cout, MyInteger myint) {
	cout << myint.num;
	return cout;
}
void test01() {
	MyInteger myint;
	cout << ++myint << endl;
	cout << ++(++myint) << endl;
}
void test02() {
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main() {
	//test01();
	test02();
}