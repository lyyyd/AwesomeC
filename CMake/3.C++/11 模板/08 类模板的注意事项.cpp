#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//类模板中模板参数列表可以有默认参数
template<class NAMETYPE = string, class AGETYPE = int>
class Person
{
public:
	Person(NAMETYPE name, AGETYPE age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	NAMETYPE m_Name;
	AGETYPE m_Age;
};

int main()
{
	Person <>p1("张三", 20);
	cout << p1.m_Name << " " << p1.m_Age << endl;

	//类模板 没有自动类型推导的，只能用显示指定类型
	//Person p2("李四", 30);

	system("pause");
	return 0;
}