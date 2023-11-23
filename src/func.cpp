#include <stdio.h>
#include <stdlib.h>

#include "colors.h"
#include "tree.h"
#include "log.h"
#include "myassert.h"
#include "verificator.h"
#include "func.h"

void TreeCtor (BinaryTree_t* myTree)
{
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return)

    myTree->Root = NULL;
    myTree->Size = 0;
}

EnumOfErrors TreeDtor (BinaryTree_t* myTree)
{
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return ERR_BAD_POINTER_TREE)

    if (myTree->Root == NULL)
    {
        return ERR_OK;
    }

    Verify(myTree);

    RecFree (myTree->Root); 

    return ERR_OK;
}

EnumOfErrors TreeInsert (Elem_t Value, BinaryTree_t* myTree)
{
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return ERR_BAD_POINTER_TREE)
    Node_t* NewNode = (Node_t*) calloc (1,sizeof (Node_t));
    MYASSERT(NewNode, ERR_BAD_CALLOC, return ERR_BAD_CALLOC)

    NewNode->Value = Value;
    NewNode->Right = NULL;
    NewNode->Left  = NULL;

    if (myTree->Root == NULL)
    {
        myTree->Root = NewNode;
        myTree->Size++;
        PrintLogTree (myTree);
        return ERR_OK;
    }

    Verify(myTree);

    bool result = RecInsert (NewNode, myTree->Root, myTree);
    MYASSERT(result, ERR_TREE_SEARCH_NOT_DONE, return ERR_TREE_SEARCH_NOT_DONE)

    PrintLogTree (myTree);
    return ERR_OK;
}

bool RecInsert (Node_t* NewNode, Node_t* CurrentNode, BinaryTree_t* myTree)
{
    MYASSERT(NewNode, ERR_BAD_POINTER_NODE, return 0)
    MYASSERT(CurrentNode, ERR_BAD_POINTER_NODE, return 0)
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return 0)
    MYASSERT(myTree->Root, ERR_ROOT_NULL, return 0)

    if (NewNode->Value < CurrentNode->Value) 
    {
        if (CurrentNode->Left == NULL)
        {
            CurrentNode->Left = NewNode;
            myTree->Size++;
        }
        else
        {
            RecInsert (NewNode, CurrentNode->Left, myTree);
        }
        return DONE;
    }
    if (NewNode->Value > CurrentNode->Value)
    {
        if (CurrentNode->Right == NULL)
        {
            CurrentNode->Right = NewNode;
            myTree->Size++;
        }
        else
        {
            RecInsert (NewNode, CurrentNode->Right, myTree);
        }
        return DONE;
    }
    if (NewNode->Value == CurrentNode->Value)
    {
        printf(BLUE "NUMBER: %d. THIS ELEMENT HAS ALREADY IN TREE!!!\n" RESET, NewNode->Value);
        free (NewNode);
        return DONE;
    }

    return ERROR;
}

EnumOfErrors TreeSearch (Node_t** ReturnNode, Elem_t Value, BinaryTree_t* myTree)
{
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return ERR_BAD_POINTER_TREE)

    if (!(myTree->Root)) 
    {
        printf (BLUE "NO SUCH ELEMENT\n" RESET);
        return ERR_OK;
    }

    Verify(myTree);

    *ReturnNode = RecSearch (Value, myTree->Root);

    return ERR_OK;
}

Node_t* RecSearch (Elem_t Value, Node_t* CurrentNode)
{
    MYASSERT(CurrentNode, ERR_BAD_POINTER_NODE, return NULL)

    if (Value < CurrentNode->Value) 
    {
        if (CurrentNode->Left == NULL)
        {
            printf (BLUE "NO SUCH ELEMENT\n" RESET);
            return NULL;
        }
        else
        {
            return RecSearch (Value, CurrentNode->Left);
        }
    }
    if (Value > CurrentNode->Value)
    {
        if (CurrentNode->Right == NULL)
        {
            printf (BLUE "NO SUCH ELEMENT\n" RESET);
            return NULL;
        }
        else
        {
            return RecSearch (Value, CurrentNode->Right);
        }
    }
    if (Value == CurrentNode->Value)
    {
        printf(CYAN "\nFIND YOUR ELEMENT: POINTER: %p VALUE: %d\n" RESET, CurrentNode, CurrentNode->Value);
        return CurrentNode;
    }

    MYASSERT(0, ERR_TREE_SEARCH_NOT_DONE, return NULL)
}

void RecFree (Node_t* CurrentNode)
{
    MYASSERT(CurrentNode, ERR_BAD_POINTER_NODE, return)

    if (CurrentNode->Left)
    {
        RecFree (CurrentNode->Left);
    }
    if (CurrentNode->Right)
    {
        RecFree (CurrentNode->Right);
    }

    free(CurrentNode);
}

EnumOfErrors TreePreOrder (BinaryTree_t* myTree, FILE* filestream)
{
    if (!filestream)
    {
        fprintf(stderr, MAGENTA "Forgot to write file where to write tree!\nTry to start with [./tree.exe <name_of_file>]\n\n" RESET);
        return ERR_BAD_FILESTREAM;
    }
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return ERR_BAD_POINTER_TREE)
    Verify(myTree);
    PrintPreNode(myTree->Root, filestream);
    fprintf(filestream, "\n");
    return ERR_OK;
}

EnumOfErrors TreeInOrder (BinaryTree_t* myTree, FILE* filestream)
{
    if (!filestream)
    {
        fprintf(stderr, MAGENTA "Forgot to write file where to write tree!\nTry to start with [./tree.exe <name_of_file>]\n\n" RESET);
        return ERR_BAD_FILESTREAM;
    }
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return ERR_BAD_POINTER_TREE)
    Verify(myTree);
    PrintInNode(myTree->Root, filestream);
    fprintf(filestream, "\n");
    return ERR_OK;
}

EnumOfErrors TreePostOrder (BinaryTree_t* myTree, FILE* filestream)
{
    if (!filestream)
    {
        fprintf(stderr, MAGENTA "Forgot to write file where to write tree!\nTry to start with [./tree.exe <name_of_file>]\n\n" RESET);
        return ERR_BAD_FILESTREAM;
    }
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return ERR_BAD_POINTER_TREE)
    Verify(myTree);
    PrintInNode(myTree->Root, filestream);
    fprintf(filestream, "\n");
    return ERR_OK;
}

void PrintPreNode (Node_t* CurrentNode, FILE* filestream)
{
    if (!CurrentNode) {fprintf(filestream, " nil "); return;}
    fprintf(filestream, "(");

    fprintf(filestream, " " SPECIFIER " ", CurrentNode->Value);
    PrintPreNode(CurrentNode->Left, filestream);
    PrintPreNode(CurrentNode->Right, filestream);

    fprintf(filestream, ")");
}

void PrintInNode (Node_t* CurrentNode, FILE* filestream)
{
    if (!CurrentNode) {fprintf(filestream, " nil "); return;}
    fprintf(filestream, "(");

    PrintInNode(CurrentNode->Left, filestream);
    fprintf(filestream, " " SPECIFIER " ", CurrentNode->Value);
    PrintInNode(CurrentNode->Right, filestream);

    fprintf(filestream, ")");
}

void PrintPostNode (Node_t* CurrentNode, FILE* filestream)
{
    if (!CurrentNode) {fprintf(filestream, " nil "); return;}
    fprintf(filestream, "(");

    PrintPostNode(CurrentNode->Left, filestream);
    PrintPostNode(CurrentNode->Right, filestream);
    fprintf(filestream, " " SPECIFIER " ", CurrentNode->Value);

    fprintf(filestream, ")");
}

