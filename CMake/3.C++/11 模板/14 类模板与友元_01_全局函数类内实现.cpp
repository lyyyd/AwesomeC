#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T1 ,class T2>
class Person
{
	friend void showPerson(Person<T1, T2>& p)
	{
		cout << "全局函数类内实现 姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
	}

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

int main()
{
	Person <string, int > p("Jerry", 18);
	showPerson(p);


	system("pause");
	return 0;
}