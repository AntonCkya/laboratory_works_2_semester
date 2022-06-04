#include "fruit.h"
#ifndef TREE_H
#define TREE_H

typedef struct node node;
struct node{
    fruit item;
    node *son;
    node *brother;
};
typedef node *tree;
tree treeCreateEmpty();
tree treeBuild(tree son, tree brother, fruit item);
fruit treeGetItem (tree t);
tree treeGetBrother (tree t);
void treeSetBrother (tree t, tree newT);
tree treeGetSon (tree t);
void treeSetSon (tree t, tree sonT);
void treeDestroyNode (tree t);
void treeDestroy (tree t, int depth);
void treeAddBrother (tree t, fruit item);
void treeAddSon (tree t, fruit item);
void treePrint (tree t, int level);

#endif //TREE_H
