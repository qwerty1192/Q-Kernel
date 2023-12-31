#include "../inc/typedef.h"

typedef struct {
    u32 r[13];
    u32 lr;
    u32 pc;
    u32 xpsr;
} Context;

void *make_context(u32 *stackPointer, UINT ssize, void* (*startp)()){
    Context *ctx;
    ctx = (Context*)((u32)stackPointer + ssize);
    ctx--;
    ctx->pc = (u32)startp & ~0x00000001UL;
    ctx->xpsr = 0x01000000;

    return (void*)ctx;
}