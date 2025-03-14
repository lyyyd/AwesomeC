#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
	vector<int>v;
	v.resize(3, 10);

	fill(v.begin(), v.end(), 20);

	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;

	system("pause");
	return 0;
}