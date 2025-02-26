#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
public:

    explicit MyString(const char* str)
    {}
    explicit MyString(int n)
    {
        m_Size = n;
    }
    char* m_Str;
    int m_Size;
};

void test01()
{
    //MyString str = "abcd";
    //MyString str2 = 10;
    MyString str3(10);
    MyString str4 = MyString(10);
}
int main()
{

    test01();

    system("pause");
    return 0;
}