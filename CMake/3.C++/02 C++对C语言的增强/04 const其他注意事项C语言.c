#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、全局变量前加const ， 默认是外部链接属性
int main()
{
	extern const int g_a; //告诉编译器 g_a在其他的文件中可以找到
	printf("g_a = %d\n", g_a);


	system("pause");
	return EXIT_SUCCESS;
}