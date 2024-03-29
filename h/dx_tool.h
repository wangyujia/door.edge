
/* dx_tool.h : DoneX工具头文件. Combo.xy */

#ifndef _DX_TOOL_H_
#define _DX_TOOL_H_


#ifdef __cplusplus
extern "C" {
#endif


/********************************************************************************
 * 拷贝字符串 (可替换为CPU汇编)
 ********************************************************************************/
#ifndef DX_STR_N_CPY                                            /* 安全拷贝字符串 */
#define DX_STR_N_CPY(dst, src, max)                             \
    do {                                                        \
        char *__d = (dst); const char *__s = (src);             \
        while (__d && __s && *__s && (max) &&                   \
                __s < (src + (max) - 1)) {                      \
            *__d++ = *__s++;                                    \
        }                                                       \
        if (__d > dst) *__d = 0;                                \
    } while (0)
#endif


/********************************************************************************
 * 双向链表操作
 ********************************************************************************/
#ifndef DX_DLL_HEAD                                             /* 表头 */
#define DX_DLL_HEAD(type)                                       \
    type * __first;                                             \
    type * __final;                                             \
    int    __count
#endif
#ifndef DX_DLL_NODE                                             /* 表节点 */
#define DX_DLL_NODE(type)                                       \
    type *__next;                                               \
    type *__prev
#endif
#ifndef DX_DLL_FIRST                                            /* 开头 */
#define DX_DLL_FIRST(head)      ((head)->__first)
#endif
#ifndef DX_DLL_FINAL                                            /* 最后 */
#define DX_DLL_FINAL(head)      ((head)->__final)
#endif
#ifndef DX_DLL_COUNT                                            /* 数量 */
#define DX_DLL_COUNT(head)      ((head)->__count)
#endif
#ifndef DX_DLL_PREV                                             /* 前一个节点 */
#define DX_DLL_PREV(node)       ((node)->__prev)
#endif
#ifndef DX_DLL_NEXT                                             /* 下一个节点 */
#define DX_DLL_NEXT(node)       ((node)->__next)
#endif
#ifndef DX_DLL_EMPTY                                            /* 是否为空 */
#define DX_DLL_EMPTY(head)      (!DX_DLL_FIRST(head) || !DX_DLL_FINAL(head) || !DX_DLL_COUNT(head))
#endif
#ifndef DX_DLL_INIT                                             /* 初始化头 */
#define DX_DLL_INIT(head)                                       \
    do {                                                        \
        DX_DLL_FIRST(head) = 0;                                 \
        DX_DLL_FINAL(head)  = 0;                                \
        DX_DLL_COUNT(head) = 0;                                 \
    } while (0)
#endif
#ifndef DX_DLL_NODE_INIT                                        /* 初始化节点 */
#define DX_DLL_NODE_INIT(node)                                  \
    do {                                                        \
        DX_DLL_NEXT(node) = 0;                                  \
        DX_DLL_PREV(node) = 0;                                  \
    } while (0)
#endif
#ifndef DX_DLL_INSERT                                           /* 插入 */
#define DX_DLL_INSERT(head, node, where)                        \
    do {                                                        \
        if (DX_DLL_EMPTY(head)) {                               \
            DX_DLL_NEXT(node) = 0;                              \
            DX_DLL_PREV(node) = 0;                              \
            DX_DLL_FIRST(head) = (node);                        \
            DX_DLL_FINAL(head) = (node);                        \
        } else if (!(where)) {                                  \
            DX_DLL_NEXT(node) = DX_DLL_FIRST(head);             \
            DX_DLL_PREV(node) = 0;                              \
            DX_DLL_PREV(DX_DLL_FIRST(head)) = (node);           \
            DX_DLL_FIRST(head) = (node);                        \
        } else {                                                \
            DX_DLL_NEXT(node) = DX_DLL_NEXT(where);             \
            DX_DLL_PREV(node) = (where);                        \
            if (DX_DLL_NEXT(where))                             \
                DX_DLL_PREV(DX_DLL_NEXT(where)) = (node);       \
            DX_DLL_NEXT(where) = (node);                        \
            if ((where) == DX_DLL_FINAL(head))                  \
                DX_DLL_FINAL(head) = (node);                    \
        }                                                       \
        DX_DLL_COUNT(head)++;                                   \
    } while (0)
#endif
#ifndef DX_DLL_REMOVE                                           /* 移除 */
#define DX_DLL_REMOVE(head, node)                               \
    do {                                                        \
        if (DX_DLL_EMPTY(head)) break;                          \
        if (DX_DLL_NEXT(node))                                  \
            DX_DLL_PREV(DX_DLL_NEXT(node)) = DX_DLL_PREV(node); \
        if (DX_DLL_PREV(node))                                  \
            DX_DLL_NEXT(DX_DLL_PREV(node)) = DX_DLL_NEXT(node); \
        if (DX_DLL_FIRST(head) == (node))                       \
            DX_DLL_FIRST(head) = DX_DLL_NEXT(node);             \
        if (DX_DLL_FINAL(head) == (node))                       \
            DX_DLL_FINAL(head) = DX_DLL_PREV(node);             \
        DX_DLL_NEXT(node) = 0;                                  \
        DX_DLL_PREV(node) = 0;                                  \
        DX_DLL_COUNT(head)--;                                   \
    } while (0)
#endif
#ifndef DX_DLL_CLEAR                                            /* 清除 */
#define DX_DLL_CLEAR(head, type, free)                          \
    do {                                                        \
        type *__node_loop = DX_DLL_FIRST(head);                 \
        while (__node_loop) {                                   \
            type *__node_free = __node_loop;                    \
            __node_loop = DX_DLL_NEXT(__node_loop);             \
            free(__node_free);                                  \
        }                                                       \
        DX_DLL_INIT(head);                                      \
    } while (0)
#endif


#ifdef __cplusplus
}
#endif


#endif /* #ifndef _DX_TOOL_H_ */
