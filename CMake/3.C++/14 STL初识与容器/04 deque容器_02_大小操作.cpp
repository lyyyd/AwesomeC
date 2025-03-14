#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <deque>

/*
empty();			//判断容器是否为空
size();			//返回容器中元素的个数
resize(int num);		//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
					//如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);  	//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
					//如果容器变短，则末尾超出容器长度的元素被删除
*/

void test01()
{
	deque<int>d;
	d.push_back(10);
	if (d.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空,大小：" << d.size() << endl;
	}

	d.resize(10,1000);
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	d.resize(3);
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();


	system("pause");
	return 0;
}