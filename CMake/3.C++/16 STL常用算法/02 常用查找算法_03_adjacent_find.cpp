#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos != v.end())
	{
		cout << "找到相邻重复的元素： " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	system("pause");
	return 0;
}