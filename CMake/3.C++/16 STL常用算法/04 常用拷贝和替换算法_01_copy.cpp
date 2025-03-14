#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	vector<int>v; //源容器
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v2; //目标容器
	v2.resize(v.size());

	copy(v.begin(), v.end(), v2.begin());

	//for_each(v2.begin(), v2.end(), [](int val) { cout << val << " "; });
	//cout << endl;

	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}