#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyInter
{
	friend ostream& operator<<(ostream& cout, MyInter& myInt);
public:
	MyInter()
	{
		this->m_Num = 0;
	}
	//重载++运算符
	//前置重载
	MyInter& operator++()
	{
		this->m_Num++;
		return *this;
	}
	//后置重载
	int operator++(int)
	{
		int temp = this->m_Num;
		this->m_Num++;
		return temp;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, MyInter& myInt)
{
	cout << myInt.m_Num;
	return cout;
}

void test01()
{
	MyInter myInt;
	cout << myInt++ << endl;
	cout << myInt << endl;
}

int main()
{
	test01();

	//int a = 0;
	//cout << (a++)++ << endl;

	system("pause");
	return 0;
}