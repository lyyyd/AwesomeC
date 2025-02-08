//#include <stdio.h>
//#include <stdlib.h>
//#include "staticLibrary.h"
////#include "dynamicLibrary.h"
//
//int main() {
//    int a = 3, b = 5;
//
//    // ���þ�̬��� add ����
//    int static_result = add(a, b);
//    printf("���þ�̬��� Static library result: %d + %d = %d\n", a, b, static_result);
//
//    // ���ö�̬��� add ����
//    //int dynamic_result = add(a, b);
//    //printf("���ö�̬��� Dynamic library result: %d + %d = %d\n", a, b, dynamic_result);
//
//    system("pause");
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include "staticLibrary.h"
#include "dynamicLibrary.h"

int main() {
    int a = 3, b = 5;

    // ��ʼ����̬��
    StaticLibrary static_lib = StaticLibrary_Init();
    // ���þ�̬��� add ����
    int static_result = static_lib.add(a, b);
    printf("���þ�̬��� Static library result: %d + %d = %d\n", a, b, static_result);


    int c = 8, d = 9;
    // ��ʼ����̬��
    DynamicLibrary dynamic_lib = DynamicLibrary_Init();
    // ���ö�̬��� add ����
    int dynamic_result = dynamic_lib.add(c, d);
    printf("���ö�̬��� Dynamic library result: %d + %d = %d\n", c, d, dynamic_result);

    system("pause");
    return 0;
}
