#include <iostream>  //iostream 相当于 C语言下的 stdio.h    i - input 输入  o -output 输出
using namespace std; //using 使用  namespace 命名空间  std 标准  ，理解为打开一个房间，房间里有我们所需要用的东西

////C头文件的风格是带.h
////C++头文件风格不带.h
//#include<time.h> //C风格
//#include<ctime>  //C++风格

//程序入口
int main()
{
	//cout 标准的输出流对象，可以利用这个对象，向屏幕中输出内容
	//<< 后面可以拼接想要输出的内容，在C++下左移运算符有了其他的用法
	// - 减法/负号    *  乘法/指针
	// endl   - end line 换行
	// printf("%d %s %lf %f %c...")
	cout << "Hello world" << 10 << endl;

	system("pause");  //按任意键继续
	return EXIT_SUCCESS; //返回正常退出值
}