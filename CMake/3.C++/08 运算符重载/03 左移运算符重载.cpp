#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//成员函数无法实现 cout << p1
	//void operator<<(ostream& cout)
	//{
	//}

private:
	int m_A;
	int m_B;
};

//利用全局函数重载左移运算符
ostream& operator<<(ostream& cout, Person& p)
{
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B ;
	return cout;
}

void test01()
{
	Person p1(10, 20);
	cout << p1 << endl;

}

int main()
{

	test01();

	system("pause");
	return 0;
}