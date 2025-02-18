#define _CRT_SECURE_NO_WARNINGS

#include "stack.h"

void show_error(char *s, char *serr, char *msg)
{
    int i = 0;

    printf("%s\n", msg);
    printf("%s\n", s);

    for (i = 0; i < (serr - s); i++)
    {
        putchar(' ');
    }
    printf("A\n");
}

//就近匹配
/*
从第一个字符开始扫描
当遇见普通字符时忽略，
当遇见左括号时压入栈中
当遇见右括号时从栈中弹出栈顶符号，并进行匹配
匹配成功：继续读入下一个字符
匹配失败：立即停止，并报错
结束：
成功 : 所有字符扫描完毕，且栈为空
    失败：匹配失败或所有字符扫描完毕但栈非空

*/
int main()
{
    char ch;
    char *p = NULL;
    //char *s1 = "5+5*(6)+9/3*1)-(1+3(";
    //char *s1 = "5 + 4 * (3 + 2) - 1(";
    char *s1 = "5 + 4 * (3 + 2) - 1";
    stack_t *s = NULL;


    //初始化
    s = stack_init(sizeof(char), NULL);
    if (NULL == s)
    {
        printf("stack_init 失败...\n");
        goto err0;
    }

    //进栈
    p = s1;
    while (*p)
    {
        if (*p == '(')
        {
            //进栈
            stack_push(s, p);
        }
        else if (*p == ')')
        {
            //出栈
            if (0 == stack_is_empty(s))
            {
                //printf("括号匹配不成功...\n");
                show_error(s1, p, "括号匹配不成功");
                break;
            }
            else
            {
                stack_pop(s, &ch);
            }
        }

        p++;
    }

    //如果栈中不为空 说明匹配不成功
    if (0 == stack_is_empty(s))
    {
        printf("括号匹配成功...\n");
    }
    else
    {
        //printf("括号匹配不成功...\n");
        show_error(s1, p, "括号匹配不成功");
    }

    //销毁
    stack_destroy(s);

    system("pause");
    return 0;
    err0:
        return 1;
}
