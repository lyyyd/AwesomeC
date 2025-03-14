#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <fstream>

//写文件
//通过成员函数write
class Person
{
public:
	char m_Name[64];
	int m_Age;
};
void test01()
{
	Person p;
	strcpy(p.m_Name, "Tom");
	p.m_Age = 30;
	//创建输出文件流对象
	ofstream ofs;

	//打开文件
	ofs.open("./test01.txt", ios::out);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//写文件
	ofs.write((const char*)&p, sizeof(p));

	//关闭文件
	ofs.close();
}

//利用<<写文件
void test02()
{
	ofstream ofs;
	ofs.open("./test02.txt", ios::out);
	if (ofs.is_open() == false)
	{
		cout << "文件打开失败" << endl;
		return;
	}

	ofs << "姓名：Tom" << endl;
	ofs << "年龄：18" << endl;
	ofs << "性别：男" << endl;

	ofs.close();
}

int main()
{

	test01();

	system("pause");
	return 0;
}