#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void func(string str)
{
}

void func2(const char * str)
{
}


//string与const char * 转换
void test01()
{
	string str = "abc";
	//string 转 const char *   利用 .c_str()
	const char* str2 = str.c_str();

	//const char * 转 string   利用 string有参构造
	string str3(str2);

	//const char * 可以隐式转换为 string，但是反之不可以的
	func(str2);
	//func2(str); //error string不会隐式转为const char *
}

//大小写转换
void test02()
{
	string str = "abcDeFGhI";

	for (int i = 0; i < str.size(); i++)
	{
		str[i] = toupper(str[i]);
	}

	cout << str << endl;

	for (int i = 0; i < str.size(); i++)
	{
		str[i] = tolower(str.at(i));
	}

	cout << str << endl;
}


int main()
{
	test02();


	system("pause");
	return 0;
}