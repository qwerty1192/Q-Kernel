#include "inc/kernel.h"
#include "inc/typedef.h"

#include "pico/stdlib.h"
#include "hardware/exception.h"

u32 stack1[1024];
u32 stack2[1024];

uint current_thread = 0;
uint next_thread = 0;

void* ctx_table[2];

void thread1(void){
    while(1){
        gpio_put(25, 1);
        sleep_ms(500);

        next_thread = 2;
        dispatch();
    }
}

void thread2(void){
    while(1){
        gpio_put(25, 0);
        sleep_ms(500);

        next_thread = 1;
        dispatch();
    }
}

int main(){
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    // ctx_table[0] = init_context(stack1, sizeof(stack1), thread1);
    // ctx_table[1] = init_context(stack2, sizeof(stack2), thread2);

    dispatch_entry();
    sleep_ms(500);
    dispatch_entry();

    exception_set_exclusive_handler(-2, dispatch_entry);

    // next_thread = 1;

    while(1){
        dispatch();
        sleep_ms(500);
    }
}