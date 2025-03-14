#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	cout << "反转前遍历结果为： " << endl;
	for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
	cout << endl;  // 10 30 20 50 40

	reverse(++v.begin(), v.end());
	cout << "反转后遍历结果为： " << endl;
	for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
	cout << endl;  // 10 40 50 20 30

	system("pause");
	return 0;
}