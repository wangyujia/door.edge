
/* dx_type.h : DoneX����ͷ�ļ�. combo.xy 2009-10-16 10:33:20 Home */

#ifndef _DX_TYPE_H_
#define _DX_TYPE_H_

#include "dx_config.h"


/********************************************************************************
 * �������Ͷ���
 ********************************************************************************/
typedef unsigned char       DX_BOOL;

typedef signed   char       DX_S8;
typedef unsigned char       DX_U8;

typedef signed   short      DX_S16;
typedef unsigned short      DX_U16;

typedef signed   int        DX_S32;
typedef unsigned int        DX_U32;

typedef signed   long long  DX_S64;
typedef unsigned long long  DX_U64;

typedef float               DX_F32;
typedef double              DX_F64;


#if     DX_CPU_BITS == 8
#define DX_SIZE             DX_U8
#define DX_INTPTR           DX_U8
#define DX_ARG              DX_U8
#define DX_ALIGN            0
#elif   DX_CPU_BITS == 16
#define DX_SIZE             DX_U16
#define DX_INTPTR           DX_U16
#define DX_ARG              DX_U16
#define DX_ALIGN            0x1
#elif   DX_CPU_BITS == 32
#define DX_SIZE             DX_U32
#define DX_INTPTR           DX_U32
#define DX_ARG              DX_U32
#define DX_ALIGN            0x3
#elif   DX_CPU_BITS == 64
#define DX_SIZE             DX_U64
#define DX_INTPTR           DX_U64
#define DX_ARG              DX_U64
#define DX_ALIGN            0x7
#else
#error 'DX_CPU_BITS' defined error!
#endif


#ifndef NULL
#define NULL                (void *)0
#endif
#ifndef TRUE
#define TRUE                1
#endif
#ifndef FALSE
#define FALSE               0
#endif

typedef void                (*VOIDFUNC)(void);
/********************************************************************************/


/********************************************************************************
 * ��ȡ���鳤��
 ********************************************************************************/
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a)       (sizeof(a)/sizeof((a)[0]))
#endif

/* ��ȡ���ֵ */
#ifndef MAX
#define MAX(a, b)           (((a) > (b))? (a) : (b))
#endif

/* ��ȡ��Сֵ */
#ifndef MIN
#define MIN(a, b)           (((a) < (b))? (a) : (b))
#endif

/* ������������ */
#ifndef SWAP
#define SWAP(a, b)          ((a) ^= (b) ^= (a) ^= (b))
#endif

/* �ṹ�г�Աƫ�� */
#ifndef OFFSET_OF
#define OFFSET_OF(t, m)     ((int)&(((t *)0)->m))
#endif

/* �ṹ�г�Ա��С */
#ifndef SIZE_OF
#define SIZE_OF(t, m)       (sizeof(((t *)0)->m))
#endif

/* ͨ����Ա��ȡ�ṹ��ָ�� */
#ifndef CONTAINER_OF
#define CONTAINER_OF(p, t, m) ((p)?((t *)((char *)p - OFFSET_OF(t, m))):0)
#endif

/* ��CPUλ����� */
#if DX_CPU_BITS == 8
#define ALIGN_OF(v)         (v)
#else
#define ALIGN_OF(v)         (((v)&DX_ALIGN)?(((v)&(~DX_ALIGN))+(DX_ALIGN+1)):(v))
#endif


/********************************************************************************
 * ��־��ӡ�ӿ�
 ********************************************************************************/
typedef void  (*LOG_PRINT)(const char *info, void *para);
typedef void *  LOG_PARA;


#endif /* #ifndef _DX_TYPE_H_ */
