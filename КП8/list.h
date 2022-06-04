#ifndef __list_h__
#define __list_h__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct list_elem {
    struct list_elem* next;
    struct list_elem* past;
    T value;
} list_elem;

typedef struct list {
    list_elem* root;
    int size;
} list;

typedef struct iterator {
    list* l;
    list_elem* pos;
} iterator;

bool list_create(list* l);
bool list_delete(list* l);
int list_size(list* l);
bool list_is_empty(list* l);
bool list_insert(iterator* it, T elem, int pos);
bool list_remove(iterator* it, int pos);
void list_print(list* l);
void iter_create(iterator* it, list* l);
void iter_begin(iterator* it);
void iter_end(iterator* it);
bool iter_next(iterator* it);
bool iter_back(iterator* it);
bool iter_move(int n, iterator* it);
T iter_val(iterator* it);

#endif //__list_h__
