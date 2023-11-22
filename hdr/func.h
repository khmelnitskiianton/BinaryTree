#ifndef FUNC_H
#define FUNC_H

#include "errors_enum.h"

const int DONE = 1;
const int ERROR = 0;

void         TreeCtor   (BinaryTree_t* myTree);
EnumOfErrors TreeDtor   (BinaryTree_t* myTree);
EnumOfErrors TreeInsert (Elem_t Value, BinaryTree_t* myTree);
EnumOfErrors TreeSearch (Node_t** ReturnNode, Elem_t Value, BinaryTree_t* myTree);

bool    RecInsert   (Node_t* NewNode, Node_t* CurrentNode, BinaryTree_t* myTree);
void    RecFree     (Node_t* CurrentNode);
Node_t* RecSearch   (Elem_t Value, Node_t* CurrentNode);

EnumOfErrors TreePreOrder  (BinaryTree_t* myTree, FILE* filestream);
EnumOfErrors TreeInOrder   (BinaryTree_t* myTree, FILE* filestream);
EnumOfErrors TreePostOrder (BinaryTree_t* myTree, FILE* filestream);

void PrintPreNode  (Node_t* CurrentNode, FILE* filestream);
void PrintInNode   (Node_t* CurrentNode, FILE* filestream);
void PrintPostNode (Node_t* CurrentNode, FILE* filestream);

#endif