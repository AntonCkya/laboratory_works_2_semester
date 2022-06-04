#include "list.h"

bool list_create(list* l) {
    if ((l->root = malloc(sizeof(T))) == NULL) {
        return false;
    }
    l->root->next = NULL;
    l->root->past = NULL;
    l->size = 0;
    return true;
}

bool list_delete(list* l){
    if(list_size(l) <= 0){
        return true;
    }
    if(list_size(l) == 1){
        free(l->root);
        if ((l->root = malloc(sizeof(T))) == NULL) {
            return false;
        }
        l->root->next = NULL;
        l->root->past = NULL;
        l->size = 0;
        return true;
    }
    iterator it;
    iter_create(&it, l);
    iter_next(&it);
    for(int i = 1; i < list_size(l); i++){
        free(it.pos->past);
    }
    free(it.pos);
    if ((l->root = malloc(sizeof(T))) == NULL) {
        return false;
    }
    l->root->next = NULL;
    l->root->past = NULL;
    l->size = 0;
    return true;
}

int list_size(list* l) {
    return l->size;
}

bool list_is_empty(list* l) {
    return list_size(l) == 0;
}

bool list_insert(iterator* it, T elem, int pos) {
    if(pos < 0)
        return false;
    if(list_size(it->l) == 0){
        list_elem* new = NULL;
        if ((new = malloc(sizeof(T))) == NULL) {
            iter_begin(it);
            return false;
        }
        new->next = NULL;
        new->past = NULL;
        new->value = elem;
        it->l->root->past = new;
        it->l->root = new;
        it->l->size++;
        iter_begin(it);
        return true;
    }
    for(int i = 0; i < pos - 1; i++){
        if (!iter_next(it)) {
            iter_begin(it);
            return false;
        }
    }
    list_elem* new = NULL;
    if ((new = malloc(sizeof(T))) == NULL) {
        iter_begin(it);    
        return false;
    }
    new->value = elem;
    new->past = NULL;
    if (list_size(it->l) == pos) {
        new->next = NULL;
        iter_back(it);
        it->pos->next = new;
        it->l->size++;
        iter_begin(it);
        return true;
    }
    if(pos == 0){
        new->next = it->pos;
        new->past = NULL;
        it->l->root = new;
        it->l->size++;
        it->pos->past = new;
        iter_begin(it);
        return true;
    }
    new->next = it->pos->next;
    new->past = it->pos;
    it->pos->next = new;
    iter_next(it);
    iter_next(it);
    it->pos->past = new;
    it->l->size++;
    iter_begin(it);
    return true;
}

bool list_remove(iterator* it, int pos) {
    if(pos < 0)
        return false;
    if(pos == 0){
        it->l->root = it->pos->next;
        iter_next(it);
        it->pos->past = NULL;
        it->l->size--;
        iter_begin(it);
        return true;
    }
    for(int i = 0; i < pos - 1; i++){
        if (!iter_next(it)) {
            iter_begin(it);
            return false;
        }
    }
    if (list_size(it->l) == pos) {
        it->pos->past = NULL;
        iter_begin(it);
        it->l->size--;
        return true;
    }
    list_elem* next_link = malloc(sizeof(T));
    next_link = it->pos->next->next;
    free(it->pos->next);
    it->pos->next = next_link;
    list_elem* past_link = malloc(sizeof(T));
    past_link = it->pos;
    iter_next(it);
    
    it->pos->past = past_link;
    it->l->size--;
    iter_begin(it);
    return true;
}

void list_print(list* l) {
    iterator it;
    iter_create(&it, l);
    T x;
    printf("list: ");
    for (int i = 0; i < list_size(l); i++) {
        x = iter_val(&it);
        printf("%d ", x);
        iter_next(&it);
    }
    printf("\n");
}

void iter_create(iterator* it, list* l) {
    it->l = l;
    it->pos = l->root;
}

void iter_begin(iterator* it) {
    it->pos = it->l->root;
}

void iter_end(iterator* it) {
    while (it->pos != it->pos->next) {
        it->pos = it->pos->next;
    }
}

bool iter_next(iterator* it) {
    if (it->pos == NULL)
        return false;
    if (it->pos->next == NULL) {
        return false;
    }
    it->pos = it->pos->next;
    return true;
}

bool iter_back(iterator* it) {
    if (it->pos == NULL)
        return false;
    if (it->pos->past == NULL) {
        return false;
    }
    it->pos = it->pos->past;
    return true;
}

bool iter_move(int n, iterator* it) {
    bool f = true;
    if (n > 0) {
        for (int i = 0; i < n; i++) {
        f = iter_next(it);
        }
    } else if (n < 0) {
        n = -n;
        for (int i = 0; i < n; i++) {
        f = iter_back(it);
        }
    }
    return f;
}

T iter_val(iterator* it) {
    return it->pos->value;
}
