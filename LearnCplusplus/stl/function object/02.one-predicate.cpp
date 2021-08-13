#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//返回bool类型的仿函数称为谓词
class GreaterFive {
public:
    bool operator()(int val) {
        return val > 5;
    }
};

void test01() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    //查找大于5的数字,GreaterFive():匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it==v.end()){
        cout << "没到了" << endl;
    }else{
        cout << "找到了大于5的数字为:" << *it << endl;
    }
}

int main() {
    test01();
    return 0;
}
