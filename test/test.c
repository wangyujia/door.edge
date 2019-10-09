
/* test.c : 测试实现文件. Combo.xy */

#include "test.h"


/* 测试头 */
DX_TEST_HEAD dx_test_head;


/* 测试入口 */
DX_TEST_RESULT *dx_test_main(
    int argc, const char **argv,
    LOG_PRINT print, LOG_PARA para)
{
    DX_TEST_REG(kernel);
    DX_TEST_REG(mem);

    static DX_TEST_RESULT result;
    result.count  = 0;
    result.failed = 0;
    result.name   = 0;

    DX_TEST *p = DX_DLL_FIRST(&dx_test_head);
    while (p) {
        result.count++;
        DX_TEST_FUNC f = p->func;
        const char *nm = p->name;
        p = DX_DLL_NEXT(p);
        if (!f) continue;

        if (print) print("------------------------------------ \n", para);
        int r = f(argc, argv, print, para);
        if (!r) continue;

        result.failed++;
        if (!result.name) result.name = nm;
    }

    return &result;
}
