#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>

//截取子串
//string substr(int pos = 0, int n = npos) ;   	//返回由pos开始的n个字符组成的字符串
void test01()
{
	string str = "abcdefg";
	string subStr = str.substr(3, 3);
	cout << subStr << endl; //def
}

//案例1：
//在字符串“zhangsan@sina.com” 中截取子串 zhangsan 并输出
void test02()
{
	string email = "zhangsan@sina.com";

	int pos = email.find("@");

	string userName = email.substr(0, pos);

	cout << userName << endl;
}

//案例2：
//将字符串 “www.boxuegu.com.cn” 中的每个以’.’ 分隔的单词截取到 vector<string>v中
//并遍历容器v
void test03()
{
	string str = "www.boxuegu.com.cn";

	vector<string> v;
	int start = 0; //查找的起始位置
	while (true)
	{
		int pos = str.find(".",start); // start = 4
		if (pos == -1)
		{
			//对最后一个单词额外处理
			string lastWord = str.substr(start);
			v.push_back(lastWord);
			break;
		}
		string temp = str.substr(start, pos-start); // pos = 11  截取 7 个字符
		v.push_back(temp);
		start = pos + 1;
	}

	//遍历容器
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}


}

int main()
{
	test03();


	system("pause");
	return 0;
}