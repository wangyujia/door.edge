
/* dx_mem.h : DoneX内存管理头文件. Combo.xy */

#ifndef _DX_MEM_H_
#define _DX_MEM_H_

#include "../../h/donex.h"
#include "dx_kernel.h"


#ifdef __cplusplus
extern "C" {
#endif


/********************************************************************************
 * 内存队列链表节点
 ********************************************************************************/
typedef struct DX_MEM_NODE_S {
    DX_DLL_NODE(struct DX_MEM_NODE_S);
} DX_MEM_NODE;


/********************************************************************************
 * 内存队列表
 ********************************************************************************/
typedef struct DX_MEM_HEAD_S {
    DX_DLL_HEAD(DX_MEM_NODE);
} DX_MEM_HEAD;


/********************************************************************************
 * 内存描述块
 ********************************************************************************/
typedef struct DX_MEM_S {
    DX_OBJ              head;                                   /* 对象描述 */
    DX_MEM_NODE         node;                                   /* 内存队列节点 */
    DX_BOOL             used;                                   /* 内存使用状态 */
    DX_U8               reserved[3];                            /* 保留 */
} DX_MEM;


/********************************************************************************
 * 内存操作接口
 ********************************************************************************/
extern  void            dx_mem_head_init(                       /* [函数]队列初始化 */
                            DX_MEM_HEAD *used_list,             /* [输入]使用队列 */
                            DX_MEM_HEAD *idle_list);            /* [输入]空闲队列 */
extern  DX_MEM *        dx_mem_node_init(                       /* [函数]节点初始化 */
                            void *addr, DX_SIZE size,           /* [输入]地址和大小*/
                            DX_BOOL used);                      /* [输入]是否使用 */
extern  void            dx_mem_node_add(                        /* [函数]添加内存节点 */
                            DX_MEM_HEAD *list,                  /* [输入]队列 */
                            void *addr, DX_SIZE size,           /* [输入]地址和大小 */
                            DX_BOOL merge,                      /* [输入]是否合并 */
                            DX_BOOL used);                      /* [输入]是否使用 */
extern  void            dx_mem_node_del(                        /* [函数]删除内存节点 */
                            DX_MEM_HEAD *list,                  /* [输入]队列 */
                            DX_MEM *mem, DX_SIZE size,          /* [输入]内存和大小 */
                            DX_BOOL split,                      /* [输入]是否切分 */
                            DX_BOOL used);                      /* [输入]是否使用 */
extern  void *          dx_mem_alloc(                           /* [函数]内存分配 */
                            DX_MEM_HEAD *used_list,             /* [输入]使用队列 */
                            DX_MEM_HEAD *idle_list,             /* [输入]空闲队列 */
                            DX_SIZE size);                      /* [输入]需要的大小 */
extern  void            dx_mem_free(                            /* [函数]内存释放 */
                            DX_MEM_HEAD *used_list,             /* [输入]使用队列 */
                            DX_MEM_HEAD *idle_list,             /* [输入]空闲队列 */
                            void *addr);                        /* [输入]释放的地址 */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef _DX_MEM_H_ */
