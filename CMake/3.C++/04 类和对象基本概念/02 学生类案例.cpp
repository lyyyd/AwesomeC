#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//设计学生类，属性姓名 学号，可以设置获取姓名、学号，展示学生信息
//学生类设计
class Student
{

//类内部 所有内容称为 成员
//类中所有属性 成员属性 成员变量
//类中所有函数 成员函数 成员方法

//公共权限
public:

	//行为
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

	//设置学号
	void setId(int id)
	{
		m_Id = id;
	}

	//获取学号
	int getId()
	{
		return m_Id;
	}

	//展示整体信息
	void showInfo()
	{
		cout << "姓名： " << m_Name << " 学号： " << m_Id << endl;
	}

	//属性
	//姓名
	string m_Name;
	//id号
	int m_Id;
};

int main()
{
	//通过类创建具体对象  实例化对象
	Student s1;
	s1.setName("张三");
	s1.setId(1);
	cout << "姓名： " << s1.getName() << " 学号： " << s1.getId() << endl;
	s1.showInfo(); //展示整体信息

	//实例化第二个对象
	Student s2;
	s2.setName("李四");
	s2.setId(2);
	s2.showInfo();

	system("pause");
	return 0;
}