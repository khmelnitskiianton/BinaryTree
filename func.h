#ifndef FUNC_H
#define FUNC_H

const int DONE = 1;
const int ERROR = 0;

void    TreeCtor  (BinaryTree_t* myTree);
bool    TreeDtor  (BinaryTree_t* myTree);
bool    TreeInsert (Elem_t Value, BinaryTree_t* myTree);
Node_t* TreeSearch (Elem_t Value, BinaryTree_t* myTree);

bool    RecInsert (Node_t* NewNode, Node_t* CurrentNode, BinaryTree_t* myTree);
void    RecFree (Node_t* CurrentNode, BinaryTree_t* myTree);
Node_t* RecSearch (Elem_t Value, Node_t* CurrentNode, BinaryTree_t* myTree);

#endif