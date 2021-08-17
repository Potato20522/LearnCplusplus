#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class myPrint {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {
    srand((unsigned int) time(nullptr));
    vector<int> v;
    v.reserve(10);
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;

    //打乱顺序
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}

int main() {
    test01();
    return 0;
}