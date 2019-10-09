
/* dx_mem.h : DoneX�ڴ����ͷ�ļ�. Combo.xy */

#ifndef _DX_MEM_H_
#define _DX_MEM_H_

#include "../../h/donex.h"
#include "dx_kernel.h"


#ifdef __cplusplus
extern "C" {
#endif


/********************************************************************************
 * �ڴ��������ڵ�
 ********************************************************************************/
typedef struct DX_MEM_NODE_S {
    DX_DLL_NODE(struct DX_MEM_NODE_S);
} DX_MEM_NODE;


/********************************************************************************
 * �ڴ���б�
 ********************************************************************************/
typedef struct DX_MEM_HEAD_S {
    DX_DLL_HEAD(DX_MEM_NODE);
} DX_MEM_HEAD;


/********************************************************************************
 * �ڴ�������
 ********************************************************************************/
typedef struct DX_MEM_S {
    DX_OBJ              head;                                   /* �������� */
    DX_MEM_NODE         node;                                   /* �ڴ���нڵ� */
    DX_BOOL             used;                                   /* �ڴ�ʹ��״̬ */
    DX_U8               reserved[3];                            /* ���� */
} DX_MEM;


/********************************************************************************
 * �ڴ�����ӿ�
 ********************************************************************************/
extern  void            dx_mem_head_init(                       /* [����]���г�ʼ�� */
                            DX_MEM_HEAD *used_list,             /* [����]ʹ�ö��� */
                            DX_MEM_HEAD *idle_list);            /* [����]���ж��� */
extern  DX_MEM *        dx_mem_node_init(                       /* [����]�ڵ��ʼ�� */
                            void *addr, DX_SIZE size,           /* [����]��ַ�ʹ�С*/
                            DX_BOOL used);                      /* [����]�Ƿ�ʹ�� */
extern  void            dx_mem_node_add(                        /* [����]����ڴ�ڵ� */
                            DX_MEM_HEAD *list,                  /* [����]���� */
                            void *addr, DX_SIZE size,           /* [����]��ַ�ʹ�С */
                            DX_BOOL merge,                      /* [����]�Ƿ�ϲ� */
                            DX_BOOL used);                      /* [����]�Ƿ�ʹ�� */
extern  void            dx_mem_node_del(                        /* [����]ɾ���ڴ�ڵ� */
                            DX_MEM_HEAD *list,                  /* [����]���� */
                            DX_MEM *mem, DX_SIZE size,          /* [����]�ڴ�ʹ�С */
                            DX_BOOL split,                      /* [����]�Ƿ��з� */
                            DX_BOOL used);                      /* [����]�Ƿ�ʹ�� */
extern  void *          dx_mem_alloc(                           /* [����]�ڴ���� */
                            DX_MEM_HEAD *used_list,             /* [����]ʹ�ö��� */
                            DX_MEM_HEAD *idle_list,             /* [����]���ж��� */
                            DX_SIZE size);                      /* [����]��Ҫ�Ĵ�С */
extern  void            dx_mem_free(                            /* [����]�ڴ��ͷ� */
                            DX_MEM_HEAD *used_list,             /* [����]ʹ�ö��� */
                            DX_MEM_HEAD *idle_list,             /* [����]���ж��� */
                            void *addr);                        /* [����]�ͷŵĵ�ַ */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef _DX_MEM_H_ */
