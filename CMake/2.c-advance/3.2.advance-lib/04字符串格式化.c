#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main0401()
{
    char str[100];
    //sprintf在字符串格式化后 自动添加\0
    //sprintf(str, "%d+%d=%d", 1, 2, 3);
    //sprintf(str, "==%3d+%03d=%-3d==", 1, 2, 3);
    //字符串追加  strcat
    sprintf(str, "%s%s", "hello", "world");
    printf("%s\n", str);

    return EXIT_SUCCESS;
}

int main0402()
{
    char str[100] = "  1+002=3  ";
    int a, b, c;
    sscanf(str, "%d+%d=%d", &a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    return 0;
}


int main0403()
{
    //char arr[] = "aadbbddbcdeabcd";
    char arr[] = "1231278656123abcdef";

    int a;
    char str[100];
    //% * 表示忽略数据
    //sscanf(arr, "%*d%s", &a, str);
    //sscanf(arr, "%3d%s",&a, str);
    //% width 表示读取数据个数（宽度）
    //sscanf(arr,"%6s", str);
    //% []  表示读取某一个区间的数据
    //sscanf(arr, "%[a-d]", str);
    //sscanf(arr, "%[0-9]", str);
    //sscanf(arr, "%[1234]", str);
    //% [^字符] 表示读取非“字符”的内容
    sscanf(arr, "%[^a-z]", str);
    printf("%s\n", str);
    return 0;

}

int main0405()
{
    char str[] = "helloworld@itcast.cn";
    char arr1[100];
    char arr2[100];
    sscanf(str, "%[^@]@%s", arr1, arr2);
    printf("%s\n", arr1);
    printf("%s\n", arr2);
    return 0;
}

int main0406()
{
    char str[] = "123abcd$myname@000qwe";
    char arr1[100];
    char arr2[100];
    //正则表达式
    //sscanf(str, "%[^$]$%6s", arr1, arr2);
    //sscanf(str, "%8s%6s", arr1, arr2);
    sscanf(str, "%*d%[a-d]$%6s",arr1,arr2);
    printf("%s\n", arr2);
    return 0;
}