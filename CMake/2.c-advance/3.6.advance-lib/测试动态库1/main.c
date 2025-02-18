#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<Windows.h>


typedef void(*func)(int*, int);
int main()
{
    //定义句柄
    HANDLE hdll;
    hdll=LoadLibrary("./动态库.dll");
    func f = (func)GetProcAddress(hdll, "BubbleSort");

    int arr[] = { 9,1,5,6,10,8,3,7,2,4 };
    f(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }

    return EXIT_SUCCESS;
}
