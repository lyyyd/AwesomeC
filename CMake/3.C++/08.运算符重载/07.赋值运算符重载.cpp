#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//编译器会默认给每个类添加4个函数
//默认构造 空实现
//析构函数 空实现
//拷贝构造 值拷贝
//operator=  值拷贝
class Person
{
public:
	Person(const char* name, int age)
	{
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
		this->m_Age = age;
	}

	Person(const Person& p)
	{
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
	}

	//重载operator=
	Person & operator=(const Person& p)
	{
		this->m_Age = p.m_Age;
		//this->m_Name = p.m_Name;
		//先判断原来是否有堆区的数据，如果有先释放
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		return *this;
	}

	~Person()
	{
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}

	char* m_Name;
	int m_Age;
};

void test01()
{
	Person p1("Tom", 10);
	Person p2("Jerry", 20);
	p1 = p2;
	cout << "p1姓名：" << p1.m_Name << " 年龄： " << p1.m_Age << endl;
	cout << "p2姓名：" << p2.m_Name << " 年龄： " << p2.m_Age << endl;

}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Jerry", 20);
	Person p3("Elvis", 30);
	p3 = p1 = p2;
	cout << "p1姓名：" << p1.m_Name << " 年龄： " << p1.m_Age << endl;
	cout << "p2姓名：" << p2.m_Name << " 年龄： " << p2.m_Age << endl;
	cout << "p3姓名：" << p3.m_Name << " 年龄： " << p3.m_Age << endl;

	Person p4(p3);
	cout << "p4姓名：" << p4.m_Name << " 年龄： " << p4.m_Age << endl;
}

int main()
{
	test02();

	//int a = 10;
	//int b = 20;
	//int c = 30;
	//c = a = b;
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;

	system("pause");
	return 0;
}