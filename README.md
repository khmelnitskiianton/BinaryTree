# BinaryTree

Base binary tree with functions and logs with GraphViz

## Table of Contents

- [Introduction](#inroduction)
- [Myassert](#myassert)
- [Veryficator](#verificator)
- [Logs](#logs)
- [Options of compiling](#options_of_compiling)

## Introduction

To start program you need to use CMake and run program

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
    $ ./tree.exe
    ```

5.  To test functions 
    `TreeInsert(Elem_t, BinaryTree_t*)`
    `TreeSearch(Elem_t, BinaryTree_t*)` 
    write it to main.cpp like in example

## Options of compiling

DEBUG_LOG
DEBUG_MYASSERT
DEBUG_VERIFY

## Myassert

`myassert.h`

Now it relized like MYASSERT() that take all errors with enum and write it to console

## Verificator

`verificator.cpp` `verificator.h`

Checking tree for loops and other errors. Functions returns EnumOfErrors 

## Logs

`log.cpp` `log.h`

Logs use GraphViz to vizualized graphs in pictures
After generating image it includes to html file `log.html`

![Пример графического лога!](https://github.com/khmelnitskiianton/BinaryTree/blob/main/example_log.svg)