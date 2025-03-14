#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <set>
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
	set<int>s;
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(50);
	//对于set而言，count的统计结果，要么是0，要么是1
	cout << "key 为 50的元素个数为： " << s.count(50) << endl;;

}

void test02()
{
	set<int>s;
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(50);

	set<int>::iterator it =  s.find(30);

	if (it != s.end())
	{
		cout << "找到了元素：" << *it << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//lower_bound(keyElem);	//返回第一个key>=keyElem元素的迭代器
	it = s.lower_bound(30);
	if (it != s.end())
	{
		cout << "找到了lower_bound(30)元素：" << *it << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//upper_bound(keyElem);	//返回第一个key>keyElem元素的迭代器。
	it = s.upper_bound(30);
	if (it != s.end())
	{
		cout << "找到了upper_bound(30)元素：" << *it << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//equal_range(keyElem);	//返回容器中key与keyElem相等的上下限的两个迭代器
	pair< set<int>::iterator, set<int>::iterator > p = s.equal_range(30);
	if (p.first != s.end())
	{
		cout << "找到了equal_range中的lower_bound(30)的元素为：" << *(p.first) << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
	if (p.second != s.end())
	{
		cout << "找到了equal_range中的upper_bound(30)的元素为：" << *(p.second) << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

}

int main()
{
	test02();


	system("pause");
	return 0;
}