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
    vector<int> v;

    //预留空间
    v.reserve(100000);//不写这个num是18

    int num = 0; //统计开辟次数
    int* p = nullptr;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }

    cout << "num:" << num << endl;//1
}

int main() {
    test01();
    return 0;
}
