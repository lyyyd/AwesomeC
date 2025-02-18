//#pragma comment(lib,"./静态库.lib")
#include<stdio.h>
#include"staticlib.h"

int main()
{

    int arr[] = { 9,1,5,6,10,8,3,7,2,4 };
    BubbleSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
