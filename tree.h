#ifndef TREE_H
#define TREE_H

#include "element.h"

struct Node {
    Elem_t       Value;
    struct Node* Right;
    struct Node* Left;
};
 
typedef struct Node Node_t;

typedef struct BinaryTree {
    Node_t* Root;
} BinaryTree_t;

#endif