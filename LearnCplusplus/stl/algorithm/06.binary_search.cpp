#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test01() {
    vector<int> v(10);

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //二分查找
    bool ret = binary_search(v.begin(), v.end(), 2);
    if (ret) {
        cout << "找到了" << endl;
    } else {
        cout << "未找到" << endl;
    }
}

int main() {
    test01();
    return 0;
}