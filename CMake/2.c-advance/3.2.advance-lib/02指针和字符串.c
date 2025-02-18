#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main0201()
{
    //字符数组  栈区
    char arr[] = { 'h','e','l','l','o' };
    /*
    for (int i = 0; i < sizeof(arr); i++)
    {
        printf("%c", arr[i]);
    }
    */
    printf("%s", arr);
    return EXIT_SUCCESS;
}


int main0202()
{
    //字符串   字符串一定是一个字符数组  栈区
    //char arr[6] = { 'h','e','l','l','o' };
    char arr[] = { "hello" };

    printf("%s", arr);
    return 0;
}

int main0203()
{
    //指针指向常量区字符串  不能修改字符串内容 常量区
    char* p = "hello";
    //p[2] = 'a';//err
    p = "美朵";
    printf("%s\n", p);
    return 0;
}

int main0204()
{
    //定义指针指向堆区字符串  堆区
    char* p = (char*)malloc(100);
    //p[0] = 'h';
    //p[1] = 'e';
    //p[2] = '\0';//

    strcpy(p, "来了，老弟");
    strcat(p, "来玩啊，小帅哥");


    printf("%s\n", p);
    free(p);
    return 0;
}

int main0205()
{
    //八进制和十六进制 表示字符
    printf("%c%c\n", '\211','\221');
    printf("%c%c\n", '\x8c','\xbb');
    return 0;
}