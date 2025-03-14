#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class GreaterFive : public unary_function<int,bool>
{
public:
	bool operator()(int val) const
	{
		return val > 5;
	}
};

//一元取反适配器
//1、not1取反
//2、继承 unary_function<参数类型，返回值类型>
//3、加const变为常函数
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( GreaterFive()));
	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(  bind2nd( greater<int>(), 5)));

	if (pos != v.end())
	{
		cout << "找到小于5的数字为： " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

void myPrint(int val)
{
	cout << val << endl;
}

void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	sort(v.begin(), v.end(), not2( less<int>()));
	for_each(v.begin(), v.end(), myPrint);

}

int main()
{
	test02();


	system("pause");
	return 0;
}