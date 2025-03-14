#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1的show函数调用" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2的show函数调用" << endl;
	}
};

template<class T>
class MyClass
{
public:
	//类模板中的成员函数，一开始不会被创建，只有被调用的时候，才去创建
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}

	T obj;
};

int main()
{
	MyClass<Person2> mc;
	//mc.func1();
	mc.func2();

	system("pause");
	return 0;
}