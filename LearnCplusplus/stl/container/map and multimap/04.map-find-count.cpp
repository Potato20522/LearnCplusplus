#include <map>
#include <iostream>

using namespace std;

void printMap(map<int, int> &m) {
    for (auto &it : m) {
        cout << "key = " << it.first << " value = " << it.second << endl;
    }
    cout << endl;
}

//查找和统计
void test01() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    //查找
    map<int, int>::iterator pos = m.find(3);

    if (pos != m.end()) {
        cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
    } else {
        cout << "未找到元素" << endl;
    }

    //统计
    int num = m.count(3);
    cout << "num = " << num << endl;
}

int main() {
    test01();
    return 0;
}