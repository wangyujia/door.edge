
/* dx_config.h : DoneX����ͷ�ļ�. Combo.xy */

#ifndef _DX_CONFIG_H_
#define _DX_CONFIG_H_


/********************************************************************************
 * [����] DX_SCHED_WAY : �ں����з�ʽ
 * 
 *  CPU����: ��������CPU���㣬�����ٶ��ڴ������,
 *           ���Խ�Լ�ڴ�, ��CPU�������;
 *  MEM����: ���������ڴ滺��, �����ٶ�CPU������,
 *           ���Լ���CPU����, ���ڴ�ռ�ø�;
 *  �Զ�����: �ҵ��м��ƽ��㣬�Զ�ʹ��
 ********************************************************************************/
#define DX_FIRST_AUT        0
#define DX_FIRST_MEM        1
#define DX_FIRST_CPU        2

#ifndef DX_SCHED_WAY
#define DX_SCHED_WAY        DX_FIRST_AUT /* DX_FIRST_AUT DX_FIRST_MEM DX_FIRST_CPU */
#endif
#if     DX_SCHED_WAY >      DX_FIRST_CPU
#error 'DX_SCHED_WAY' config error!
#endif
/********************************************************************************/


/********************************************************************************
 * [����] DX_PRIO_MAX : ������ȼ�
 ********************************************************************************/
#ifndef DX_PRIO_MAX
#define DX_PRIO_MAX         255 /* 63 127 255 */
#endif
#if     DX_PRIO_MAX >       255
#error 'DX_PRIO_MAX' defined error!
#endif
/********************************************************************************/


/********************************************************************************
 * [����] DX_CPU_MAX : CPU Core������ (ʵ�ʸ���������ӿڷ���)
 ********************************************************************************/
#ifndef DX_CPU_MAX                                              /* CPU������ */
#define DX_CPU_MAX          1
#endif
#ifndef DX_CPU_BITS                                             /* CPUλ�� */
#define DX_CPU_BITS         32                                  /* 8 16 32 64 */
#endif
/********************************************************************************/


/********************************************************************************
 * [����] DX_INT_MAX : �ж�������
 ********************************************************************************/
#ifndef DX_INT_MAX
#define DX_INT_MAX          16
#endif
/********************************************************************************/


/********************************************************************************
 * [����] ��������
 ********************************************************************************/
#ifndef DX_TASK_NAME_MAX                                        /* ����������󳤶� */
#define DX_TASK_NAME_MAX    16                                  /* (��ʹ���������־���Ϊ0) */
#endif
#ifndef DX_TASK_VAR_MAX                                         /* �������������� */
#define DX_TASK_VAR_MAX     8                                   /* (��ʹ�������������Ϊ0) */
#endif
/********************************************************************************/


#endif /* #ifndef _DX_CONFIG_H_ */