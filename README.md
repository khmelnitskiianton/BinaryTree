# BinaryTree

Base binary tree with functions and logs with GraphViz

## Table of Contents

- [Introduction](#inroduction)
- [Functions](#functions)
    - [treeCtor](#treector)
    - [treeDtor](#treedtor)
    - [treeInit](#treeinit)
- [List of Headers](#list-of-headers)
- [List of Sources](#list-of-sources)
- [Veryficator](#verificator)
- [Logs](#logs)

## Introduction

To start programm you need to use CMake and run program

1. Clone repository:

    ```c
    $ git clone https://github.com/khmelnitskiianton/BinaryTree.git
    ```

2. Compile CMake, write command in main directory in repo:

    ```c
    $ cmake .
    ```

3. Run CMake (compile program), write command in main directory in repo:

    ```c
    $ make
    ```

4. Run program:

    ```c
    $ ./tree
    ```

## Functions

All functions in func.h and func.cpp
Main functions of binary tree:

1. TreeCtor()

    ```c
    void    TreeCtor  (BinaryTree_t* myTree);
    ```
    - Description: construct binary tree
    - Parameters:
        - `myTree` - The tree struct.

2. TreeDtor()

    ```c
    bool    TreeDtor  (BinaryTree_t* myTree);
    ```
    - Description: destruct binary tree
    - Parameters:
        - `myTree` - The tree struct. 
    - Note: this functions use recursion travelsal to free() all elements

3. TreeInsert()

    ```c
    bool    TreeInsert (Elem_t Value, BinaryTree_t* myTree);
    ```

    - Description: insert number in tree - with sort
    - Parameters:
        - `Value`  - value to insert
        - `myTree` - The tree struct. 
    - Note: this functions use recursion travelsal to insert element

4. TreeSearch()

    ```c
    Node_t* TreeSearch (Elem_t Value, BinaryTree_t* myTree);
    ```

    - Description: insert number in tree - with sort
    - Parameters:
        - `Value`  - value to find
        - `myTree` - The tree struct. 
    - Note: this functions use recursion travelsal to find element in tree

5. TreeDelete()

    ```c
    void    TreeDelete (Elem_t Value, BinaryTree_t* myTree);
    ```

    - Description: insert number in tree - with sort
    - Parameters:
        - `Value`  - value to delete
        - `myTree` - The tree struct. 
    - Note: this functions use recursion travelsal to delete element in tree

    - NOT DONE YET NEED TO ADD PARENT TO NODE

## List of Headers

- `myassert.h` my assert with beauty printing and not stopping program
- `func.h`   all about functions
- `log.h`    all about logs
- `tree.h`   info about binary tree

## List of Sources

- `main.cpp` main sources
- `func.cpp` contents all functions
- `log.cpp`  source with log-functions

## Veryficator

Now it relized like MYASSERT() that take all errors and write it to console

## Logs

I NEED TO WRITE IT :(((())))