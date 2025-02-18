#define _CRT_SECURE_NO_WARNINGS

#include "darr.h"

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

//通过姓名作为关键字比较
int my_cmp(void *data, void *key)
{
    stu_t *s = data;

    return strcmp(s->name, key);
}

//动态数组测试
int main()
{
    darr_t *d = NULL;

    stu_t s1 = {1, 10, "洪七公"};
    stu_t s2 = {
        .id = 2,
        .age = 11,
        .name = "王重阳"
    };

    stu_t s3 = {3, 12, "欧阳锋"};
    stu_t s4 = {4, 13, "黄药师" };
    stu_t s5 = {5, 14, "一灯大师"};

    stu_t s6 = {
        .id = 6,
        .age = 15,
        .name = "外星人"
        };

    //1. 初始化
    d = darr_init(5);
    if (NULL == d)
    {
        printf("darr_init failed...\n");
        goto err0;
    }

    printf("容量： %d 元素个数: %d\n", d->capacity, d->count);

    //2. 添加数据
    darr_insert_by_index(d, 0, &s1);
    darr_insert_by_index(d, 0, &s2);
    darr_insert_by_index(d, 0, &s3);
    darr_insert_by_index(d, 0, &s4);
    darr_insert_by_index(d, 0, &s5);
    darr_insert_by_index(d, 0, &s6);

    //3. 遍历
    darr_traverse(d, my_print);
    printf("容量： %d 元素个数: %d\n", d->capacity, d->count);


#if 0
    printf("==================================\n");
    darr_delete_by_index(d, 3);
    darr_traverse(d, my_print);
    printf("容量： %d 元素个数: %d\n", d->capacity, d->count);
#endif

    printf("==================================\n");
    darr_delete_by_key(d, "欧阳锋", my_cmp);
    darr_traverse(d, my_print);
    printf("容量： %d 元素个数: %d\n", d->capacity, d->count);

    //4. 销毁
    darr_destroy(d);

    system("pause");
    return 0;
    err0:
        return 1;
}
