#include <stdio.h>
#include <stdbool.h>
#include "queue.h"

void queue_create (queue *q){
    q->first = 0;
    q->size = 0;
}
void queue_destroy(queue *q){
    queue_create(q);
}
int queue_size(queue *q){
    return q->size;
}
bool queue_is_empty(queue *q){
    return (q->size == 0);
}
bool queue_push(queue *q, int elem){
    if(q->size >= buffer_size)
        return false;
    q->buffer[(q->first + q->size) % buffer_size] = elem;
    q->size++;
    return true;
}
int queue_pop(queue *q){
    if (!queue_is_empty(q)){
        int elem = q->buffer[q->first];
        q->first++;
        q->size--;
        return elem;
    }
    return -1;
}
void queue_print(queue *q){
    for(int i = q->first; i < q->first + q->size; i++){
        printf("%d ", q->buffer[i % buffer_size]);
    }
    printf("\n");
}
