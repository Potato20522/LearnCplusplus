#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

void printDeque(const deque<int>& d) {
    for (int it : d) {
        cout << it << " ";
    }
    cout << endl;
}

void test01() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    printDeque(d);
    sort(d.begin(), d.end());
    printDeque(d);
}

int main() {
    test01();
    return 0;
}