#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>

int main()
{
	srand((unsigned int)time(NULL));

	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//洗牌
	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
	cout << endl;

	system("pause");
	return 0;
}