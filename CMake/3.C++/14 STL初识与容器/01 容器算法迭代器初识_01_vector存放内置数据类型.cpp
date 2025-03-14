#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void myPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v;// 创建vector容器对象

	//向容器中添加数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//通过迭代器遍历容器
	vector<int>::iterator itBegin =  v.begin(); //起始迭代器 ， 指向容器中第一个元素的位置
	vector<int>::iterator itEnd = v.end(); //结束迭代器，指向容器中最后一个元素的下一个位置
	//第一种遍历方式
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//第二种方式
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	//第三种方式  for_each 内置算法
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main()
{

	test01();

	system("pause");
	return 0;
}