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
    map<int, int> m; //默认构造
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    printMap(m);

    map<int, int> m2(m); //拷贝构造
    printMap(m2);

    map<int, int> m3;
    m3 = m2; //赋值
    printMap(m3);
}

int main() {
    test01();
    return 0;
}