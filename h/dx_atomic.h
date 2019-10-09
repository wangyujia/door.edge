
/* dx_atomic.h : DoneX原子锁头文件. Combo.xy */

#ifndef _DX_ATOMIC_H_
#define _DX_ATOMIC_H_

#include "dx_type.h"


#ifdef __cplusplus
extern "C" {
#endif


/********************************************************************************
 * CPU原子锁
 ********************************************************************************/
extern  DX_INTPTR   dx_atomic_add(                              /* [函数]原子相加 */
                        DX_INTPTR *addr,                        /* [输入]变量地址 */
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_sub(                              /* [函数]原子相减 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_or(                               /* [函数]原子相或 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_and(                              /* [函数]原子相与 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_xor(                              /* [函数]原子相异或 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_nand(                             /* [函数]原子相与非 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_set(                              /* [函数]原子设置值 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_BOOL     dx_atomic_cas(                              /* [函数]原子比较交换 */
                        DX_INTPTR *addr,                        /* [输入]变量地址 */
                        DX_INTPTR cmp,                          /* [输入]比较的值 */
                        DX_INTPTR swap);                        /* [输入]交换的值 */
extern  DX_INTPTR   dx_atomic_fetch_add(                        /* [函数]原子获取值后相加 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_sub(                        /* [函数]原子获取值后相减 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_or(                         /* [函数]原子获取值后相或 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_and(                        /* [函数]原子获取值后相与 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_xor(                        /* [函数]原子获取值后相异或 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_nand(                       /* [函数]原子获取值后相与非 */
                        DX_INTPTR *addr,
                        DX_INTPTR  val);
extern  DX_INTPTR   dx_atomic_fetch_cas(                        /* [函数]原子比较交换 */
                        DX_INTPTR *addr,                        /* [输入]变量地址 */
                        DX_INTPTR cmp,                          /* [输入]比较的值 */
                        DX_INTPTR swap);                        /* [输入]交换的值 */


#ifdef __cplusplus
}
#endif


#endif /* #ifndef _DX_ATOMIC_H_ */
