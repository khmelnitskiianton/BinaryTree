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
    // PrintLogStart (&myTree);
    // PrintLogList (&myTree, __PRETTY_FUNCTION__);

    TreeInsert(2, &myTree);

    // PrintLogFinish (&myTree);
    TreeDtor (&myTree);

    printf("\n!!!!!!!!!!!!!!! <GOOD ENDING. CHECK LOG.HTML> !!!!!!!!!!!\n");
    return 0;   
}