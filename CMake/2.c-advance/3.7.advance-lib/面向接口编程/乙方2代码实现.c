#include "乙方2代码实现.h"
#include<stdlib.h>
#include<stdio.h>

void * Imp2InitSocket(void ** handle)
{
	printf("乙方2：创建通过连接成功\n");
	return NULL;
}

void Imp2SendMassage(char * msg, int len)
{
	printf("乙方2：发送数据：%s  长度：%d\n", msg, len);
}

void Imp2RecvMassage(char * msg, int len)
{
	printf("乙方2：接收数据：%s  长度：%d\n", msg, len);
}

void * Imp2DestroySocket(void ** handle)
{
	printf("乙方2：销毁通信连接成功\n");
	return NULL;
}

char * Imp2Encryption(char * msg)
{
	printf("乙方2：数据加密成功\n");
	return NULL;
}

char * Imp2Decode(char * msg)
{
	printf("乙方2：数据解密成功\n");
	return NULL;
}
