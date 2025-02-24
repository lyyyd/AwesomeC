#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、C下必须用高级指针修饰实参中的低级空指针
struct Person
{
	int age; //年龄
};
void allocateMemory(Person ** p)
{
	*p = (Person *)malloc(sizeof(Person));
	(*p)->age = 100;
}
void test01()
{
	Person* p = NULL;
	allocateMemory(&p);
	cout << "p的age = " << p->age << endl;
}

//指针的引用
void allocateMemory2(Person*& p)
{
	p =(Person *) malloc(sizeof(Person));
	p->age = 200;
}

void test02()
{
	Person* p = NULL;
	allocateMemory2(p);
	cout << "p的age = " << p->age << endl;
}

int main()
{
	test02();


	system("pause");
	return 0;
}