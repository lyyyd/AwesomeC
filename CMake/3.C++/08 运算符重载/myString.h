#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//自定义字符串类
class MyString
{
    friend ostream& operator<<(ostream& cout, MyString& str);
    friend istream& operator>>(istream& cin, MyString& str);
public:

    //默认构造
    MyString();

    //有参构造
    MyString(const char* str);

    //拷贝构造
    MyString(const MyString& str);

    //析构函数
    ~MyString();

    //重载[]
    char& operator[](int pos);

    //重载=
    MyString& operator=(const char* str);
    MyString& operator=(const MyString & str);

    //重载+
    MyString operator+(const char* str);
    MyString operator+(const MyString& str);

    //字符串对比
    bool operator==(const char* str);
    bool operator==(const MyString& str);

private:
    char* pString; //指向堆区字符数组的指针
    int m_Size; //字符串长度
};
