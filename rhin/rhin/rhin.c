//#include <stdio.h>
//#include "dynamicLibrary.h"
//#include "staticLibrary.h"
//
//int main() {
//    //int a = 3, b = 5;
//    //int result = add(a, b);
//    //printf("The result of %d + %d is %d\n", a, b, result);
//
//    int a = 5, b = 7;
//    int result = add(a, b);
//    printf("The result of %d + %d is %d\n", a, b, result); 
//
//    system("pause");
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include "dynamicLibrary.h"
#include "staticLibrary.h"

int main() {
    int a = 5, b = 7;

    // 获取静态库函数封装结构体实例
    StaticLibrary static_lib = get_static_library();
    int static_result = static_lib.add(a, b);
    printf("静态库 The result of static add %d + %d is %d\n", a, b, static_result);


    int c = 8, d = 9;
    // 获取动态库函数封装结构体实例
    DynamicLibrary dynamic_lib = get_dynamic_library();
    int dynamic_result = dynamic_lib.add(c, d);
    printf("动态库 The result of dynamic add %d + %d is %d\n", c, d, dynamic_result);

    system("pause");
    return 0;
}
