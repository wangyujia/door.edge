
/* test.h : 测试头文件. Combo.xy */

#ifndef _TEST_H_
#define _TEST_H_

#include "../h/donex.h"

#ifdef __cplusplus
extern "C" {
#endif


/* 测试入口函数原型 */
typedef int (*DX_TEST_FUNC)(
    int argc, const char **argv,
    LOG_PRINT print, LOG_PARA para);


/* 测试节点类型 */
typedef struct DX_TEST_S {
    const char *    name;
    DX_TEST_FUNC    func;
    DX_DLL_NODE(struct DX_TEST_S);
} DX_TEST;


/* 测试头部类型 */
typedef struct DX_TEST_HEAD_S {
    DX_DLL_HEAD(DX_TEST);
} DX_TEST_HEAD;
extern  DX_TEST_HEAD dx_test_head;


/* 测试结果 */
typedef struct DX_TEST_RESULT_S {
    int count;
    int failed;
    const char *name;
} DX_TEST_RESULT;


/* 测试用例 */
#define DX_TEST_CASE(func)                                      \
    static int __dx_test_func_##func();                         \
    void __dx_test_reg_##func() {                               \
        static int reg = FALSE;                                 \
        static DX_TEST __node = {#func,                         \
            __dx_test_func_##func};                             \
        if (!reg) {                                             \
            DX_DLL_INSERT(&dx_test_head, &__node,               \
                DX_DLL_FINAL(&dx_test_head));                   \
            reg = TRUE;                                         \
        }                                                       \
    }                                                           \
    static int __dx_test_func_##func(                           \
        int argc, const char *argv,                             \
        LOG_PRINT print, LOG_PARA para)
#define DX_TEST_REG(func)                                       \
    extern void __dx_test_reg_##func();                         \
    __dx_test_reg_##func();


/* 测试入口 */
extern DX_TEST_RESULT *dx_test_main(
    int argc, const char **argv,
    LOG_PRINT print, LOG_PARA para);


#ifdef __cplusplus
}
#endif

#endif // #ifndef _TEST_H_
