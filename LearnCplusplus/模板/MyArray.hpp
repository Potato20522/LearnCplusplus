/**
* 自己的通用数组类
*/
#pragma once

#include <iostream>

using namespace std;

template<class T>
class MyArray {
public:
    explicit MyArray(int capacity) {
//        cout<<"MyArray的有参构造调用"<<endl;
        this->capacity = capacity;
        this->size = 0;
        this->address = new T[this->capacity];
    }

    //拷贝构造，防止浅拷贝
    MyArray(const MyArray& arr) {
//        cout<<"MyArray的拷贝构造调用"<<endl;
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->address = new T[arr.capacity];//这一步是深拷贝
        //将arr中的数据都可拷贝过来
        for (int i = 0; i < this->size; ++i) {
            this->address[i] = arr.address[i];
        }
    }

    //重载=,防止浅拷贝问题
    MyArray& operator=(const MyArray& arr) {
//        cout<<"MyArray的 operator= 调用"<<endl;
        //先判断原来堆区是否有数据，如果有先释放
        if (this->address != NULL) {
            delete[] this->address;
            this->address = NULL;
            this->capacity = 0;
            this->size = 0;
        }
        //深拷贝
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->address = new T[arr.capacity];
        for (int i = 0; i < this->size; ++i) {
            this->address[i] = arr.address[i];
        }
        return *this;
    }

    //尾插法
    void pushBack(const T& val) {
        //判断容量是否等于大小
        if (this->capacity == this->size) return;
        this->address[this->size] = val;//在数组末尾插入数据
        this->size++;//更新数组的大小
    }

    //尾删法
    void popBack() {
        //让用户访问不到最有一个元素，即为尾删，逻辑删除
        if (this->size == 0) return;
        this->size--;
    }

    //通过下标的方式访问数组中的元素
    T& operator[](int index) {
        //函数返回引用，这个函数调用可以作为左值
        return this->address[index];
    }

    //返回数组的容量
    int getCapacity() {
        return this->capacity;
    }

    //返回数组的大小
    int getSize() {
        return this->size;
    }

    ~MyArray() {
        if (this->capacity != NULL) {
            delete[] this->address;//释放数组占的内存
            this->address = NULL;//指针置为空，防止野指针
//            cout<<"MyArray的析构调用"<<endl;
        }
    }

private:
    T* address;//指针指向堆区开辟的数组
    int capacity{};//数组容量
    int size{};//数组大小
};