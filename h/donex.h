
/* donex.h : DoneX�ܹ���ͷ�ļ�. */

#ifndef _DONEX_H_
#define _DONEX_H_

/********************************************************************************
 * ��ӭʹ������(DoneX)����ϵͳ(R) !
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
 * �߳���ؽӿ� (�����Ϊ'����)
 ********************************************************************************/
extern  void *      dx_task_create (const char *name,           /* �������� */
                                    void (*entry)(void *para),
                                    int   stack_size,
                                    int   priority,
                                    void *para);
extern  void        dx_task_destroy(void *handle);              /* ɾ������ */
extern  int         dx_task_suspend(void *handle);              /* �������� */
extern  int         dx_task_resume (void *handle);              /* �ָ����� */
extern  void        dx_task_delay  (int milliseconds);          /* �ӳ����� */
extern  int         dx_task_current();                          /* ��ǰ���� */


/********************************************************************************
 * �����ź�����ؽӿ� (�����Ϊ'����)
 ********************************************************************************/
extern  void *      dx_lock_create ();                           /* ���������� */
extern  void        dx_lock_destroy(void *handle);              /* ɾ�������� */
extern  void        dx_lock_enter  (void *handle);              /* ���뻥���� */
extern  void        dx_lock_leave  (void *handle);              /* �˳������� */


/********************************************************************************
 * �������ź�����ؽӿ� (�����Ϊ'�¼���)
 ********************************************************************************/
extern  void *      dx_event_create (int   value);              /* �����¼��� */
extern  void        dx_event_destroy(void *handle);             /* ɾ���¼��� */
extern  void        dx_event_send   (void *handle);             /* �����¼��� */
extern  void        dx_event_recv   (void *handle,              /* �����¼��� */
                                     int   milliseconds);
extern  void        dx_event_clear  (void *handle);             /* ����¼��� */


/********************************************************************************
 * �����ź�����ؽӿ� (�����Ϊ'��������)
 ********************************************************************************/
extern  void *      dx_counter_create (int   init_value,        /* ���������� */
                                       int   max_value);
extern  void        dx_counter_destroy(void *handle);           /* ɾ�������� */
extern  void        dx_counter_take   (void *handle,            /* ��ȡ������ */
                                       int   milliseconds);
extern  void        dx_counter_recv   (void *handle,            /* �ͷż����� */
                                       int   count);
extern  int         dx_counter_count  (void *handle);           /* ��ȡ������ */


/********************************************************************************
 * �ж���ؽӿ�
 ********************************************************************************/
extern  void        dx_isr_connect   (int irq,                  /* �жϷ������ҽ� */
                                      VOIDFUNC isr);
extern  void        dx_isr_disconnect(int irq);                 /* �жϷ�������� */


#ifdef __cplusplus
}
#endif


#endif /* #ifndef _DONEX_H_ */
