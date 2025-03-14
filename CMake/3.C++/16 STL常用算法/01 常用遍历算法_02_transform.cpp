#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

class myTransform
{
public:
	int operator()(int val)
	{
		return val * 10;
	}
};

int main()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//目标容器
	vector<int>v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), myTransform());

	//lambda表达式 匿名函数 [](){}
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << endl; });

	system("pause");
	return 0;
}