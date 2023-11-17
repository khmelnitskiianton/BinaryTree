#ifndef TREE_H
#define TREE_H

#include <limits.h>

typedef int Elem_t;
#define SPECIFIER "%d"
const Elem_t POISON_ELEMENT = 666;

struct Node {
    Elem_t       Value;
    struct Node* Right;
    struct Node* Left;
};
 
typedef struct Node Node_t;

typedef struct BinaryTree {
    Node_t* Root;
    //TODO: change what i will need
} BinaryTree_t;

#endif