#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//类模板基本语法
template<class NAMETYPE ,class AGETYPE>
class Person
{
public:
	Person(NAMETYPE name, AGETYPE age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	NAMETYPE m_Name;
	AGETYPE m_Age;
};

int main()
{
	//通过类模板实例化对象
	Person <string ,int >p1("张三", 18);
	p1.showPerson();

	system("pause");
	return 0;
}