#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v) {
    for (int& it : v) {
        cout << it << " ";
    }
    cout << endl;
}

//1.基本使用
void test01() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--) {
        v2.push_back(i);
    }
    printVector(v2);

    //互换容器
    cout << "互换后" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

//2.实际用途：可以收缩内存空间
void test02() {
    vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }

    cout << "v的容量为：" << v.capacity() << endl;//131072
    cout << "v的大小为：" << v.size() << endl;//100000

    v.resize(3);

    cout << "v的容量为：" << v.capacity() << endl;//131072
    cout << "v的大小为：" << v.size() << endl;//3

    //收缩内存
    vector<int>(v).swap(v); //匿名对象 vector<int>(v)，初始化的容量是v的大小，即：3
    //匿名对象执行完成后，会自动执行析构进行回收

    cout << "v的容量为：" << v.capacity() << endl;//3
    cout << "v的大小为：" << v.size() << endl;//3
}

int main() {
    test01();
    test02();
    return 0;
}
