#include<iostream>

using namespace std;

class Base {
public:
    //纯虚函数
    //类中只要有一个纯虚函数就称为抽象类
    //抽象类无法实例化对象
    //子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;

    virtual ~Base() = default;
};

class Son : public Base {
public:
    virtual void func() {
        cout << "func调用" << endl;
    };
};

void test01() {
    Base *base;
    //base = new Base; // 错误，抽象类无法实例化对象
    base = new Son;
    base->func();
    delete base;//记得销毁
}

int main() {
    test01();
    return 0;
}