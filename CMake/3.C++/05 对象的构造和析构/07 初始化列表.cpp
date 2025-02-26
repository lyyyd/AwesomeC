#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//初始化列表
class Person
{
public:
	Person(int a,int b,int c): m_A(a), m_B(b),m_C(c)
	{
		//m_A = a;
		//m_B = b;
		//m_C = c;
	}

	int m_A;
	int m_B;
	int m_C;
};

void test01()
{
	Person p1(10, 20, 30);
	cout << p1.m_A << endl;
	cout << p1.m_B << endl;
	cout << p1.m_C << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}