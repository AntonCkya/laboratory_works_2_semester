#include <stdio.h>
#include "queue.h"

bool queue_transpose(queue *q){
    queue new_q;
    queue_create(&new_q);
    bool is_sorted = true;
    if(queue_is_empty(q)){
        queue_destroy(&new_q);
        return true;
    }
    int f = queue_pop(q);
    if(queue_is_empty(q)){
        queue_destroy(&new_q);
        queue_push(q, f);
        return true;
    }
    int s = queue_pop(q);
    while(!queue_is_empty(q)){
        if(f > s){
            queue_push(&new_q, s);
            s = queue_pop(q);
            is_sorted = false;
        } else {
            queue_push(&new_q, f);
            f = s;
            s = queue_pop(q);
        }
    }
    if(f > s){
        queue_push(&new_q, s);
        queue_push(&new_q, f);
        is_sorted = false;
    } else {
        queue_push(&new_q, f);
        queue_push(&new_q, s);
    }
    while(!queue_is_empty(&new_q)){
        queue_push(q, queue_pop(&new_q));
    }
    queue_destroy(&new_q);
    return is_sorted;
}
void queue_sort(queue *q){
    while(!queue_transpose(q));
}

int main() {
    queue q;
    int num;
    queue_create(&q);
    printf("enter elements to queue\n");
    while(scanf("%d", &num) == 1){
        queue_push(&q, num);
    }
    printf("\nqueue:\n");
    queue_print(&q);
    printf("sorted queue:\n");
    queue_sort(&q);
    queue_print(&q);
    return 0;
}
