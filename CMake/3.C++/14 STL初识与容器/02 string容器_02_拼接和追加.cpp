#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*  拼接
string operator+(const string &str1,const string &str2 );	//str1与str2拼接，返回拼接后字符串
string operator+(const string &str1,const char * str2);	//str1与str2拼接，返回拼接后字符串
string operator+(const char * str1,const string& str2);	//str1与str2拼接，返回拼接后字符串
string operator+(const string &str,const char c);		//str与字符c拼接，返回拼接后字符串
string operator+(const char c， const string& str);	//字符c与str拼接，返回拼接后字符串
*/
void test01()
{
	string str1 = "abc";
	string str2 = "def";

	string str3 = str1 + str2;  //abcdef
	string str4 = str1 + "xyz"; //abcxyz
	string str5 = "xyz" + str1; //xyzabc

	string str6 = str5 + 'd'; //xyzabcd
	string str7 = 'w' + str2; //wdef

	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
	cout << "str5 = " << str5 << endl;
	cout << "str6 = " << str6 << endl;
	cout << "str7 = " << str7 << endl;
}

/*  追加
string& operator+=(const char* str);		//字符串str追加到源字符串
string& operator+=(const char c);		//字符c追加到源字符串
string& operator+=(const string& str);		//字符串str追加到源字符串
string& append(const char *s);		//字符串s连接到当前字符串结尾
string& append(const char *s, int n);		//字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);		//同operator+=(const string& str)
string& append(const string &s, int pos, int n);	//字符串s中从pos开始的n个字符连接到字符串结尾
*/
void test02()
{
	string str1 = "我";
	//str1 += "爱北京";
	str1.append("爱北京");

	cout << str1 << endl;

	string str2 = "天安门";
	//str1 += str2;
	str1.append(str2);
	cout << str1 << endl;

	string str3 = "abc";
	str3 += 'd';
	cout << "str3 = " << str3 << endl; //abcd

	str3.append("xyzlajdlfj", 3);
	cout << "str3 = " << str3 << endl; //abcdxyz

	string str4 = "w";
	str4.append(str3, 1, 3); //wbcd
	cout << "str4 = " << str4 << endl;
}


int main()
{
	test02();

	system("pause");
	return 0;
}