#include <set>
#include <iostream>

using namespace std;

void printSet(set<int> &s) {
    for (int it : s) {
        cout << it << " ";
    }
    cout << endl;
}

//set和multiset区别
void test01() {
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second) {
        cout << "第一次插入成功!" << endl;
    } else {
        cout << "第一次插入失败!" << endl;
    }

    ret = s.insert(10);
    if (ret.second) {
        cout << "第二次插入成功!" << endl;
    } else {
        cout << "第二次插入失败!" << endl;
    }

    //multiset
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);

    for (int m : ms) {
        cout << m << " ";
    }
    cout << endl;
}

int main() {
    test01();
    return 0;
}