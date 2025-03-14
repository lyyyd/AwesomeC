#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	//二分查找 必须是有序容器
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//v.push_back(3);

	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	system("pause");
	return 0;
}