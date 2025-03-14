#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <iomanip>

//输出流成员函数
void test01()
{
	cout.put('h').put('e');

	char buf[1024] = "hello world";
	cout.write(buf, strlen(buf));
	//常用还是cout <<
}

//格式化输出
//1、通过流成员函数
void test02()
{
	int num = 99;
	cout.width(10); //设置宽度
	cout.fill('*');  //设置填充
	cout.setf(ios::left); //设置左对齐
	cout.unsetf(ios::dec); //卸载十进制
	cout.setf(ios::hex); //设置十六进制
	cout.unsetf(ios::hex); //卸载十六进制
	cout.setf(ios::oct); //设置八进制
	cout.setf(ios::showbase); //设置显示基数
	cout << num << "aaa" << endl;
}

//2、通过控制符设置格式化输出
void test03()
{
	int num = 99;
	cout << setw(20)
		 << setfill('~')
		 << setiosflags(ios::left)
		 << setiosflags(ios::showbase)
		 << hex   //设置十六进制
		 << num
		 << endl;

}

int main()
{

	test02();

	system("pause");
	return 0;
}