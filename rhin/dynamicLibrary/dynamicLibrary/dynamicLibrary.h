//#pragma once
//#ifdef DYNAMICLIBRARY_EXPORTS
//#define DYNAMICLIBRARY_API __declspec(dllexport)
//#else
//#define DYNAMICLIBRARY_API __declspec(dllimport)
//#endif
//
//// ���� add ����
//DYNAMICLIBRARY_API int add(int a, int b);

// dynamicLibrary.h
#ifdef DYNAMICLIBRARY_EXPORTS
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif

// ���嶯̬�⺯����װ�ṹ��
typedef struct {
    int (*add)(int a, int b);
} DynamicLibrary;

// ��ȡ��̬�⺯����װ�ṹ��ʵ��
DYNAMICLIBRARY_API DynamicLibrary get_dynamic_library();