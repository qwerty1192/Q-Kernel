#include "inc/kernel.h"
#include "inc/typedef.h"

#include "pico/stdlib.h"

u32 stack1[1024];
u32 stack2[1024];

uint current_thread = 0;
uint next_thread = 0;

void* ctx_table[2];

void thread1(void){
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
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
    ctx_table[0] = init_context(stack1, sizeof(stack1), thread1);
    ctx_table[1] = init_context(stack2, sizeof(stack2), thread2);



    next_thread = 1;
    dispatch();

    while(1);
}