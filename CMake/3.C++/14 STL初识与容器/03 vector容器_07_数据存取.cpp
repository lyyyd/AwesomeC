#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>

/*  数据存取
at(int idx);		//返回索引idx所指的数据
operator[];		//返回索引idx所指的数据
front();		//返回容器中第一个数据元素
back();		//返回容器中最后一个数据元素
*/

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i] << " ";
		cout << v.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素为： " << v.front() << endl;
	cout << "最后一个元素为： " << v.back() << endl;


	try
	{
		//cout << v[1000] << endl;
		cout << v.at(1000) << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

int main()
{
	test01();


	system("pause");
	return 0;
}