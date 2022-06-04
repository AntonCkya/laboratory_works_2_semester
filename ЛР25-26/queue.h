#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
#define buffer_size 1024

typedef struct {
    int size;
    int first;
    int buffer[buffer_size];
} queue; 
void queue_create (queue *q);
void queue_destroy(queue *q);
int queue_size(queue *q);
bool queue_is_empty(queue *q);
bool queue_push(queue *q, int elem);
int queue_pop(queue *q);
int queue_peek(queue *q);
void queue_print(queue *q);

#endif //QUEUE_H
