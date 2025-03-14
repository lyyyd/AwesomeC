#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int num = 0;
	cout << "请输入1~10之间的数字" << endl;

	while (true)
	{
		cin >> num;
		if (num >= 1 && num <= 10)
		{
			cout << "输入正确" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;

		//重置标志位
		cin.clear();
		//刷新缓冲区  vs版本低  可以利用 cin.sync() 高版本废弃
		char buf[1024] = "";
		cin.getline(buf, 1024);

		//标志位为0代表正常，1代表异常
		//cout << "标志位： " << cin.fail() << endl;
	}


	system("pause");
	return 0;
}