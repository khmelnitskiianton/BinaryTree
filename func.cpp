#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "func.h"
#include "log.h"
#include "myassert.h"

void TreeCtor (BinaryTree_t* myTree)
{
    MYASSERT(myTree, BAD_POINTER_PASSED_IN_FUNC, )

    myTree->Root = NULL;
}

bool TreeDtor (BinaryTree_t* myTree)
{
    MYASSERT(myTree, BAD_POINTER_PASSED_IN_FUNC, return ERROR)

    if (myTree->Root == NULL)
    {
        return DONE;
    }

    RecFree (myTree->Root, myTree);

    return DONE;
}

bool TreeInsert (Elem_t Value, BinaryTree_t* myTree)
{
    //Создание нового узла
    MYASSERT(myTree, BAD_POINTER_PASSED_IN_FUNC, return ERROR)
    Node_t* NewNode = (Node_t*) calloc (1,sizeof (Node_t));

    NewNode->Value = Value;
    NewNode->Right = NULL;
    NewNode->Left  = NULL;

    MYASSERT(NewNode, BAD_POINTER_PASSED_IN_FUNC, return ERROR)
    
    //Если пустой корень
    if (myTree->Root == NULL)
    {
        myTree->Root = NewNode;
        PrintLogTree (myTree);
        return DONE;
    }

    //Если не пусто то рекурсивный поиск
    bool result = RecInsert (NewNode, myTree->Root, myTree);
    MYASSERT(result, TREE_SEARCH_NOT_DONE, return ERROR)
    
    PrintLogTree (myTree);
    return DONE;
}

bool RecInsert (Node_t* NewNode, Node_t* CurrentNode, BinaryTree_t* myTree)
{
    //Если меньше то вставка слева
    if (NewNode->Value < CurrentNode->Value) 
    {
        //Если место свободно то вставляем
        if (CurrentNode->Left == NULL)
        {
            CurrentNode->Left = NewNode;
        }
        else //если не пустой то вызываем рекурсивный обход
        {
            RecInsert (NewNode, CurrentNode->Left, myTree);
        }
        return DONE;
    }
    //Если больше то вставка справа
    if (NewNode->Value > CurrentNode->Value)
    {
        //Если место свободно то вставляем
        if (CurrentNode->Right == NULL)
        {
            CurrentNode->Right = NewNode;
        }
        else //если не пустой то вызываем рекурсивный обход
        {
            RecInsert (NewNode, CurrentNode->Right, myTree);
        }
        return DONE;
    }
    //Если нашли такой же элемент
    if (NewNode->Value == CurrentNode->Value)
    {
        free (NewNode);
        printf("THIS ELEMENT HAS ALREADY IN TREE!!!\n");
        return DONE;
    }

    return ERROR;
}

Node_t* TreeSearch (Elem_t Value, BinaryTree_t* myTree)
{
    MYASSERT(myTree, BAD_POINTER_PASSED_IN_FUNC, return NULL)

    if (myTree->Root) 
    {
        printf ("NO SUCH ELEMENT\n");
        return NULL;
    }

    Node_t* FindNode = RecSearch (Value, myTree->Root, myTree);
    return FindNode;
}

Node_t* RecSearch (Elem_t Value, Node_t* CurrentNode, BinaryTree_t* myTree)
{
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

    MYASSERT(0, BAD_TREE_SEARCH, return NULL)
}

void RecFree (Node_t* CurrentNode, BinaryTree_t* myTree)
{
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