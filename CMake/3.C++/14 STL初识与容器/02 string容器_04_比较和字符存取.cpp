#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*  比较
int compare(const string &s) const;  //与字符串s比较
int compare(const char *s) const;      //与字符串s比较
*/
void test01()
{
	string str1 = "abcde";
	string str2 = "abcde";

	//if (str1.compare(str2) == 0)
	if(str1 == str2)
	{
		cout << "str1 == str2" << endl;
	}
	else if (str1.compare(str2) == 1)
	{
		cout << "str1 > str2" << endl;
	}
	else
	{
		cout << "str1 < str2" << endl;
	}
}

/*  字符存取
char& operator[](int n);     //通过[]方式取字符
char& at(int n);                    //通过at方法获取字符
*/
void test02()
{
	string str = "hello world";
	for (int i = 0; i < str.size(); i++)
	{
		//cout << str[i] << " ";
		cout << str.at(i) << " ";
	}
	cout << endl;

	//[] 和 at 区别在 []访问越界 程序直接崩溃，而at越界抛出 out_of_range的异常
	try
	{
		//cout << str[100] << endl;
		cout << str.at(100) << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "访问越界" << endl;
	}
}

int main()
{
	test02();


	system("pause");
	return 0;
}