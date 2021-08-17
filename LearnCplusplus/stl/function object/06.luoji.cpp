#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void test01() {
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    //逻辑非  将v容器搬运到v2中，并执行逻辑非运算
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for (auto it : v2) {
        cout << it << " ";
    }
    cout << endl;
}


int main() {
    test01();
    return 0;
}
