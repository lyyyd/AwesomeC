#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*
01001001
0<<1=0
0<<1+1=1
1<<1=2
2<<1=4
4<<1+1=9
9<<1=18
18<<1=26
36<<1+1 73
*/

int main0201(void)
{
    char *pbin = "01001001";
    int val = 0;
    for (int i = 0; i < strlen(pbin); i++)
    {
        if (pbin[i] == '1')
            val = (val << 1) + 1;
        else
            val = val << 1;
    }
    printf("%d\n", val);

    return 0;
}


int main0202()
{
    char *pbin = "01001001";

    int index = 0;
    int val = 0;
    for (int i = strlen(pbin) - 1; i >= 0; i--)
    {
        //printf("%c\n", pbin[i]);
        if (pbin[i] == '1')
        {
            //数学表达式
            //val += 1 * 2 ^ index;
            //val += 1 * pow(2, index);
            val += 1 << index;
        }
        index++;
    }
    printf("%d\n", val);

    return EXIT_SUCCESS;
}
