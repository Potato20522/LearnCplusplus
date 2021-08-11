#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v) {
    for (int& it : v) {
        cout << it << " ";
    }
    cout << endl;
}
void test01() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v1.size(); i++) {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << "v1的第一个元素为： " << v1.front() << endl;
    cout << "v1的最后一个元素为： " << v1.back() << endl;
}


int main() {
    test01();
    return 0;
}
