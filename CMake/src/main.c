//#include <stdio.h>
//#include <stdlib.h>
//#include "staticLibrary.h"
////#include "dynamicLibrary.h"
//
//int main() {
//    int a = 3, b = 5;
//
//    // 调用静态库的 add 函数
//    int static_result = add(a, b);
//    printf("调用静态库的 Static library result: %d + %d = %d\n", a, b, static_result);
//
//    // 调用动态库的 add 函数
//    //int dynamic_result = add(a, b);
//    //printf("调用动态库的 Dynamic library result: %d + %d = %d\n", a, b, dynamic_result);
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

    // 初始化静态库
    StaticLibrary static_lib = StaticLibrary_Init();
    // 调用静态库的 add 函数
    int static_result = static_lib.add(a, b);
    printf("调用静态库的 Static library result: %d + %d = %d\n", a, b, static_result);


    int c = 8, d = 9;
    // 初始化动态库
    DynamicLibrary dynamic_lib = DynamicLibrary_Init();
    // 调用动态库的 add 函数
    int dynamic_result = dynamic_lib.add(c, d);
    printf("调用动态库的 Dynamic library result: %d + %d = %d\n", c, d, dynamic_result);

    system("pause");
    return 0;
}
