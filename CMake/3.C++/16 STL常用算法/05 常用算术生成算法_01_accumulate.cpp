#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <numeric>

int main()
{
	//求 0 ~ 100 总和
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int sum = accumulate(v.begin(), v.end(), 1000);

	cout << "sum = " << sum << endl;

	system("pause");
	return 0;
}