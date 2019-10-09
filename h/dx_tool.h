
/* dx_tool.h : DoneX����ͷ�ļ�. Combo.xy */

#ifndef _DX_TOOL_H_
#define _DX_TOOL_H_


#ifdef __cplusplus
extern "C" {
#endif


/********************************************************************************
 * �����ַ��� (���滻ΪCPU���)
 ********************************************************************************/
#ifndef DX_STR_N_CPY                                            /* ��ȫ�����ַ��� */
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
 * ˫���������
 ********************************************************************************/
#ifndef DX_DLL_HEAD                                             /* ��ͷ */
#define DX_DLL_HEAD(type)                                       \
    type * __first;                                             \
    type * __final;                                             \
    int    __count
#endif
#ifndef DX_DLL_NODE                                             /* ��ڵ� */
#define DX_DLL_NODE(type)                                       \
    type *__next;                                               \
    type *__prev
#endif
#ifndef DX_DLL_FIRST                                            /* ��ͷ */
#define DX_DLL_FIRST(head)      ((head)->__first)
#endif
#ifndef DX_DLL_FINAL                                            /* ��� */
#define DX_DLL_FINAL(head)      ((head)->__final)
#endif
#ifndef DX_DLL_COUNT                                            /* ���� */
#define DX_DLL_COUNT(head)      ((head)->__count)
#endif
#ifndef DX_DLL_PREV                                             /* ǰһ���ڵ� */
#define DX_DLL_PREV(node)       ((node)->__prev)
#endif
#ifndef DX_DLL_NEXT                                             /* ��һ���ڵ� */
#define DX_DLL_NEXT(node)       ((node)->__next)
#endif
#ifndef DX_DLL_EMPTY                                            /* �Ƿ�Ϊ�� */
#define DX_DLL_EMPTY(head)      (!DX_DLL_FIRST(head) || !DX_DLL_FINAL(head) || !DX_DLL_COUNT(head))
#endif
#ifndef DX_DLL_INIT                                             /* ��ʼ��ͷ */
#define DX_DLL_INIT(head)                                       \
    do {                                                        \
        DX_DLL_FIRST(head) = 0;                                 \
        DX_DLL_FINAL(head)  = 0;                                \
        DX_DLL_COUNT(head) = 0;                                 \
    } while (0)
#endif
#ifndef DX_DLL_NODE_INIT                                        /* ��ʼ���ڵ� */
#define DX_DLL_NODE_INIT(node)                                  \
    do {                                                        \
        DX_DLL_NEXT(node) = 0;                                  \
        DX_DLL_PREV(node) = 0;                                  \
    } while (0)
#endif
#ifndef DX_DLL_INSERT                                           /* ���� */
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
#ifndef DX_DLL_REMOVE                                           /* �Ƴ� */
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
#ifndef DX_DLL_CLEAR                                            /* ��� */
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
