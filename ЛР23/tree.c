#include "tree.h"
#include "fruit.c"

tree treeCreateEmpty(){
    return NULL;
}
tree treeBuild(tree son, tree brother, fruit item){
    tree t = malloc(sizeof(node));
    t->item = item;
    t->brother = brother;
    t->son = son;
    return t;
}
fruit treeGetItem (tree t){
    return t->item;
}
tree treeGetBrother (tree t){
    return t->brother;
}
void treeSetBrother (tree t, tree newT){
    t->brother = newT;
}
tree treeGetSon (tree t){
    return t->son;
}
void treeSetSon (tree t, tree sonT){
    t->son = sonT;
}
void treeDestroyNode (tree t){
    free(t->son);
    t->son = treeCreateEmpty();
}
void treeDestroy (tree t, int depth){
    if (treeGetBrother(t) != NULL && depth > 0)
        treeDestroy(treeGetBrother(t), depth + 1);
    if (treeGetSon(t) != NULL)
        treeDestroy(treeGetSon(t), depth + 1);
    treeDestroyNode(t);
}
void treeAddBrother (tree t, fruit item){
    tree newT = treeBuild(treeCreateEmpty(), treeCreateEmpty(), item);
    if (treeGetBrother(t) == NULL){
        treeSetBrother(t, newT);
        return;
    }
    free(newT);
    treeAddBrother(treeGetBrother(t), item);
}
void treeAddSon (tree t, fruit item){
    tree newT = treeBuild(treeCreateEmpty(), treeCreateEmpty(), item);
    if (treeGetSon(t) == NULL){
        treeSetSon(t, newT);
        return;
    }
    free(newT);
    treeAddBrother(treeGetSon(t), item);
}
void treePrint (tree t, int level){
    for (int i = 0; i < level; i++)
        printf("-");
    printf("%s\n", stringByFruit(treeGetItem(t)));
    if (treeGetSon(t) != NULL){
        treePrint(treeGetSon(t), level + 1);
    }
    if (treeGetBrother(t) != NULL){
        treePrint(treeGetBrother(t), level);
    }
}
