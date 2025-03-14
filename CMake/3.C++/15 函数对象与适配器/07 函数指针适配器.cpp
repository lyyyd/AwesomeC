#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

void myPrint(int val , int start)
{
	cout << val + start << endl;
}

int main()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始累加数字： " << endl;
	int start;
	cin >> start;
	//将函数指针 适配成 函数对象，利用ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint), start) ) ;


	system("pause");
	return 0;
}