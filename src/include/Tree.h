#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>

typedef struct Node *Tree;

typedef struct Node {
    int value;
    Tree left, right;
} Node;

Tree TreeCreate(int initial);

void TreeDestory(Tree t);

void TreeInsert(Tree t, int value);

void TreeRemove(Tree t, int value);

bool TreeSearch(Tree t, int value);

void TreePrint(Tree t);

Tree TreeCopy(Tree t);

#endif