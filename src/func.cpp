#include <stdio.h>
#include <stdlib.h>

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

    RecFree (myTree->Root, myTree); 

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
        free (NewNode);
        printf("THIS ELEMENT HAS ALREADY IN TREE!!!\n");
        return DONE;
    }

    return ERROR;
}

EnumOfErrors TreeSearch (Node_t** ReturnNode, Elem_t Value, BinaryTree_t* myTree)
{
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return ERR_BAD_POINTER_TREE)

    if (!(myTree->Root)) 
    {
        printf ("NO SUCH ELEMENT\n");
        return ERR_OK;
    }

    Verify(myTree);

    *ReturnNode = RecSearch (Value, myTree->Root, myTree);

    return ERR_OK;
}

Node_t* RecSearch (Elem_t Value, Node_t* CurrentNode, BinaryTree_t* myTree)
{
    MYASSERT(CurrentNode, ERR_BAD_POINTER_NODE, return NULL)
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return NULL)

    if (Value < CurrentNode->Value) 
    {
        if (CurrentNode->Left == NULL)
        {
            printf ("NO SUCH ELEMENT\n");
            return NULL;
        }
        else
        {
            return RecSearch (Value, CurrentNode, myTree);
        }
    }
    if (Value > CurrentNode->Value)
    {
        if (CurrentNode->Right == NULL)
        {
            printf ("NO SUCH ELEMENT\n");
            return NULL;
        }
        else
        {
            return RecSearch (Value, CurrentNode, myTree);
        }
    }
    if (Value == CurrentNode->Value)
    {
        printf("\nFIND YOUR ELEMENT:\nPOINTER: %p\t\tVALUE: %d\n", CurrentNode, CurrentNode->Value);
        return CurrentNode;
    }

    MYASSERT(0, ERR_TREE_SEARCH_NOT_DONE, return NULL)
}

void RecFree (Node_t* CurrentNode, BinaryTree_t* myTree)
{
    MYASSERT(CurrentNode, ERR_BAD_POINTER_NODE, return)
    MYASSERT(myTree, ERR_BAD_POINTER_TREE, return)

    if (CurrentNode->Left)
    {
        RecFree (CurrentNode->Left, myTree);
    }
    if (CurrentNode->Right)
    {
        RecFree (CurrentNode->Right, myTree);
    }

    free(CurrentNode);
}