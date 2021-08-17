#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void test01() {
    vector<int> v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    v.push_back(20);

    for (int & it : v) {
        cout << it << " ";
    }
    cout << endl;

    //自己实现仿函数
    //sort(v.begin(), v.end(), MyCompare());
    //STL内建仿函数  大于仿函数
    sort(v.begin(), v.end(), greater<int>());

    for (int & it : v) {
        cout << it << " ";
    }
    cout << endl;
}


int main() {
    test01();
    return 0;
}
