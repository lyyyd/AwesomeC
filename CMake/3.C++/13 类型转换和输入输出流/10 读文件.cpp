#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <fstream>
#include <string>

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

//read方式读文件
void test01()
{
    ifstream ifs;
    ifs.open("./test01.txt", ios::in );
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    Person p;
    ifs.read((char*)&p, sizeof(p));

    cout << "姓名： " << p.m_Name << endl;
    cout << "年龄： " << p.m_Age << endl;

    ifs.close();

}

void test02()
{
    ifstream ifs;
    ifs.open("./test02.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    char buf[1024] = "";
    while (ifs >> buf)
    {
        cout << buf << endl;
    }

    ifs.close();
}

void test03()
{
    ifstream ifs;
    ifs.open("./test02.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    char buf[1024] = "";
    while (ifs.getline(buf, sizeof(buf)))
    {
        cout << buf << endl;
    }
    ifs.close();
}

void test04()
{
    ifstream ifs;
    ifs.open("./test02.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    string buf;
    while (getline(ifs, buf))
    {
        cout << buf << endl;
    }

}

void test05()
{
    ifstream ifs;
    ifs.open("./test02.txt", ios::in);

    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }

    ifs.close();
}

int main()
{
    test05();


    system("pause");
    return 0;
}