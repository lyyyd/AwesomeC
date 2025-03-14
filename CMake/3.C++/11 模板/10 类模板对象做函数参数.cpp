#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名：" << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};

//1、指定传入类型
void doWork(Person <string, int > & p)
{
	p.showPerson();
}

void test01()
{
	Person <string, int > p1("Tom", 10);
	doWork(p1);
}


//2、参数模板化
template<class T1, class T2>
void doWork2(Person <T1, T2>& p)
{
	p.showPerson();
	cout << "T1的类型：" << typeid(T1).name() << endl;
	cout << "T2的类型：" << typeid(T2).name() << endl;
}

void test02()
{
	Person <string, int > p2("Jerry", 20);
	doWork2(p2);
}

//3、整个类模板化
template<class T>
void doWork3( T & p)
{
	p.showPerson();
	cout << "T的类型：" << typeid(T).name() << endl;
}

void test03()
{
	Person <string, int > p3("Elvis", 30);
	doWork3(p3);
}

int main()
{

	test03();

	system("pause");
	return 0;
}