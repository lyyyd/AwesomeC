#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct  stu
{
    char* name;
    int age;
}ss;
int main()
{
    //深拷贝
    //int a = 10;
    //int b = a;
    //b = 20;
    //深拷贝
    //char* ch = "hello world";
    //char buf[100];
    ////strcpy(buf, ch);
    ////深拷贝
    //memcpy(buf, ch, 12);

    ss s1;
    s1.name = (char *)malloc(sizeof(char) * 21);
    strcpy(s1.name, "张三");
    s1.age = 18;
    ss s2;
    s2 = s1;//浅拷贝
    //深拷贝
    s2.name = (char*)malloc(sizeof(char) * 21);
    strcpy(s2.name, s1.name);
    s2.age = s1.age;



    //strcpy(s2.name, "李四");

    printf("%s %d\n", s2.name, s2.age);
    printf("%s %d\n", s1.name, s1.age);

    system("pause");
    return EXIT_SUCCESS;
}
