#include<iostream>

using namespace std;

//模板不是万能的，有些特定数据类型，需要用具体化方式做特殊实现
//对比两个数据是否相等的函数
template<class T>
bool myCompare(T& a, T& b) {
    return a == b;
}

class Person {
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

//具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
template<> bool myCompare(Person& p1, Person& p2) {
    return p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age;
}

void test01() {
    int a = 10, b = 20;
    bool ret = myCompare(a, b);
    if (ret) {
        cout << "a == b " << endl;
    } else {
        cout << "a != b " << endl;
    }
}

void test02() {
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    //自定义数据类型，不会调用普通的函数模板
    //可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
    bool ret = myCompare(p1, p2);
    if (ret) {
        cout << "p1 == p2 " << endl;
    } else {
        cout << "p1 != p2 " << endl;
    }
}

int main() {
    test01();
    test02();
    return 0;
}