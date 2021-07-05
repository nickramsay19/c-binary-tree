#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "include/Tree.h"

Tree TreeCreate(int initial) {

    // allocate space for the treee
    Tree t = (Tree) malloc(sizeof(Node));

    // assign the root value
    t->value = initial;

    return t;
}

void TreeDestory(Tree t) {

    // destroy each subtree if they exist
    if (t->right != NULL) TreeDestory(t->right);
    if (t->left != NULL) TreeDestory(t->left);

    // destroy t
    free(t);
}

Tree TreeCopy(Tree t) {

    // create a NULL tree
    Tree s = NULL;

    // if the given tree isn't NULL
    // copy its values into s
    if (t != NULL) {

        // allocate space for s
        s = TreeCreate(t->value);

        // copy its branch pointers
        s->left = t->left;
        s->right = t->right;
    }

    return s;
}

void TreeInsert(Tree t, int value) {

    // check to move right
    if (t->value < value) {
        
        // check if there is already a branch right before creation
        // if there is, keep searching right w/ recursive insert
        if (t->right == NULL) t->right = TreeCreate(value);
        else TreeInsert(t->right, value);

    // check to move left
    } else if (t->value > value) {

        // check if there is already a branch left before creation
        // if there is, keep searching left w/ recursive insert
        if (t->left == NULL) t->left = TreeCreate(value);
        else TreeInsert(t->left, value);
    }

    // item already exists or we have finished, return
    return;
}

void TreeRemove(Tree t, int value) {

    // check if we found the node to be deleted
    if (t->value == value) {
                    
        // case 1: check if root containes only one subtree
        // if so: replace t with its only subtree
        if (t->left == NULL || t->right == NULL) {

            // find which side a subtree exists
            Tree subtree = t->left != NULL ? t->left : t->right;

            // replace t with the subtree
            t->value = subtree->value;
            t->left = subtree->left;
            t->right = subtree->right;

        // case 2: check if root has both children defined
        // if so: replace t with its successor: the smallest ..
        // number larger than t (most left number, right of t)
        } else if (t->left != NULL && t->right != NULL) {

            // store the successor tree (the smallest number larger than t)
            Tree successor = t->right;

            // loop until the true successor is found i.e. cant go further left
            while (successor->left != NULL) {
                // move to the left
                successor = successor->left;
            }

            // replace t with the successor
            t->value = successor->value;

            // now we must remove the smallest value right of t

            // before we remove the smallest value, we must check
            // if there is a subtree to the right to replace it with or it will be lost
            // will default to NULL if not
            Tree successor_replacement = TreeCopy(successor->right);

            // free what was at the successor tree
            // then replace it with its replacement
            free(successor);
            successor = TreeCopy(successor_replacement);

        } 
        
    // case 3: for case 3 we must search ahead of the current tree to..
    // ensure we can delete the pointer to the tree entirely
    // case 3A: the node to the left is a leaf and is to be deleted
    } else if ((t->left != NULL) && t->left->value == value && t->left->left == NULL && t->left->right == NULL) { 
        free(t->left);
        t->left = NULL;

    // case 3B: the node to the right is a leaf and is to be deleted
    } else if ((t->right != NULL) && t->right->value == value && t->right->left == NULL && t->right->right == NULL) {
        free(t->right);
        t->right = NULL;

    // otherwise, keep searching in subtrees
    // so long as the sub trees exist
    } else if (t->value < value && t->right != NULL) {
        TreeRemove(t->right, value);
    } else if (t->value > value && t->left != NULL) {
        TreeRemove(t->left, value);
    } else {
        // node wasn't found, simply return
        return;
    }
}

bool TreeSearch(Tree t, int value) {
    if (t != NULL && t->value == value) {
        return true;
    } else if (t != NULL && t->value < value) {
        return TreeSearch(t->right, value);
    } else if (t != NULL && t->value > value) {
        return TreeSearch(t->left, value);
    } else {
        return false;
    }
}

void _TreePrintNode(Tree t) {

    // check if nothing at node
    if (t == NULL) {
        printf("-");

    // check if leaf -> print value
    } else if (t->left == NULL && t->right == NULL) { 
        printf("%d", t->value);

    // otherwise, print value with children in brackets
    } else {
        printf("%d(", t->value);
        _TreePrintNode(t->left);
        printf(", ");
        _TreePrintNode(t->right);
        printf(")");
    }
}

void TreePrint(Tree t) {
    _TreePrintNode(t);
    printf("\n");
}

