#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "hardware/regs/m0plus.h"
#include "hardware/regs/addressmap.h"
#include "typedef.h"

typedef u32 q_thread_id;

typedef struct {
    u32 r[13];
    u32 lr;
    u32 pc;
    u32 xpsr;
} q_thread_context;

typedef enum {
    Q_THREAD_STATE_DORMANT    = 0,
    Q_THREAD_STATE_RUNNING    = 1,
    Q_THREAD_STATE_READY      = 2,
    Q_THREAD_STATE_WAITING    = 3,
    Q_THREAD_STATE_TERMINATED = 4
} q_thread_state;

// スレッド制御ブロック
typedef struct {
    void *context;          // コンテキスト

    struct q_thread_control_block *next; // 次のスレッド
    struct q_thread_control_block *prev; // 前のスレッド

    q_thread_id id;         // スレッド識別子
    q_thread_state state;   // スレッド状態
    u16 priority;           // スレッド優先度
    void *stack_pointer;    // スタックポインタ
    u32 stack_size;         // スタックサイズ

    void* (*threadadr);     // スレッド開始アドレス
} q_thread_control_block;

// ディスパッチャ呼び出し
static inline void *dispatch(void){
    // PendSV例外発生
   *(_u32*)(M0PLUS_ICSR_OFFSET | PPB_BASE) = M0PLUS_ICSR_PENDSVSET_BITS;
}

extern void *make_context(u32 *stackPointer, UINT ssize, void (*startp)());
extern void dispatch_entry(void);

#endif