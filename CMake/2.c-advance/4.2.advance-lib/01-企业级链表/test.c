#define _CRT_SECURE_NO_WARNINGS

#include "slist.h"

//结构体声明
typedef struct _stu_t {
    node_t *next; //64位 前面8个字节存储下一个节点的地址
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

//自定义销毁函数
void my_destroy(void *data)
{
    stu_t *s = data;

    free(s);
}

int main()
{
    int id = -1;
    slist_t *s = NULL;
    stu_t *stu = NULL;

    //设置随机种子
    srand((unsigned int)time(NULL));

    //1. 初始化
    s = slist_init(my_destroy);
    if (NULL == s)
    {
        printf("slist初始化失败...\n");
        goto err0;
    }

    //2. 循环添加数据
    while (1)
    {
        printf("请输入学号: [-1 quit]  ");
        scanf("%d", &id);

        if (-1 == id)
            break;

        //分配空间
        stu = malloc(sizeof(stu_t));
        if (NULL == stu)
        {
            printf("malloc stu failed...\n");
            break;
        }
        memset(stu, 0, sizeof(stu_t));

        //赋值
        stu->next = NULL;
        stu->id = id;
        stu->sex = "MF"[rand() % 2];
        sprintf(stu->name, "%c%c%c%c%c%c%c%c", 'A' + rand() % 26, 'a' + rand() % 26,
                                               'a' + rand() % 26, 'a' + rand() % 26,
                                               'A' + rand() % 26, 'a' + rand() % 26,
                                               'a' + rand() % 26, 'a' + rand() % 26
            );

        slist_insert_by_index(s, stu, 0);
    }

    //3. 遍历
    slist_traverse(s, my_print);


#if 1
    printf("==============================\n");
    slist_delete_by_index(s, 1);
    slist_traverse(s, my_print);

#endif

    //4. 销毁
    slist_destroy(s);


    system("pause");
    return 0;
    err0:
        return 1;
}
