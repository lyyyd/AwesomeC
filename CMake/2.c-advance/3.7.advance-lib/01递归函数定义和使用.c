#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//函数格式
//返回值类型 函数名（函数参数列表）
//{
//  函数代码体
//	return 返回值
//}
//返回值类型 函数名（函数参数列表）
//{
//  函数代码体-》函数名（函数参数列表）
//	return 返回值
//}

//void test()
//{
//	int a, b, c, d, e, f;
//	//return 表示函数结束  goto  exit(0)
//	return;
//	printf("hello world\n");
//	//在函数定义时 调用函数本身 递归函数
//	test();
//	return;
//}

void test(int a)
{
    if (a == 0)
        return;
    printf("%d\n", a);
    test(a - 1);
    return;
}

int main01()
{
    test(10);
    return EXIT_SUCCESS;
}
