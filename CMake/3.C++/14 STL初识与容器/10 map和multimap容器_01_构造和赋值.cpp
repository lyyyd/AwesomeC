#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <map>

/*
构造
map<T1, T2> mp;		//map默认构造函数
map(const map &mp);	//拷贝构造函数
赋值
map& operator=(const map &mp);	//重载等号操作符
*/

int main()
{
	map<int, int> m;
	//插入数据
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(4, 50));
	m.insert(pair<int, int>(3, 30));

	map<int, int>m2(m);
	for (map<int, int>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
	cout << "-----------------" << endl;
	multimap<int, int>mm;
	mm.insert(pair<int, int>(1, 10));
	mm.insert(pair<int, int>(1, 20));
	mm.insert(pair<int, int>(1, 30));

	for (multimap<int, int>::iterator it = mm.begin(); it != mm.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}


	system("pause");
	return 0;
}