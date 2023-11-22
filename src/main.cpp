#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "log.h"
#include "func.h"
#include "myassert.h"

int main()
{
    BinaryTree_t myTree = {};
    
    TreeCtor (&myTree);
    PrintLogStart ();
    PrintLogTree (&myTree);

    TreeInsert(2, &myTree);
    TreeInsert(-10, &myTree);
    TreeInsert(10, &myTree);
    TreeInsert(3, &myTree);
    TreeInsert(2, &myTree);
    TreeInsert(4, &myTree);
    TreeInsert(-1, &myTree);

    PrintLogFinish ();
    TreeDtor (&myTree);
    printf("\n!!!!!!!!!!!!!!! <GOOD ENDING. CHECK LOG.HTML> !!!!!!!!!!!\n");
    return 0;   
}