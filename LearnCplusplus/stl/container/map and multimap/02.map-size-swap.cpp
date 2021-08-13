#include <map>
#include <iostream>

using namespace std;

void printMap(map<int, int> &m) {
    for (auto & it : m) {
        cout << "key = " << it.first << " value = " << it.second << endl;
    }
    cout << endl;
}

void test01() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    if (m.empty()) {
        cout << "m为空" << endl;
    } else {
        cout << "m不为空" << endl;
        cout << "m的大小为： " << m.size() << endl;
    }
}


//交换
void test02() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    map<int, int> m2;
    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));

    cout << "交换前" << endl;
    printMap(m);
    printMap(m2);

    cout << "交换后" << endl;
    m.swap(m2);
    printMap(m);
    printMap(m2);
}

int main() {
    test01();
    test02();
    return 0;
}