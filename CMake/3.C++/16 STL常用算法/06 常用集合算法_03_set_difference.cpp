#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget; //目标容器
	vTarget.resize(max(v1.size(), v2.size()));

	cout << "v1与v2的差集:" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	copy(vTarget.begin(), itEnd , ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "v2与v1的差集:" << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}