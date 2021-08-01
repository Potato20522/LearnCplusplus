#include <iostream>
#include "MyArray.hpp"

using namespace std;

void printIntArray(MyArray<int>& arr) {
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << endl;
    }
}

void test01() {
    MyArray<int> arr1(5);
    for (int i = 0; i < 5; ++i) {
        arr1.pushBack(i);
    }
    cout << "arr1的打印输出为:" << endl;
    printIntArray(arr1);
    cout << "arr1的容量为:" << arr1.getCapacity() << endl;
    cout << "arr1的大小为:" << arr1.getSize() << endl;

    MyArray<int> arr2(arr1);
    arr2.popBack();
    cout << "arr2尾删后" << endl;
    cout << "arr2的容量为:" << arr2.getCapacity() << endl;
    cout << "arr2的大小为:" << arr2.getSize() << endl;

}

//测试自定义数据类型
class Person {
public:
    Person() {}

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

public:
    string name;
    int age;
};

void printPersonArray(MyArray<Person>& personArr) {
    for (int i = 0; i < personArr.getSize(); i++) {
        cout << "姓名：" << personArr[i].name << " 年龄： " << personArr[i].age << endl;
    }

}

void test02() {
    //创建数组
    MyArray<Person> pArray(10);
    Person p1("孙悟空", 30);
    Person p2("韩信", 20);
    Person p3("妲己", 18);
    Person p4("王昭君", 15);
    Person p5("赵云", 24);

    //插入数据
    pArray.pushBack(p1);
    pArray.pushBack(p2);
    pArray.pushBack(p3);
    pArray.pushBack(p4);
    pArray.pushBack(p5);

    printPersonArray(pArray);

    cout << "pArray的大小：" << pArray.getSize() << endl;
    cout << "pArray的容量：" << pArray.getCapacity() << endl;

}
int main() {
    test01();
    cout<<"----------------"<<endl;
    test02();
    return 0;
}