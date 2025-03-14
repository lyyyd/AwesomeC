#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "myArray.hpp"

void test01()
{
    MyArray<int> intArray(10);

    for (int i = 0; i < intArray.getCapacity(); i++)
    {
        intArray.push_back(i + 100);
    }

    //遍历数组
    for (int i = 0; i < intArray.getSize(); i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    MyArray<int>arr2 = intArray;
    arr2.pop_back();
    for (int i = 0; i < arr2.getSize(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    MyArray<int>arr3(10);
    arr3 = arr2;
    arr3.pop_back();
    for (int i = 0; i < arr3.getSize(); i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}

class Person
{
public:
    Person() {}
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void test02()
{
    MyArray<Person> pArr(10);
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    pArr.push_back(p1);
    pArr.push_back(p2);
    pArr.push_back(p3);
    pArr.push_back(p4);
    pArr.push_back(p5);

    //遍历数组
    for (int i = 0; i < pArr.getSize(); i++)
    {
        cout << "姓名： " << pArr[i].m_Name << " 年龄： " << pArr[i].m_Age << endl;
    }

    cout << "容量： " << pArr.getCapacity() << endl;
    cout << "大小： " << pArr.getSize() << endl;

    pArr.pop_back();
    cout << "大小： " << pArr.getSize() << endl;

}

int main()
{

    test02();

    system("pause");
    return 0;
}