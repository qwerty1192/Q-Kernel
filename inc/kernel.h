#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "hardware/regs/m0plus.h"
#include "typedef.h"

// typedef u32 q_thread_id;

// typedef enum {
//     THREAD_STATE_CREATED,
//     THREAD_STATE_RUNNING,
//     THREAD_STATE_BLOCKED,
//     THREAD_STATE_TERMINATED
// } q_thread_state;


// typedef enum {
//     THREAD_PRIORITY_LOW,
//     THREAD_PRIORITY_NORMAL,
//     THREAD_PRIORITY_HIGH
// } q_thread_priority;

// // スレッドスタートアップ関数の型
// typedef void (*thread_start_func_t)(void*);

// // スレッド制御ブロック
// typedef struct {
//     q_thread_id id;                 // スレッド識別子
//     q_thread_priority priority;     // スレッド優先度
//     thread_start_func_t start_func; // スレッドスタートアップ関数
//     void* arg;                      // スレッド引数
//     // その他のスレッド情報や状態を格納するメンバー
// } q_thread_control_block;

// ディスパッチャ呼び出し
static inline void dispatch(void){
    // PendSV例外発生
   *(_u32*)M0PLUS_ICSR_OFFSET = M0PLUS_ICSR_PENDSVSET_BITS;
}

extern void *init_context(u32 *stackPointer, UINT ssize, void* (*startp)());

#endif