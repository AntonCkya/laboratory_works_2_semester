#include <stdio.h>
#include <stdbool.h>
#include "tree.c"

//Interface
void Add (tree t, fruit item){
    while (true){
        printf("goto: (son)(brother)(add)(exit)\n");
        char c[50];
        scanf("%s", c);
        if (strcmp(c, "son") == 0){
            printf("goto son\n");
            Add(treeGetSon(t), item);
            return;
        }
        else if (strcmp(c, "brother") == 0){
            printf("goto brother\n");
            if (treeGetBrother(t) != NULL)
                Add(treeGetBrother(t), item);
            else
                printf("there is no brothers\n");
            return;
        }
        else if (strcmp(c, "add") == 0){
            printf("added as younger son\n");
            treeAddSon(t, item);
            return;
        }
        else if (strcmp(c, "exit") == 0){
            return;
        } else {
            printf("incorrect input\n");
        }
    }
}
bool Delete (tree t){
    while (true){
        printf("goto: (son)(brother)(delete)(exit)\n");
        char c[50];
        scanf("%s", c);
        if (strcmp(c, "son") == 0){
            printf("goto son\n");
            if(Delete(treeGetSon(t))){
                t->son = t->son->brother;
            }
            return false;
        }
        else if (strcmp(c, "brother") == 0){
            printf("goto brother\n");
            if(Delete(treeGetBrother(t))){
                t->brother = t->brother->brother;
            }
            return false;
        }
        else if (strcmp(c, "delete") == 0){
            printf("deleted node and it's sons\n");
            treeDestroy(t, 0);
            return true;
        }
        else if (strcmp(c, "exit") == 0){
            return false;
        } else {
            printf("incorrect input\n");
            return false;
        }
    }
}

//Task
bool isList(tree t){
    if(treeGetBrother(t) != NULL)
        return false;
    if(treeGetSon(t) != NULL)
        return isList(treeGetSon(t));
    return true;
}

int main() {
    printf("commands (begin)(allfruits)(exit)\n");
    char comm[50];
    while (true){
        scanf("%s", comm);
        if (strcmp(comm, "begin") == 0){
            printf("write your first item:\n");
            scanf("%s", comm);
            fruit item = fruitByString(comm);
            tree t = treeBuild(treeCreateEmpty(), treeCreateEmpty(), item);
            printf("tree is created\n");
            printf("commands (add)(delete)(print)(islist)(exit)\n");
            while (true){
                scanf("%s", comm);
                if (strcmp(comm, "add") == 0){
                    printf("write your item:\n");
                    scanf("%s", comm);
                    item = fruitByString(comm);
                    if (item != -1)
                        Add(t, item);
                    else
                        printf("there is no that item\n");
                }
                else if (strcmp(comm, "delete") == 0){
                    Delete(t);
                }
                else if (strcmp(comm, "print") == 0){
                    treePrint(t, 0);
                }
                else if (strcmp(comm, "islist") == 0){
                    if (isList(t))
                        printf("tree is a linear list of nodes\n");
                    else
                        printf("tree is not a linear list of nodes\n");
                }
                else if (strcmp(comm, "exit") == 0){
                    return 0;
                } else {
                    printf("incorrect input\n");
                }
            }
        }
        else if (strcmp(comm, "allfruits") == 0){
            fruitPrint();
        }
        else if (strcmp(comm, "exit") == 0){
            return 0;
        } else {
            printf("incorrect input\n");
        }
    }
}
