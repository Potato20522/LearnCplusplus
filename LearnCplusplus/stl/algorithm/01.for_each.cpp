#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//普通函数
void print01(int val) {
    cout << val << " ";
}

//函数对象
class print02 {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {
    vector<int> v;
    v.reserve(10);
for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print01);
    cout << endl;

    for_each(v.begin(), v.end(), print02());
    cout << endl;
}

int main() {
    test01();
    return 0;
}