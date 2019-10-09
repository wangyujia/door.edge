
/* donex.h : DoneX总公共头文件. */

#ifndef _DONEX_H_
#define _DONEX_H_

/********************************************************************************
 * 欢迎使用龙骑(DoneX)操作系统(R) !
 *  DoneX (DrgoON EXpress) : Distributed Operating Network Edge X !
 *                                                2009-2019 Combo.xy Copyright(C)
 ********************************************************************************/

#include "dx_config.h"
#include "dx_type.h"
#include "dx_error.h"
#include "dx_tool.h"
#include "dx_adapt.h"


#ifdef __cplusplus
extern "C" {
#endif


/********************************************************************************
 * 线程相关接口 (这里称为'任务‘)
 ********************************************************************************/
extern  void *      dx_task_create (const char *name,           /* 创建任务 */
                                    void (*entry)(void *para),
                                    int   stack_size,
                                    int   priority,
                                    void *para);
extern  void        dx_task_destroy(void *handle);              /* 删除任务 */
extern  int         dx_task_suspend(void *handle);              /* 挂起任务 */
extern  int         dx_task_resume (void *handle);              /* 恢复任务 */
extern  void        dx_task_delay  (int milliseconds);          /* 延迟任务 */
extern  int         dx_task_current();                          /* 当前任务 */


/********************************************************************************
 * 互斥信号量相关接口 (这里称为'锁‘)
 ********************************************************************************/
extern  void *      dx_lock_create ();                           /* 创建互斥锁 */
extern  void        dx_lock_destroy(void *handle);              /* 删除互斥锁 */
extern  void        dx_lock_enter  (void *handle);              /* 进入互斥锁 */
extern  void        dx_lock_leave  (void *handle);              /* 退出互斥锁 */


/********************************************************************************
 * 二进制信号量相关接口 (这里称为'事件‘)
 ********************************************************************************/
extern  void *      dx_event_create (int   value);              /* 创建事件量 */
extern  void        dx_event_destroy(void *handle);             /* 删除事件量 */
extern  void        dx_event_send   (void *handle);             /* 发送事件量 */
extern  void        dx_event_recv   (void *handle,              /* 接收事件量 */
                                     int   milliseconds);
extern  void        dx_event_clear  (void *handle);             /* 清除事件量 */


/********************************************************************************
 * 计数信号量相关接口 (这里称为'计数器‘)
 ********************************************************************************/
extern  void *      dx_counter_create (int   init_value,        /* 创建计数器 */
                                       int   max_value);
extern  void        dx_counter_destroy(void *handle);           /* 删除计数器 */
extern  void        dx_counter_take   (void *handle,            /* 获取计数器 */
                                       int   milliseconds);
extern  void        dx_counter_recv   (void *handle,            /* 释放计数器 */
                                       int   count);
extern  int         dx_counter_count  (void *handle);           /* 获取计数器 */


/********************************************************************************
 * 中断相关接口
 ********************************************************************************/
extern  void        dx_isr_connect   (int irq,                  /* 中断服务程序挂接 */
                                      VOIDFUNC isr);
extern  void        dx_isr_disconnect(int irq);                 /* 中断服务程序解除 */


#ifdef __cplusplus
}
#endif


#endif /* #ifndef _DONEX_H_ */
