//
//#ifndef STATICLIBRARY_H
//#define STATICLIBRARY_H
//
//int add(int a, int b);
//
//#endif


#ifndef STATICLIBRARY_H
#define STATICLIBRARY_H

typedef struct {
    int (*add)(int a, int b);
} StaticLibrary;

// ��ʼ����̬��ṹ��
StaticLibrary StaticLibrary_Init();

#endif