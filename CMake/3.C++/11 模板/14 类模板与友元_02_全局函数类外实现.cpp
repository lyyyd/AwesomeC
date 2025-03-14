#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//让编译器提前看到Person类声明
template<class T1, class T2> class Person;

//让编译器提前看到全局函数声明
template<class T1,class T2> void showPerson(Person<T1, T2>& p);

template<class T1, class T2>
void showPerson2(Person<T1, T2>& p)
{
	cout << "全局函数类外实现2 姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	friend void showPerson<>(Person<T1, T2>& p);  //函数是普通函数 还是函数模板？
	friend void showPerson2<>(Person<T1, T2>& p);
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

template<class T1,class T2>
void showPerson(Person<T1, T2>& p)
{
	cout << "全局函数类外实现 姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

int main()
{
	Person <string, int > p("Jerry", 18);
	showPerson(p);
	showPerson2(p);

	system("pause");
	return 0;
}