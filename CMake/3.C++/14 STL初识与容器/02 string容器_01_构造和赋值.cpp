#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

/*  构造
string();			//创建一个空的字符串 例如: string str;
string(const char* s);	        	//使用字符串s初始化
string(const string& str);   	//使用一个string对象初始化另一个string对象
string(int n, char c);           	//使用n个字符c初始化
*/
void test01()
{
	string str1;
	string str2("abcd");
	string str3 = str2;
	string str4(10, 'a');

	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
}

/* 赋值
string& operator=(const char* s);	//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);	//把字符串s赋给当前的字符串
string& operator=(char c);		//字符赋值给当前的字符串
string& assign(const char *s);		//把字符串s赋给当前的字符串
string& assign(const char *s, int n);	//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);	//把字符串s赋给当前字符串
string& assign(int n, char c);		//用n个字符c赋给当前字符串
*/
void test02()
{
	string str1;
	str1 = "abcdefg";

	string str2;
	str2 = str1;

	string str3;
	str3 = 'x';

	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;

	str1.assign("xyz");
	str2.assign("abcdefg", 3);
	str3.assign(str1);
	string str4;
	str4.assign(5, 'w');

	cout << "-------------------" << endl;

	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
}

int main()
{

	test02();

	system("pause");
	return 0;
}