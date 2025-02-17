#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>

// 字符串 拷贝
// 第一种实现
void copyString1(char * dest, char  * sourse)
{
    // 利用下标的方式拷贝
    int len = strlen(sourse);
    for (int i = 0; i < len; ++i) {
        dest[i] = sourse[i];
    }
    dest[len] = '\0';
}
// 第二种实现
void copyString2(char * dest, char  * sourse)
{
//    利用字符串指针
    while (*sourse != '\0')
    {
        *dest = *sourse;

        dest++;
        sourse++;
    }
    *dest = '\0';
}
// 第三种实现
void copyString3(char * dest, char  * sourse)
{
    while (*dest++ = *sourse++)
    {}
}
void test01()
{
    char * str = "hello world!";

    char buf[1024];

//    copyString1(buf, str);
//    copyString2(buf, str);
    copyString3(buf, str);

    printf("buf = %s\n", buf);
}


// 字符串翻转

// abcdefg -> gfedcba
// 第一种方式
void reverseString1(char * str)
{
    int len = strlen(str);
    int start = 0;
    int end  = len - 1;

    while (start < end)
    {
        // 交换首位下标元素
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}
void test02()
{
    char str[] = "abcdefg";

    reverseString1(str);

    printf("%s\n", str);
}

int main(){
    test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;
}
