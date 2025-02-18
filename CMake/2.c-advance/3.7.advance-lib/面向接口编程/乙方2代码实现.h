#pragma once
#pragma once


//通过接口定义
//初始化通信 ip port username password  char* arr[]
extern void* Imp2InitSocket(void** handle);

//发送数据
extern void Imp2SendMassage(char* msg, int len);

//接收数据
extern void Imp2RecvMassage(char* msg, int len);

//销毁通信
extern void* Imp2DestroySocket(void** handle);

//加密接口
extern char* Imp2Encryption(char* msg);

//解密接口
extern char* Imp2Decode(char* msg);


