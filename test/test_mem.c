
/* test_mem.c : 测试内存实现文件. Combo.xy */

#include "test.h"
#include "../src/core/dx_mem.h"


static DX_MEM_HEAD dx_test_mem_used;
static DX_MEM_HEAD dx_test_mem_idle;


static int print_mem_forward(char *info, DX_MEM_HEAD *list, LOG_PRINT print, LOG_PARA para) {
    int count = 0;
    char tmp[256];
    sprintf(tmp, "[%s] forward count: %d\n", info, DX_DLL_COUNT(list));
    if (print) print(tmp, para);
    DX_MEM *p = CONTAINER_OF(DX_DLL_FIRST(list), DX_MEM, node);
    while (p) {
        count++;
        sprintf(tmp, "  addr: %p, offset: %d, size: %d\n", p, p->head.offset, p->head.size);
        if (print) print(tmp, para);
        p = CONTAINER_OF(DX_DLL_NEXT(&p->node), DX_MEM, node);
    }

    sprintf(tmp, "[%s] forward total: %d\n", info, count);
    if (print) print(tmp, para);
    return count;
}


static int print_mem_reverse(char *info, DX_MEM_HEAD *list, LOG_PRINT print, LOG_PARA para) {
    int count = 0;
    char tmp[256];
    sprintf(tmp, "[%s] reverse count: %d\n", info, DX_DLL_COUNT(list));
    if (print) print(tmp, para);
    DX_MEM *q = CONTAINER_OF(DX_DLL_FINAL(list), DX_MEM, node);
    while (q) {
        count++;
        sprintf(tmp, "  addr: %p, offset: %d, size: %d\n", q, q->head.offset, q->head.size);
        if (print) print(tmp, para);
        q = CONTAINER_OF(DX_DLL_PREV(&q->node), DX_MEM, node);
    }

    sprintf(tmp, "[%s] reverse total: %d\n", info, count);
    if (print) print(tmp, para);
    return count;
}


DX_TEST_CASE(mem) {

    dx_mem_head_init(&dx_test_mem_used, &dx_test_mem_idle);

    DX_SIZE l = 102400;
    void *p = malloc(l);
    if (!p) return DX_FAIL;

#define __CHECK(used_count, idle_count) \
    if (used_count != print_mem_forward("used list", &dx_test_mem_used, print, para) || \
        used_count != print_mem_reverse("used list", &dx_test_mem_used, print, para)) \
        return DX_FAIL; \
    if (idle_count != print_mem_forward("idle list", &dx_test_mem_idle, print, para) || \
        idle_count != print_mem_reverse("idle list", &dx_test_mem_idle, print, para)) \
        return DX_FAIL


    dx_mem_node_add(&dx_test_mem_idle, p, l, TRUE, FALSE);
    if (print) print(" *** dx_mem_node_add *** \n", para);
    __CHECK(0, 1); // 0 
    void *p1 = dx_mem_alloc(&dx_test_mem_used, &dx_test_mem_idle, 501);
    if (print) print(" *** dx_mem_alloc p1:501 *** \n", para);
    __CHECK(1, 1); // p1 0
    void *p2 = dx_mem_alloc(&dx_test_mem_used, &dx_test_mem_idle, 251);
    if (print) print(" *** dx_mem_alloc p2:251 *** \n", para);
    __CHECK(2, 1); // p1 p2 0
    void *p3 = dx_mem_alloc(&dx_test_mem_used, &dx_test_mem_idle, 1221);
    if (print) print(" *** dx_mem_alloc p3:1221 *** \n", para);
    __CHECK(3, 1); // p1 p2 p3 0
    dx_mem_free(&dx_test_mem_used, &dx_test_mem_idle, p2);
    if (print) print(" *** dx_mem_free p2 *** \n", para);
    __CHECK(2, 2); // p1 0 p3 0
    void *p4 = dx_mem_alloc(&dx_test_mem_used, &dx_test_mem_idle, 1);
    if (print) print(" *** dx_mem_alloc p4:1 *** \n", para);
    __CHECK(3, 2); // p1 p4 0 p3 0
    dx_mem_free(&dx_test_mem_used, &dx_test_mem_idle, p4);
    if (print) print(" *** dx_mem_free p4 *** \n", para);
    __CHECK(2, 2); // p1 0 p3 0
    dx_mem_free(&dx_test_mem_used, &dx_test_mem_idle, p3);
    if (print) print(" *** dx_mem_free p3 *** \n", para);
    __CHECK(1, 1); // p1 0
    dx_mem_free(&dx_test_mem_used, &dx_test_mem_idle, p1);
    if (print) print(" *** dx_mem_free p1 *** \n", para);
    __CHECK(0, 1); // 0
    p3 = dx_mem_alloc(&dx_test_mem_used, &dx_test_mem_idle, 102400 - sizeof(DX_MEM));
    if (print) print(" *** dx_mem_alloc p3:all *** \n", para);
    __CHECK(1, 0); // p3
    p4 = dx_mem_alloc(&dx_test_mem_used, &dx_test_mem_idle, 5);
    if (p4) return DX_FAIL;
    dx_mem_free(&dx_test_mem_used, &dx_test_mem_idle, p3);
    p4 = dx_mem_alloc(&dx_test_mem_used, &dx_test_mem_idle, 5);
    if (!p4) return DX_FAIL;


#undef __CHECK

    free(p);

    return DX_OK;
}
