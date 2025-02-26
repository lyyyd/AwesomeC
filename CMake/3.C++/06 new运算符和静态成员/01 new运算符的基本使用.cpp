#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//new和delete运算符
class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int a)
	{
		cout << "Person的有参构造函数调用" << endl;
	}
	Person(const Person & p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
};
void test01()
{
	Person* p1 = new Person;
	Person* p2 = new Person(10);
	Person* p3 = new Person(*p1);
	delete p1;
	delete p2;
	delete p3;
	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
}

int main()
{
	test01();


	system("pause");
	return 0;
}