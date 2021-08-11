#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v) {
    for (int& it : v) {
        cout << it << " ";
    }
    cout << endl;
}

void test01() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    //赋值 1.operator=
    vector<int> v2;
    v2 = v1;
    printVector(v2);

    //2.assign
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());//左闭右开
    printVector(v3);

    //3.n个elem方式赋值
    vector<int>v4;
    v4.assign(10, 100);
    printVector(v4);
}

int main() {
    test01();
    return 0;
}
