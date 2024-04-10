.balign 4
.thumb_func
.global dispatch_entry

dispatch_entry:
    movs    r0, #208        ;# 0xd0
    lsl     r0, r0, #24
    movs    r1, #128        ;# 0x80
    lsl     r1, r1, #18
    str     r1, [r0, #28]   ;# 0x1c
    bx      lr

@     push    {r4-r7}
@     mov     r0, r8
@     mov     r1, r9
@     mov     r2, r10
@     mov     r3, r11
@     push    {r0-r3}

@     ldr     r0, =current_thread
@     ldr     r1, [r0]
@     cmp     r1, #0
@     beq     disp_010

@     ldr     r0, =ctx_table
@     sub     r1, #1
@     lsl     r1, r1, #2
@     mov     r2, sp
@     str     r2, [r0, r1]

@ disp_010:
@     ldr     r0, =next_thread
@     ldr     r1, [r0]
@     ldr     r0, =current_thread
@     str     r1, [r0]

@     ldr     r0, =ctx_table
@     sub     r1, #1
@     lsl     r1, r1, #2
@     ldr     r2, [r1, r0]
@     mov     sp, r2

@     pop     {r0-r3}
@     mov     r8, r0
@     mov     r9, r1
@     mov     r10, r2
@     mov     r11, r3
@     pop     {r4-r7}
@     bx      lr
