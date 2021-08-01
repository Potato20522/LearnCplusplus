#include<iostream>

using namespace std;

//实现通用的对数组进行排序的函数，从大到小，选择排序，char、int数组

template<class T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void printArray(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

template<class T>
void mySort(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        if (max != i) {
            mySwap(arr[max], arr[i]);
        }
    }
}

void test01() {
    //char
    char charArr[] = "badcfe";
    mySort(charArr, sizeof(charArr) / sizeof(char));
    printArray(charArr,sizeof(charArr) / sizeof(char));
}
void test02() {
    //int
    int intArr[] = {7,5,1,3,9,2,4,6,8};
    mySort(intArr, sizeof(intArr) / sizeof(int));
    printArray(intArr,sizeof(intArr) / sizeof(int));
}

int main() {
    test01();
    test02();
    return 0;
}