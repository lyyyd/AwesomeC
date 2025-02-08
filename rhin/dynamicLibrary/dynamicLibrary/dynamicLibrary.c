//#include "dynamicLibrary.h"
//
//// ʵ�� add ����
//DYNAMICLIBRARY_API int add(int a, int b) {
//    return a + b;
//}


#include "dynamicLibrary.h"

// ��̬��� add ����ʵ��
static int dynamic_add(int a, int b) {
    return a + b;
}

// ��ȡ��̬�⺯����װ�ṹ��ʵ��
DYNAMICLIBRARY_API DynamicLibrary get_dynamic_library() {
    DynamicLibrary lib;
    lib.add = dynamic_add;
    return lib;
}