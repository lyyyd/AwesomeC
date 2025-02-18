#define _CRT_SECURE_NO_WARNINGS

#include "slist.h"

//数据类型
typedef struct _stu_t {
    int id;
    char sex;
    char name[32];
}stu_t;


//id作为关键字
int my_cmp(void *data, void *key)
{
    stu_t *s = data;

    if (NULL == data || NULL == key)
    {
        return -1;
    }

    return s->id - (int)key;
}

void my_print(void *data)
{
    stu_t *p = data;
    printf("学号: %d 性别: %c 姓名: %s\n", p->id, p->sex, p->name);
}

int main()
{
    int id = 0;
    slist_t *s = NULL;

    stu_t stu;

    //设置随机种子
    srand((unsigned int)time(NULL));

    //1. 链表初始化
    s = slist_init(sizeof(stu_t));
    if (NULL == s)
    {
        printf("slist_init failed...\n");
        goto err0;
    }

    //2. 添加数据
    while (1)
    {
        printf("请输入学号： [-1 退出]: ");
        scanf("%d", &id);

        if (-1 == id)
            break;

        //赋值
        memset(&stu, 0, sizeof stu);
        //学号
        stu.id = id;
        //随机性别
        stu.sex = "MF"[rand() % 2];
        sprintf(stu.name, "%c%c%c%c%c%c%c%c", 'A' + rand() % 26, 'a' + rand() % 26,
                                              'a' + rand() % 26, 'a' + rand() % 26,
                                              'A' + rand() % 26, 'a' + rand() % 26,
                                              'a' + rand() % 26, 'a' + rand() % 26
            );


        //头插法
        //slist_prepend(s, &stu);
        //尾插法
        slist_append(s, &stu);
    }

    //3. 链表的遍历
    slist_traverse(s, my_print);


#if 0
    stu_t stu1 = { 0, 'M', "AAAA" };
    printf("=============================\n");
    slist_insert_by_index(s, &stu1, 0);
    slist_traverse(s, my_print);

#endif

#if 0
    printf("=============================\n");
    printf("count: %d\n", slist_count(s));
#endif


#if 0
    printf("=============================\n");
    slist_delete_by_index(s, 0);
    slist_traverse(s, my_print);
#endif

#if 1
    printf("=============================\n");
    slist_delete_by_key(s, (void*)3, my_cmp);
    slist_traverse(s, my_print);
#endif

    //4. 链表的销毁
    slist_destroy(s);

    system("pause");
    return 0;
    err0:
        return 1;
}
