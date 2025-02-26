#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}

	Person& personAddAge(Person & p)
	{
		this->age += p.age;
		//*this指向的是对象本体
		return *this;
	}

	int age;
};

void test01()
{
	Person p1(10);
	Person p2(10);
	//链式编程思想
	p2.personAddAge(p1).personAddAge(p1).personAddAge(p1);

	cout << "p2.age = " << p2.age << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}