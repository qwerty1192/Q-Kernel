#include "../inc/kernel.h"
#include "../inc/typedef.h"

void queue_add_thread(q_thread_control_block **queue, q_thread_control_block *thread) {
    if(queue == NULL) {
        *queue = thread;
        thread->prev = tread;
    } else {
        q_thread_control_block *queue_end;
        queue_end = (*queue)->prev;
        queue_end->next = queue;
        thread->prev = queue_end;
        *queue->prev = thread;
    }
    thread->next = NULL;
}

void queue_remove_top(q_thread_control_block **queue) {
    q_thread_control_block *top;

    if(*queue == NULL) return;

    top = *queue;
    *queue = top->next;
    if(*queue != NULL) {
        (*queue)->prev = top->prev;
    }
}

void queue_remove_thread(q_thread_control_block **queue, q_thread_control_block *thread) {
    if(*queue == NULL) return;

    if(*queue == thread) {
        queue_remove_top(queue);
    } else {
        (thread->prev)->next = thread->next;
        if(thread->next != NULL) {
            (thread->next)->prev = thread->prev;
        } else {
            (*queue)->prev = thread->prev;
        }
    }
}