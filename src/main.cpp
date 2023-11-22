#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "log.h"
#include "func.h"
#include "myassert.h"

int main(int argc, char *argv[])
{
    BinaryTree_t myTree = {};
    FILE* filestream = NULL;

    if (argc == 2)
    {
        printf("File to print tree: %s\n", argv[1]);
        filestream = OpenFile(argv[1]);
    }

    TreeCtor (&myTree);
    PrintLogStart();
    PrintLogTree (&myTree);

    TreeInsert(2, &myTree);
    TreeInsert(-10, &myTree);
    TreeInsert(10, &myTree);
    TreeInsert(3, &myTree);
    TreeInsert(2, &myTree);
    TreeInsert(4, &myTree);
    TreeInsert(-1, &myTree);

    TreePreOrder(&myTree, filestream);
    TreeInOrder(&myTree, filestream);
    TreePostOrder(&myTree, filestream);

    PrintLogFinish();
    TreeDtor (&myTree);
    CloseFile(filestream);
    printf("\n!!!!!!!!!!!!!!! <GOOD ENDING. CHECK LOG.HTML> !!!!!!!!!!!\n");
    return 0;   
}