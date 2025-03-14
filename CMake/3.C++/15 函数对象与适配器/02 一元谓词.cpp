#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>

//谓词 ：仿函数 或 普通函数 返回值类型 是bool
//一元谓词： 参数个数为1个
//在容器中 找到第一个大于5数字的迭代器

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());
	if (pos != v.end())
	{
		cout << "找到大于5的元素： " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}


int main()
{

	test01();

	system("pause");
	return 0;
}