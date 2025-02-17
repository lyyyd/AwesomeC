#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>



void test01()
{
    //字符数组只能初始化5个字符，当输出的时候，从开始位置直到找到0结束
    char str1[] = { 'h', 'e', 'l', 'l', 'o' };
    printf("%s\n",str1);

    //字符数组部分初始化，剩余填0
    char str2[100] = { 'h', 'e', 'l', 'l', 'o' };
    printf("%s\n", str2);

    //如果以字符串初始化，那么编译器默认会在字符串尾部添加'\0'
    char str3[] = "hello";
    printf("%s\n",str3);
    printf("sizeof str:%d\n",sizeof(str3));
    printf("strlen str:%d\n",strlen(str3));

    //sizeof计算数组大小，数组包含'\0'字符
    //strlen计算字符串的长度，到'\0'结束

    //那么如果我这么写,结果是多少呢？
    char str4[100] = "hello";
    printf("sizeof str:%d\n", sizeof(str4));
    printf("strlen str:%d\n", strlen(str4));

    //请问下面输入结果是多少？sizeof结果是多少？strlen结果是多少？
    char str5[] = "hello\0world";
    printf("%s\n",str5);
    printf("sizeof str5:%d\n",sizeof(str5));
    printf("strlen str5:%d\n",strlen(str5));

    //再请问下面输入结果是多少？sizeof结果是多少？strlen结果是多少？
    char str6[] = "hello\012world";
    printf("%s\n", str6);
    printf("sizeof str6:%d\n", sizeof(str6));
    printf("strlen str6:%d\n", strlen(str6));

}


int main(){
    test01();
    system("pause");
    return EXIT_SUCCESS;
}
