#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	//pair创建
	//第一个方式
	pair<string, int>p1("tom", 18);
	cout << "姓名： " << p1.first << " 年龄： " << p1.second << endl;

	//第二个方式
	pair<string,int> p2 = make_pair("Jerry", 20);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;

	system("pause");
	return 0;
}