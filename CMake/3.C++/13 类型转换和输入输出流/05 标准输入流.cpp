#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
cin.get();    		从缓冲区读取一个字符
cin.get(一个参数)；  	从缓冲区读取一个字符
cin.get(两个参数)； 	从缓冲区读取字符串
cin.getline();		从缓冲区读取字符串
cin.ignore();		忽略缓冲区中1个字符
cin.ignore(int x);	忽略缓冲区中x个字符
cin.peek();		查看缓冲区中一个字符
cin.putback();	将指定字符放回
*/

//1 cin.get();    		从缓冲区读取一个字符
void test01()
{
	char ch = cin.get();
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;

	ch = cin.get();
	cout << "ch = " << ch << endl;
	//输入 as 输出结果是什么？
	//第一次输出a、第二次输出s、第三次是换行、第四次等待下次输入
}

//cin.get(一个参数)；  	从缓冲区读取一个字符
//cin.get(两个参数)； 	从缓冲区读取字符串
void test02()
{
	//char ch;
	//cin.get(ch);
	//cout << "ch = " << ch << endl;

	char buf[1024] = "";
	cin.get(buf, 1024);


	char ch = cin.get(); // 换行符会遗留在缓冲区中
	if (ch == '\n')
	{
		cout << "换行符遗留在缓冲区中" << endl;
	}

	cout << buf << endl;
}


//cin.getline();		从缓冲区读取字符串
void test03()
{
	char buf[1024] = "";
	cin.getline(buf, 1024);

	char ch = cin.get(); //换行符不会遗留在缓冲区中，而是直接扔掉
	if (ch == '\n')
	{
		cout << "换行符遗留在缓冲区中" << endl;
	}
	cout << buf << endl;
}

//cin.ignore();		忽略缓冲区中1个字符
//cin.ignore(int x);	忽略缓冲区中x个字符
void test04()
{
	cin.ignore(3);
	char ch = cin.get();

	cout << "ch = " << ch << endl;
}

//cin.peek()  查看缓冲区中一个字符
void test05()
{
	char ch = cin.peek();

	cout << "ch = " << ch << endl;

	ch = cin.get();

	cout << "ch = " << ch << endl;
}

//cin.putback();	将指定字符放回
void test06()
{
	char ch = cin.get();

	cin.putback(ch);  //将字符放回原位

	char buf[1024] = "";
	cin.getline(buf, 1024);
	cout << buf << endl;
}

int main()
{
	test06();


	system("pause");
	return 0;
}