//#pragma once
//// staticLibrary.h
//// ���� add ����
//int add(int a, int b);


// ���徲̬�⺯����װ�ṹ��
typedef struct {
    int (*add)(int a, int b);
} StaticLibrary;

// ��ȡ��̬�⺯����װ�ṹ��ʵ��
StaticLibrary get_static_library();