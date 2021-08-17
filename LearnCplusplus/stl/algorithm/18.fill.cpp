#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class myPrint {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {

    vector<int> v;
    v.resize(10);
    //填充
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}

int main() {
    test01();
    return 0;
}