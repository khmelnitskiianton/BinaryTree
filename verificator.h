#ifndef VERIFY_H
#define VERIFY_H

#define DEBUG_VERIFY 1

#ifdef DEBUG_VERIFY
    #define ON_VERIFY(...) __VA_ARGS__
    #define VERIFY_TREE(tree_pointer) VerifyTree(tree_pointer, __LINE__, __FILE__, __PRETTY_FUNCTION__)
#else
    #define ON_VERIFY(...)
    #define VERIFY_TREE(tree_pointer) VerifyTree(tree_pointer, __LINE__, __FILE__, __PRETTY_FUNCTION__)
#endif


#endif
