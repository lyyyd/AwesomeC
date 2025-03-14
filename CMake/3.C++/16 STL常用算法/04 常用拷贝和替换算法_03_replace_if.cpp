#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

class myReplace
{
public:
	bool operator()(int val)
	{
		return val > 3;
	}
};

int main()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//将所有比3大的元素，都替换成3000
	// 0 1 2 3 3000 3000 3000 3000 3000 3000

	replace_if(v.begin(), v.end(), myReplace(), 3000);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	system("pause");
	return 0;
}