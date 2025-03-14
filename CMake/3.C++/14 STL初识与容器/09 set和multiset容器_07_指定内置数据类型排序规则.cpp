#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <set>

class myCompare
{
public:
	bool operator()(int v1,int v2) const
	{
		return v1 > v2;
	}
};

int main()
{
	set<int, myCompare> s;
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(50);

	for (set<int, myCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}