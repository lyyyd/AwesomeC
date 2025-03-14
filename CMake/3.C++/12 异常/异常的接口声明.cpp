#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//throw() 代表不允许函数中抛出异常
void func()throw(int,double)
{
    throw 3.14;
}

int main()
{
    try
    {
        func();
    }
    catch(int)
    {
        cout << "int类型异常捕获"<< endl;
    }
    catch(...)
    {
        cout << "其他类型异常捕获"<< endl;
    }



    return 0;
}
