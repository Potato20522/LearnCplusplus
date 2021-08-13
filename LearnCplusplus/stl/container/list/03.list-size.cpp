#include <list>
#include <iostream>

using namespace std;

void printList(const list<int> &L) {
    for (int it : L) {
        cout << it << " ";
    }
    cout << endl;
}

//大小操作
void test01() {
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    if (L1.empty()) {
        cout << "L1为空" << endl;
    } else {
        cout << "L1不为空" << endl;
        cout << "L1的大小为： " << L1.size() << endl;
    }

    //重新指定大小
    L1.resize(10);
    printList(L1);

    L1.resize(2);
    printList(L1);
}

int main() {
    test01();
    return 0;
}