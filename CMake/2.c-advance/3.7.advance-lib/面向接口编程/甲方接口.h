#pragma once


//通过接口定义
//初始化通信 ip port username password  char* arr[]
extern void* InitSocket(void** handle);

//发送数据
extern void SendMassage(char* msg, int len);

//接收数据
extern void RecvMassage(char* msg, int len);

//销毁通信
extern void* DestroySocket(void** handle);

//加密接口
extern char* Encryption(char* msg);

//解密接口
extern char* Decode(char* msg);


