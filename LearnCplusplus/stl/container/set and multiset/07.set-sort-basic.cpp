#include <set>
#include <iostream>

using namespace std;

class MyCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

void test01() {
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);

    //默认从小到大
    for (int it : s1) {
        cout << it << " ";
    }
    cout << endl;

    //指定排序规则
    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    s2.insert(50);

    for (int it : s2) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    test01();
    return 0;
}
