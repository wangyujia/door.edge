
/* dx_atomic.h : DoneXԭ����ͷ�ļ�. Combo.xy */

#ifndef _DX_ATOMIC_H_
#define _DX_ATOMIC_H_

#include "dx_type.h"


#ifdef __cplusplus
extern "C" {
#endif


/********************************************************************************
 * CPUԭ����
 ********************************************************************************/
extern  DX_INTPTR   dx_atomic_add(                              /* [����]ԭ����� */
                        DX_INTPTR *addr,                        /* [����]������ַ */
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_sub(                              /* [����]ԭ����� */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_or(                               /* [����]ԭ����� */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_and(                              /* [����]ԭ������ */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_xor(                              /* [����]ԭ������� */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_nand(                             /* [����]ԭ������� */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_set(                              /* [����]ԭ������ֵ */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_BOOL     dx_atomic_cas(                              /* [����]ԭ�ӱȽϽ��� */
                        DX_INTPTR *addr,                        /* [����]������ַ */
                        DX_INTPTR cmp,                          /* [����]�Ƚϵ�ֵ */
                        DX_INTPTR swap);                        /* [����]������ֵ */
extern  DX_INTPTR   dx_atomic_fetch_add(                        /* [����]ԭ�ӻ�ȡֵ����� */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_sub(                        /* [����]ԭ�ӻ�ȡֵ����� */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_or(                         /* [����]ԭ�ӻ�ȡֵ����� */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_and(                        /* [����]ԭ�ӻ�ȡֵ������ */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_xor(                        /* [����]ԭ�ӻ�ȡֵ������� */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_nand(                       /* [����]ԭ�ӻ�ȡֵ������� */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_cas(                        /* [����]ԭ�ӱȽϽ��� */
                        DX_INTPTR *addr,                        /* [����]������ַ */
                        DX_INTPTR cmp,                          /* [����]�Ƚϵ�ֵ */
                        DX_INTPTR swap);                        /* [����]������ֵ */


#ifdef __cplusplus
}
#endif


#endif /* #ifndef _DX_ATOMIC_H_ */
