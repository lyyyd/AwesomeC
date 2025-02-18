#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"乙方1代码实现.h"
#include"乙方2代码实现.h"
#include"甲方框架.h"


framework_socket*  init_socket(socket1 init, socket2 send, socket2 recv, socket1 destroy)
{
    framework_socket* fs=(framework_socket*)malloc(sizeof(framework_socket));
    fs->init = init;
    fs->send = send;
    fs->recv = recv;
    fs->destroy = destroy;

    return fs;
}
//测试代码
void test_socket(framework_socket* p)
{
    void** handle = NULL;
    char* msg = "你瞅啥";
    //函数调用
    p->init(handle);
    p->send(msg, 6);
    p->recv(msg, 6);
    p->destroy(handle);
}
framework_encdes* init_encdes(encdes encryption, encdes decode)
{
    framework_encdes* fe = (framework_encdes*)malloc(sizeof(framework_encdes));
    fe->encryption = encryption;
    fe->decode = decode;
    return fe;
}

void test_encdes(framework_encdes* fe)
{
    char* p = "瞅你咋地";
    fe->encryption(p, 8);
    fe->decode(p, 8);
}

int main0101()
{

    //乙方1 数据初始化
    //framework_socket* p = init_socket(Imp1InitSocket, Imp1SendMassage, Imp1RecvMassage, Imp1DestroySocket);
    //test_socket(p);

    //乙方2 数据初始化
    framework_socket* p = init_socket(Imp2InitSocket, Imp2SendMassage, Imp2RecvMassage, Imp2DestroySocket);
    test_socket(p);
    free(p);

    return EXIT_SUCCESS;
}

int main()
{
    //乙方1 加密解密
    //framework_encdes* fe = init_encdes(Imp1Encryption, Imp1Decode);
    //test_encdes(fe);
    //乙方2 加密解密
    framework_encdes* fe = init_encdes(Imp2Encryption, Imp2Decode);
    test_encdes(fe);
    free(fe);
    return 0;
}
