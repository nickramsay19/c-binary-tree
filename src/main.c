#include <stdio.h>

#include "include/Tree.h"

void testValueInsert(Tree t, int value) {
    TreeInsert(t, value);
    printf("I[%d] P:%d - \t", value, TreeSearch(t, value) == 1);
    TreePrint(t);
}

void testValueRemove(Tree t, int value) {
    TreeRemove(t, value);
    printf("R[%d] P:%d - \t", value, TreeSearch(t, value) == 0);
    TreePrint(t);
}

void TreeTest1() {
    Tree t = TreeCreate(5);
    
    printf("--- Adding items --- \n");
    testValueInsert(t, 5);
    testValueInsert(t, 5);
    testValueInsert(t, 3);
    testValueInsert(t, 6);
    testValueInsert(t, 4);
    testValueInsert(t, 25);
    testValueInsert(t, 1);
    testValueInsert(t, 18);
    printf("--- Deleting 5 1st time ---\n");
    testValueRemove(t, 5);
    printf("--- Deleting 5 2nd time --- \n");
    testValueRemove(t, 5);
    printf("--- Deleting 4 --- \n");
    testValueRemove(t, 4);
    printf("--- Deleting 3 --- \n");
    testValueRemove(t, 3);
    printf("--- Adding items --- \n");
    testValueInsert(t, 3);
    testValueInsert(t, 4);
    testValueInsert(t, 18); // should do nothing
    testValueInsert(t, 19);
    testValueInsert(t, 5);
    printf("--- Deleting 1 --- \n");
    testValueRemove(t, 1);

    // finally destory the tree
    TreeDestory(t);
}

int main(int argc, char** argv) {
    TreeTest1();
}