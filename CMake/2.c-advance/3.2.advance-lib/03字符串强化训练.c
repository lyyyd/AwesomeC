#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void my_strcpy01(char* dest,const char* src)
{
    //数组
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    //字符串结束标志
    dest[i] = '\0';
}
void my_strcpy02(char* dest, const char* src)
{
    //指针+步长
    int i = 0;
    while (*(src + i) != '\0')
    {
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest + i) = 0;
}
void my_strcpy03(char* dest, const char* src)
{
    //指针
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = 0;
}
void my_strcpy04(char* dest, const char* src)
{
    while (*dest++ = *src++);
}

char* my_strcpy(char* dest, const char* src)
{
    //在函数执行时  需要对函数参数进行判断
    if (dest == NULL || src == NULL)
    {
        return NULL;
    }
    while (*dest++ = *src++);
}

int main0301()
{
    char dest[100];
    char* p = "hello world";
    my_strcpy(dest, p);

    printf("%s\n", dest);

    return EXIT_SUCCESS;
}

//字符串逆置
void reverse(char* str)
{
    char* start = str;
    char* end = str + strlen(str) - 1;
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
int main0302()
{
    char str[] = "hello world";
    reverse(str);
    printf("%s", str);
    return 0;

}
