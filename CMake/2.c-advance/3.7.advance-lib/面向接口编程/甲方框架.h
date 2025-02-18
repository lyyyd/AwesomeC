#pragma once
#include"甲方接口.h"

//定义通信 函数类型
typedef void* (*socket1)(void**);
typedef void(*socket2)(char*, int);

typedef  char* (*encdes)(char*);

typedef struct
{
	//结构体成员为函数指针类型
	socket1 init;
	socket2 send;
	socket2 recv;
	socket1 destroy;
}framework_socket;

typedef struct
{
	encdes encryption;
	encdes decode;
}framework_encdes;