#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//Person类创建
class Person
{
public:
	Person(const char* name, int age)
	{
		cout << "有参构造函数调用" << endl;
		m_Name = (char *)malloc(strlen(name) + 1);
		strcpy(m_Name, name);
		m_Age = age;
	}

	Person(const Person& p)
	{
		cout << "拷贝构造函数调用" << endl;
		m_Name = (char *)malloc(strlen(p.m_Name) + 1);
		strcpy(m_Name, p.m_Name);
		m_Age = p.m_Age;
	}

	~Person()
	{
		if (m_Name != NULL)
		{
			cout << "析构函数调用" << endl;
			free(m_Name);
			m_Name = NULL;
		}
	}

	char* m_Name; //姓名
	int m_Age; //年龄
};

void test01()
{
	Person p1("张三", 10);
	Person p2(p1);

	cout << "姓名： " << p1.m_Name << " 年龄： " << p1.m_Age << endl;
	cout << "姓名： " << p2.m_Name << " 年龄： " << p2.m_Age << endl;
}

int main()
{
	test01();


	system("pause");
	return 0;
}