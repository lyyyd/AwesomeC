#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//Person类
class Person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}

	//获取年龄
	int getAge()
	{
		return m_Age;
	}

	//设置年龄 年龄必须在0~150之间，否则赋值失败
	void setAge(int age)
	{
		if (age < 0 || age > 150)
		{
			cout << "年龄范围有误，赋值失败" << endl;
			return;
		}
		m_Age = age;
	}

	//设置偶像
	void setIdol(string idol)
	{
		m_Idol = idol;
	}

private:
	//姓名  可读可写
	string m_Name;
	//年龄  只读
	int m_Age = 18;
	//偶像  只写
	string m_Idol;
};

//成员属性私有化优点：
//1、对于成员属性，可以自己控制读写权限
//2、对于写权限，可以验证数据的有效性
int main()
{
	Person p1;
	p1.setName("张三");
	cout << "姓名： " << p1.getName() << endl;

	//p1.setAge(28);
	//p1.m_Age = 28;
	p1.setAge(19);

	cout << "年龄： " << p1.getAge() << endl;

	p1.setIdol("李四");
	//cout << "偶像： " << p1.getIdol() << endl;

	system("pause");
	return 0;
}