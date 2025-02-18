#include "乙方1代码实现.h"
#include<stdlib.h>
#include<stdio.h>

void * Imp1InitSocket(void ** handle)
{
	printf("乙方1：创建通过连接成功\n");
	return NULL;
}

void Imp1SendMassage(char * msg, int len)
{
	printf("乙方1：发送数据：%s  长度：%d\n", msg, len);
}

void Imp1RecvMassage(char * msg, int len)
{
	printf("乙方1：接收数据：%s  长度：%d\n", msg, len);
}

void * Imp1DestroySocket(void ** handle)
{
	printf("乙方1：销毁通信连接成功\n");
	return NULL;
}

char * Imp1Encryption(char * msg)
{
	printf("乙方1：数据加密成功\n");
	return NULL;
}

char * Imp1Decode(char * msg)
{
	printf("乙方1：数据解密成功\n");
	return NULL;
}
