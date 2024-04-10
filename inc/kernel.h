#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "hardware/regs/m0plus.h"
#include "typedef.h"

typedef u32 q_thread_id;

// typedef enum {
//     THREAD_STATE_CREATED,
//     THREAD_STATE_RUNNING,
//     THREAD_STATE_BLOCKED,
//     THREAD_STATE_TERMINATED
// } q_thread_state;

// // スレッド制御ブロック
// typedef struct {
//     q_thread_id id;         // スレッド識別子
//     u16 priority;           // スレッド優先度
//     q_thread_state state;   // スレッド状態
//     void* stack_pointer;    // スタックポインタ
//     u32 stack_size;         // スタックサイズ

//     void* (*threadadr);     // スレッド開始アドレス
// } q_thread_control_block;

// ディスパッチャ呼び出し
static inline void *dispatch(void){
    // PendSV例外発生
   *(_u32*)(M0PLUS_ICSR_OFFSET | 0xe0000000) = M0PLUS_ICSR_PENDSVSET_BITS;
}

extern void *init_context(u32 *stackPointer, UINT ssize, void (*startp)());
extern void dispatch_entry(void);

#endif