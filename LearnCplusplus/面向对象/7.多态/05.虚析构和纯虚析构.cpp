#include <iostream>

using namespace std;

//虚析构和纯虚析构
class Animal {
public:
    Animal() {
        cout << "Animal 构造函数调用！" << endl;
    }

    //析构函数加上virtual关键字，变成虚析构函数
    //利用虚析构可以解决，父类指针释放子类对象时不干净的问题
    /*virtual ~Animal() {
        cout << "Animal虚析构函数调用！" << endl;
    }*/

    //纯虚析构，需要声明，也需要实现
    //有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;
    //纯虚函数
    virtual void speak() = 0;
};

Animal::~Animal() {
    cout << "Animal纯析构函数调用！" << endl;
}

class Cat : public Animal {
public:
    Cat(string name) {
        cout << "Cat构造函数调用！" << endl;
        m_Name = new string(name);
    }

    virtual void speak() {
        cout << *m_Name << "小猫在说话" << endl;
    }

    virtual ~Cat() {
        if (m_Name != nullptr) {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = nullptr;
        }
    }

    string *m_Name;
};

void test01() {
    Animal *animal = new Cat("Tom");
    animal->speak();
    //父类的指针在析构时，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露
    delete animal;
}

int main() {
    test01();
    return 0;
}