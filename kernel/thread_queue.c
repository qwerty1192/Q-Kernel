#include "../inc/kernel.h"
#include "../inc/typedef.h"

void queue_add_thread(q_thread_control_block **queue, q_thread_control_block *thread) {
    // Add a thread to the thread queue
    if(queue == NULL) {
        *queue = thread;
        thread->prev = NULL;
    } else {
        thread->next = queue->next;
        thread->prev = queue;
        queue->next->prev = thread;
        queue->next = thread;
    }
    thread->next = NULL;
}

void queue_remove_thread(q_thread_control_block *thread) {
    // Remove a thread from the thread queue
    if(thread->prev != NULL) {
        thread->prev->next = thread->next;
    }
    if(thread->next != NULL) {
        thread->next->prev = thread->prev;
    }
    thread->next = NULL;
    thread->prev = NULL;
}