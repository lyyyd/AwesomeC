#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <map>
/*
插入
insert(pair);			//在容器中插入元素
operator[];             //利用[]插入元素

删除
clear();		//清除所有元素
erase(pos);		//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);	//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(key);		//删除容器中值为key的元素。
*/

int main()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;

	m.erase(3); //按照key删除
	m.clear();

	cout << m[5] << endl;

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}



	system("pause");
	return 0;
}