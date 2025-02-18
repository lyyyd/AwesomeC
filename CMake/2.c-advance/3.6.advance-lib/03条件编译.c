#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main0301()
{
    //等同于将一块代码注释
#ifndef TEST
    printf("hello world\n");
#else
    printf("hello kitty\n");
#endif // TEST

    return EXIT_SUCCESS;
}

#if 0
//代码片段
int main()
{
#if 0
    printf("helo world\n");
#else
    printf("hello kitty\n");
#endif
}
#elif 0
int main()
{

}
#endif