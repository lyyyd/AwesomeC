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


#include <cLanguageEnvLib.h>
#include <stdio.h>
#include <stdlib.h>
#include "staticLibrary.h"
#include "dynamicLibrary.h"
#include "cLanguageEnvLib.h"
#include "statementsLib.h"
#include "cTypeLib.h"
#include "ArrLib.h"
#include "funLib.h"
#include "pointerLib.h"
#include "memoryLib.h"
#include "compositeTypeLib.h"
#include "fileLib.h"

int main() {
    // int a = 3, b = 5;

    // // 初始化静态库
    // StaticLibrary static_lib = StaticLibrary_Init();
    // // 调用静态库的 add 函数
    // int static_result = static_lib.add(a, b);
    // printf("调用静态库的 Static library result: %d + %d = %d\n", a, b, static_result);

    // int c = 8, d = 9;
    // // 初始化动态库
    // DynamicLibrary dynamic_lib = DynamicLibrary_Init();
    // // 调用动态库的 add 函数
    // int dynamic_result = dynamic_lib.add(c, d);
    // printf("调用动态库的 Dynamic library result: %d + %d = %d\n", c, d, dynamic_result);


    // int e = 10, f = 5;
    // // 初始化动态库
    // CLanguageEnvLibrary c_language_env_lib = CLanguageEnvLibrary_Init();
    // // 调用动态库的 add 函数
    // int c_language_env_result = c_language_env_lib.sub(e, f);
    // printf("调用动态库的 CLanguageEnv library result: %d - %d = %d\n", e, f, c_language_env_result);
    // c_language_env_lib.init();

    // 初始化动态库
    // CLanguageEnvLib c_language_env_lib = CLanguageEnvLib_Init();
    // c_language_env_lib.init();


    // CTypeLib c_type_lib = CTypeLib_Init();
    // c_type_lib.init();
    //
    // StatementsLib c_statements_lib = StatementsLib_Init();
    // c_statements_lib.init();
    //
    // ArrLib arr_lib = ArrLib_Init();
    // arr_lib.init();
    //
    //
    // FunLib fun_lib = FunLib_Init();
    // fun_lib.init();

    // PointerLib pointer_lib = PointerLib_Init();
    // pointer_lib.init();

    // MemoryLib memory_lib = MemoryLib_Init();
    // memory_lib.init();
    //
    // CompositeTypeLib composite_type_lib = CompositeTypeLib_Init();
    // composite_type_lib.init();
    //
    // FileLib file_lib = FileLib_Init();
    // file_lib.init();

    // system("pause");
    return 0;
}
