#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "myString.h"

void test01()
{
    MyString str;
    MyString str2("abc");
    MyString str3(str2);

    cout << str << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    cin >> str3 >> str2;
    cout << str2 << endl;
    cout << str3 << endl;
}

void test02()
{
    MyString str1 = "abc";
    cout << str1[0] << endl;
    str1[0] = 'x';
    cout << str1 << endl;

    MyString str2;
    str2 = str1;
    cout << str2 << endl;

    MyString str3 = "abc";
    MyString str4 = "def";
    MyString str5 = str3 + "def";
    cout << str5 << endl;

    MyString str6 = "abcde";
    if (str5 == str6)
    {
        cout << "str5 == str6" << endl;
    }
    else
    {
        cout << "str5 != str6" << endl;
    }
}

int main()
{

    test02();




    system("pause");
    return 0;
}