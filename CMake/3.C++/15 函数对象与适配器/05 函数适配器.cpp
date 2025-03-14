#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class MyPrint :public binary_function<int,int ,void >
{
public:
	void operator()(int val , int start) const
	{
		cout << "val = " << val << " start = " << start << " sum = " <<   val + start << endl;
	}
};

//1、绑定 bind2nd
//2、继承 binary_function <参数类型1，参数类型2，返回值类型>
//3、加const 让operator()变为常函数

int main()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	cout << "请输入起始值： " << endl;
	int start = 0;
	cin >> start;

	for_each(v.begin(), v.end(), bind1st( MyPrint() , start) );
	//for_each(v.begin(), v.end(), bind2nd(MyPrint(), start));


	system("pause");
	return 0;
}