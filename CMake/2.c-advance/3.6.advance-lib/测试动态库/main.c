#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"./动态库.lib")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"动态库.h"

int main()
{

    int arr[] = { 9,1,5,6,10,8,3,7,2,4 };

    BubbleSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }

    system("pause");
    return EXIT_SUCCESS;
}
