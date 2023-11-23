#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
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
        printf(GREEN "\n<<<FILE TO PRINT TREE: %s>\n\n" RESET, argv[1]);
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

    Node_t* FindNode = NULL;
    TreeSearch(&FindNode, 3, &myTree);

    TreePreOrder(&myTree, filestream);
    TreeInOrder(&myTree, filestream);
    TreePostOrder(&myTree, filestream);

    PrintLogFinish();
    TreeDtor (&myTree);
    CloseFile(filestream);
    printf(GREEN "\n<<<GOOD ENDING. CHECK LOG.HTML>>>\n\n" RESET);
    return 0;   
}