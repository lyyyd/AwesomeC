#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout << "姓名： " << m_Name << " 年龄： " << m_Age << endl;
    }
    void addAge()
    {
        this->m_Age++;
    }
private:
    string m_Name;
    int m_Age;
};

//void showPerson(Person & p)
//{
//	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
//}

int main()
{
    vector<Person>v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //for_each(v.begin(), v.end(), showPerson);
    // mem_fun_ref 将成员函数入口地址，适配成全局函数
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson ));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));

    //如果容器中存储的是对象的指针类型，需要利用mem_fun适配器

    system("pause");
    return 0;
}