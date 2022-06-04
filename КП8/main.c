#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main() { 
    list l;
    list_create(&l);

    iterator it;
    iter_create(&it, &l);
    
    printf("Add first element:\n");
    
    printf("Commands:\n");
    printf("print - print list\n");
    printf("add num pos - add element num to position pos\n");
    printf("remove pos - remove element of pos position\n");
    printf("len - print length of list\n");
    printf("spec num - special activity (erase list if find num element)\n");
    printf("exit - exit programm\n");
  
    char com[64];
  
    while(true){
        scanf("%s", com);
        if(strcmp(com, "print") == 0){
            list_print(&l);
        }
        else if(strcmp(com, "add") == 0){
            int add_x, pos_x;
            scanf("%d %d", &add_x, &pos_x);
            list_insert(&it, add_x, pos_x);
        }
        else if(strcmp(com, "remove") == 0){
            int rem_pos;
            scanf("%d", &rem_pos);
            list_remove(&it, rem_pos);
        }
        else if(strcmp(com, "len") == 0){
            printf("%d\n", list_size(&l));
        }
        else if(strcmp(com, "spec") == 0){
            int spec, x;
            scanf("%d", &spec);
            for(int i = 0; i < list_size(&l); i++){
                x = iter_val(&it);
                if (x == spec) {
                    list_delete(&l);
                    break;
                }
                iter_next(&it);
            }
        }
        else if(strcmp(com, "exit") == 0){
            break;
        }
        else {
            printf("incorrect input\n");
        }
      
    }
    return 0;
}
