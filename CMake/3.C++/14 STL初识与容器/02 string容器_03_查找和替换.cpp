#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*  查找
int find(const string& str, int pos = 0) const; 	//查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;	//查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;	//从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;		//查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;	//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const; 	//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;	//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; 	//查找字符c最后一次出现位置
*/
void test01()
{
	string str = "abcdefg";

	int pos = str.find("dex",0,2);

	//if (pos == -1)
	if (pos == string::npos)
	{
		cout << "未查找到子串" << endl;
	}
	else
	{
		cout << "查找到了子串，位置是：" << pos << endl;
	}

	cout << "--------------" << endl;
	string str2 = "abcdefghide";

	pos = str2.rfind("de");
	if (pos == string::npos)
	{
		cout << "未查找到子串" << endl;
	}
	else
	{
		cout << "查找到了子串，位置是：" << pos << endl;
	}
}

/*  替换
string& replace(int pos, int n, const string& str);	//替换从pos开始n个字符为字符串str
string& replace(int pos, int n,const char* s); 	//替换从pos开始的n个字符为字符串s
*/
void test02()
{
	string str = "abcdefg";

	str.replace(1, 3, "11111");
	cout << "str = " << str << endl; //a11111efg
}

int main()
{
	test02();


	system("pause");
	return 0;
}