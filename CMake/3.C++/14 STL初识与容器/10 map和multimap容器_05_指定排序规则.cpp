#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <map>

class myCompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

int main()
{
	map<int, int, myCompare> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));

	for (map<int, int, myCompare>::iterator it = m.begin(); it != m.end();it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}

	system("pause");
	return 0;
}