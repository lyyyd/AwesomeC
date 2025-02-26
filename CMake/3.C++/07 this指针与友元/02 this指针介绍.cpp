#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//this指针
class Person
{
public:
	//this指针指向被调用成员函数所属对象
	Person(int age)
	{
		this->age = age;
	}
	int age;
};

void test01()
{
	Person p1(10);
	cout << "p1.age = " << p1.age << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}