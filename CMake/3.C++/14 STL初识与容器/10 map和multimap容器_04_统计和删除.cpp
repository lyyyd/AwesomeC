#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <map>
/*
统计
count(key);		//统计key的元素个数
查找
find(key);	//查找key是否存在,若存在返回该键的元素的迭代器，若不存在，返回迭代器end()位置;
lower_bound(keyElem);	//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);	//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);	//返回容器中key与keyElem相等的上下限的两个迭代器
*/

void test01()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));

	cout << "key为3的元素个数为： " << m.count(3) << endl;
}

void test02()
{
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));

	map<int,int>::iterator ret =  m.find(1);

	if (ret != m.end())
	{
		cout << "找到了元素，key = " << ret->first << " value = " << ret->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//lower_bound(keyElem);	//返回第一个key>=keyElem元素的迭代器。
	ret = m.lower_bound(3);
	if (ret != m.end())
	{
		cout << "找到了lower_bound(3)的结果，key = " << ret->first << " value = " << ret->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	//upper_bound(keyElem);	//返回第一个key>keyElem元素的迭代器。
	ret = m.upper_bound(3);
	if (ret != m.end())
	{
		cout << "找到了upper_bound(3)的结果，key = " << ret->first << " value = " << ret->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	//equal_range(keyElem);	//返回容器中key与keyElem相等的上下限的两个迭代器
	pair< map<int,int>::iterator,map<int,int>::iterator > p =  m.equal_range(3);
	if (p.first != m.end())
	{
		cout << "在equal_range中，找到了lower_bound(3)的结果，key = " << p.first->first << " value = " << p.first->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	if (p.second != m.end())
	{
		cout << "在equal_range中，找到了upper_bound(3)的结果，key = " << p.second->first << " value = " << p.second->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

int main()
{
	test02();


	system("pause");
	return 0;
}