#include <set>
#include <iostream>

using namespace std;

void printSet(set<int> &s) {
    for (int it : s) {
        cout << it << " ";
    }
    cout << endl;
}

//构造和赋值
void test01() {
    set<int> s1;
    //插入数据，只有insert
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    //拷贝构造
    set<int> s2(s1);
    printSet(s2);

    //赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);
}

int main() {
    test01();
    return 0;
}