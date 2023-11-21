# BinaryTree

Base binary tree with functions and logs with GraphViz

## Table of Contents

- [Introduction](#inroduction)
- [List of Headers](#list-of-headers)
- [List of Sources](#list-of-sources)
- [Myassert](#myassert)
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

5. To test functions `TreeInsert(Elem_t, BinaryTree_t*)` and `TreeSearch(Elem_t, BinaryTree_t*)` write it to main.cpp like in example

## List of Headers

- `myassert.h` my assert with beauty printing and not stopping program
- `func.h`     all about functions
- `log.h`      all about logs
- `tree.h`     info about binary tree
- `element.h`  type of elements in tree
- `verificator.h` all about verificator

## List of Sources

- `main.cpp` main sources
- `func.cpp` contents all functions
- `log.cpp`  source with log-functions

## Myassert

`myassert.h`

DEBUG_MYASSERT 1

Now it relized like MYASSERT() that take all errors with enum and write it to console

## Verificator

`verificator.h`

DEBUG_VERIFY 1

---

## Logs

`log.cpp` `log.h`

DEBUG_LOG 1

Logs use GraphViz to vizualized graphs in pictures
After generating image it includes to html file `log.html`

![Пример графического лога!](https://github.com/khmelnitskiianton/BinaryTree/images/4.svg)