#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


typedef struct
{
    char* key;
    char* value;
}config;
int main13()
{
    FILE* fp = fopen("D:/config.ini", "r");
    if (!fp)
    {
        printf("配置文件打开失败\n");
        return -1;
    }

    char* buf = (char*)malloc(sizeof(char) * 100);
    //config* cp = (config*)malloc(sizeof(config));
    config* cp = NULL;
    int i = 0;
    while (!feof(fp))
    {
        memset(buf, 0, 100);
        fgets(buf, 100, fp);
        //如果是注释 忽略注释
        //#这是我的IP地址
        if (buf[0] != '#')
        {
            cp = (config*)realloc(cp, sizeof(config)*(i + 1));
            //printf("%s", buf);
            //将key和value分别存在结构体成员中
            //计算:之前的字符个数
            //printf("%d\n", strchr(buf, ':') - buf+1);
            cp[i].key = (char*)calloc(strchr(buf, ':') - buf + 1, sizeof(char));
            strncpy(cp[i].key, buf, strchr(buf, ':') - buf);


            //printf("%d\n", buf + strlen(buf) - strchr(buf, ':'));
            cp[i].value = (char*)calloc(buf + strlen(buf) - strchr(buf, ':')+1, sizeof(char));
            strcpy(cp[i].value, strchr(buf, ':') + 1);
            //printf("%s   %s\n", cp[i].key,cp[i].value);
            i++;

        }
    }


    for (int j = 0; j < i; j++)
    {
        printf("key: %s value:%s", cp[j].key, cp[j].value);
    }


    //释放堆空间
    free(buf);
    free(cp);

    //关闭文件
    fclose(fp);
    return EXIT_SUCCESS;
}
