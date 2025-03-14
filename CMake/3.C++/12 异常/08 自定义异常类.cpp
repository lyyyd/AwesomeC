#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <stdexcept>

//自定义异常类
class MyOutOfRange : public exception
{
public:

    MyOutOfRange(const char* errorInfo)
    {
        //const char * 转 string
        this->m_ErrorInfo = string(errorInfo);
    }

    MyOutOfRange(const string& errorInfo)
    {
        this->m_ErrorInfo = errorInfo;
    }

    //通过what返回错误提示信息
    virtual char const* what() const
    {
        //const char * 转换 string  利用 .c_str()
        return this->m_ErrorInfo.c_str();
    }

    //记录错误提示信息
    string m_ErrorInfo;
};

class Person
{
public:
    Person(int age)
    {
        if (age < 0 || age > 150)
        {
            throw MyOutOfRange("我自己的异常，年龄必须在0~150之间");
        }
        this->m_Age = age;
    }
    int m_Age;
};

int main()
{
    try
    {
        Person p(1000);
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }


    system("pause");
    return 0;
}