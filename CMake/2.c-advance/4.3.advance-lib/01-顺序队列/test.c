#define _CRT_SECURE_NO_WARNINGS

#include "seq_queue.h"

typedef struct _stu_t {
    int id;
    int age;
    char name[64];
}stu_t;

//自定义输出函数
void my_print(void *data)
{
    stu_t *s = data;
    printf("id: %d age: %d name: %s\n", s->id, s->age, s->name);
}


//动态数组测试
int main()
{
    queue_t *q = NULL;
    stu_t *pstu = NULL;
    stu_t s1 = { 1, 10, "洪七公" };
    stu_t s2 = {2, 11, "王重阳"};
    stu_t s3 = { 3, 12, "欧阳锋" };
    stu_t s4 = { 4, 13, "黄药师" };
    stu_t s5 = { 5, 14, "一灯大师" };


    //1. 初始化
    q = queue_init(5);
    if (NULL == q)
    {
        printf("queue_init failed...\n");
        goto err0;
    }



    //2. 添加数据
    queue_en(q, &s1);
    queue_en(q, &s2);
    queue_en(q, &s3);
    queue_en(q, &s4);
    queue_en(q, &s5);
    printf("容量： %d 元素个数: %d\n", q->capacity, q->count);

    //3. 遍历
    while (0 != queue_is_empty(q))
    {
        //出队列
        queue_de(q, &pstu);

        printf("学号: %d 年龄： %d  姓名： %s\n", pstu->id, pstu->age, pstu->name);

    }

    printf("容量： %d 元素个数: %d\n", q->capacity, q->count);

    //4. 销毁
    queue_destroy(q);

    system("pause");
    return 0;
    err0:
        return 1;
}
