.balign 4
.thumb_func
.global dispatch_entry

dispatch_entry:
    mov     r0, #1
    msr     primask, r0
    ldr     r1, =ctx_table
    str     r0, [r1]

    push    {r4-r7}
    mov     r0, r8
    mov     r1, r9
    mov     r2, r10
    mov     r3, r11
    push    {r0-r3}

    ldr     r0, =current_thread
    ldr     r1, [r0]
    cmp     r1, #0
    beq     disp_010

    mov     r2, sp
    str     r2, [r1]

disp_010:
    ldr     r1, =next_thread
    ldr     r2, [r1]
    cmp     r2, #0
    beq     disp_030

    str     r2, [r0]

disp_020:
    mov     r3, #0
    msr     primask, r3
    mov     r3, #1
    msr     primask, r3

    ldr     r2, [r1]
    cmp     r2, #0
    beq     disp_020

disp_030:
    str     r2, [r0]
    ldr     r0, [r2]
    mov     sp, r0

    pop     {r0-r3}
    mov     r8, r0
    mov     r9, r1
    mov     r10, r2
    mov     r11, r3
    pop     {r4-r7}

    ldr     r0, =ctx_table
    mov     r0, #0
    msr     primask, r0
    str     r0, [r1]

    bx      lr