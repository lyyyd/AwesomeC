#define _CRT_SECURE_NO_WARNINGS

#include "stack.h"

//声明一个结构体
typedef struct _stu_t {
    int id;
    char sex;
    char name[32];
}stu_t;


//自定义输出
void my_print(void *data)
{
    stu_t *s = data;

    printf("学号: %d 性别: %c 姓名: %s\n", s->id, s->sex, s->name);
}



int main()
{
    int id;
    stu_t stu;

    stack_t *s = NULL;

    //1. 初始化
    s = stack_init(sizeof(stu_t), NULL);
    if (NULL == s)
    {
        printf("stack_init初始化失败...\n");
        goto err0;
    }

    //2. 进栈
    while (1)
    {

        printf("请输入学号: [-1 quit]  ");
        scanf("%d", &id);

        if (-1 == id)
            break;

        memset(&stu, 0, sizeof(stu));
        //赋值
        stu.id = id;
        stu.sex = "MF"[rand() % 2];
        sprintf(stu.name, "%c%c%c%c%c%c%c%c", 'A' + rand() % 26, 'a' + rand() % 26,
            'a' + rand() % 26, 'a' + rand() % 26,
            'A' + rand() % 26, 'a' + rand() % 26,
            'a' + rand() % 26, 'a' + rand() % 26
        );

        stack_push(s, &stu);
    }

    //测试栈中元素的个数
    printf("count: %d\n", stack_count(s));

    //获取栈顶元素
    memset(&stu, 0, sizeof stu);
    stack_top(s, &stu);
    my_print(&stu);
    printf("===========================\n");

    //3. 出栈
    while (stack_is_empty(s))
    {
        memset(&stu, 0, sizeof stu);
        //出栈
        stack_pop(s, &stu);
        my_print(&stu);
    }

    //4. 销毁
    stack_destroy(s);

    system("pause");
    return 0;
    err0:
        return -1;
}


