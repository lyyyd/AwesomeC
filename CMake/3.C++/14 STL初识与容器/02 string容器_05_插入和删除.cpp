#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
插入
string& insert(int pos, const char* s);		//插入字符串
string& insert(int pos, const string& str);	//插入字符串
string& insert(int pos, int n, char c);		//在指定位置插入n个字符c

删除
string& erase(int pos, int n = npos);		//删除从Pos开始的n个字符
*/
void test01()
{
	string str = "hello";
	str.insert(1, "111");

	cout << str << endl; //h111ello

	str.insert(5, 3, 'w');
	cout << str << endl; //h111ewwwllo

	str.erase(1, 3);
	cout << str << endl; //hewwwllo

	str.erase(3);
	cout << str << endl; //hew
}
int main()
{
	test01();


	system("pause");
	return 0;
}