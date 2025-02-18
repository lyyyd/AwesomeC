#define _CRT_SECURE_NO_WARNINGS

#include "queue.h"

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

    queue_t *q = NULL;

    //1. 初始化
    q = queue_init(sizeof(stu_t), NULL);
    if (NULL == q)
    {
        printf("queue_init初始化失败...\n");
        goto err0;
    }

    //2. 入队列
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

        queue_en(q, &stu);
    }

    //测试队列中元素的个数
    printf("count: %d\n", queue_count(q));

    //获取队头元素
    memset(&stu, 0, sizeof stu);
    queue_front(q, &stu);
    my_print(&stu);
    printf("===========================\n");

    //3. 出队列
    while (queue_is_empty(q))
    {
        memset(&stu, 0, sizeof stu);
        //出队列
        queue_de(q, &stu);
        my_print(&stu);
    }

    //4. 销毁
    queue_destroy(q);

    system("pause");
    return 0;
    err0:
        return -1;
}


