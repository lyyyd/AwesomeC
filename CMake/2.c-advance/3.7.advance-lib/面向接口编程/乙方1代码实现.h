#pragma once

//通过接口定义
//初始化通信 ip port username password
extern void* Imp1InitSocket(void** handle);

//发送数据
extern void Imp1SendMassage(char* msg, int len);

//接收数据
extern void Imp1RecvMassage(char* msg, int len);

//销毁通信
extern void* Imp1DestroySocket(void** handle);

//加密接口
extern char* Imp1Encryption(char* msg);

//解密接口
extern char* Imp1Decode(char* msg);
