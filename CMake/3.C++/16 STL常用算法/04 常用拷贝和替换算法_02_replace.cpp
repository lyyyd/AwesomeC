#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>


int main()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	v.push_back(3);

	//替换： 将容器中所有3 替换成 30
	replace(v.begin(), v.end(), 3, 30);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}