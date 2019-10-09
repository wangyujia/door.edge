
/* test_kernel.c : 测试内核实现文件. Combo.xy */

#include "test.h"
#include "../src/core/dx_kernel.h"


static int dx_test_ready_rs(DX_U8 right, LOG_PRINT print, LOG_PARA para) {
    if (right > DX_PRIO_MAX) right = DX_PRIO_MAX;
    DX_U8 prio = dx_ready_sched();
    char info[256];
    sprintf(info, "  SCHED INDEX: 0x%x\n", dx_prio_sched_index);
    if (print) print(info, para);
    sprintf(info, "sched prio: %d | right: %d\n", prio, right);
    if (print) print(info, para);
    return (prio == right)? DX_OK : DX_FAIL;
}


DX_TEST_CASE(kernel) {

    dx_kernel_para.tick_irq      = dx_tick_irq();
    dx_kernel_para.tick_interval = dx_tick_interval();
    dx_kernel_init(&dx_kernel_para);

    int r = 0;
#define __CHECK(prio) \
    r = dx_test_ready_rs(prio, print, para); \
    if (r != DX_OK) return r


    dx_ready_enter(251);
  __CHECK(251);
    dx_ready_leave(251);
  __CHECK(255);
    dx_ready_enter(15);
    dx_ready_enter(6);
    dx_ready_enter(16);
    dx_ready_leave(15);
    dx_ready_enter(251);
  __CHECK(6);
    dx_ready_enter(252);
  __CHECK(6);
    dx_ready_leave(251);
  __CHECK(6);
    dx_ready_leave(6);
    dx_ready_enter(15);
  __CHECK(15);
    dx_ready_leave(15);
  __CHECK(16);
    dx_ready_enter(5);
  __CHECK(5);
    dx_ready_leave(5);
  __CHECK(16);
    dx_ready_leave(16);
  __CHECK(252);
    dx_ready_leave(252);
  __CHECK(255);
    dx_ready_enter(118);
  __CHECK(118);
    dx_ready_enter(222);
  __CHECK(118);
    dx_ready_leave(118);
  __CHECK(222);


#undef __CHECK

    return DX_OK;
}
