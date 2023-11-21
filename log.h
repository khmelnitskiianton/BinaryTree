#ifndef LOG_H
#define LOG_H

#define DEBUG_LOG 1

#ifdef DEBUG_LOG
    #define ON_LOG(...)   __VA_ARGS__
    #define PrintLogTree(myTree) \
            _PrintLogTree(myTree, __FILE__, __PRETTY_FUNCTION__, __LINE__)
#else
    #define ON_LOG(...)
    #define PrintLogTree(myTree) 
#endif

void _PrintLogTree (BinaryTree_t* myTree, 
                    const char* file,  const char* function, const size_t line);

void  PrintLogStart  (void);
void  PrintLogFinish (void);
void  GenerateImage  (void);
void  GenerateGraph  (BinaryTree_t* myTree);
void  WriteNode      (Node_t* CurrentNode);
void  WriteNullNode  (Node_t* CurrentNode);
void  WriteHead      (BinaryTree_t* myTree);
void  WriteTree      (BinaryTree_t* myTree);
FILE* OpenFile       (const char* file_text);
void  CloseFile      (FILE* file_text);

#define FILE_LOG "log.html"
#define FILE_GRAPH "graph.dot"
#define PLACE_IMAGE "./images/"
#define TYPE_OF_IMAGE "svg"
const size_t SIZE_OF_COMMAND = 500;
const size_t SIZE_OF_POINTER = 13;

#define FILL_BACK_COLOR "#ff7f50"
#define FILL_BACK_GRAPH "#ffe4c4"
#define FILL_BACK_GRAPH_NULL "#BC8F8F"
#define COLOR_FRAME "#800000"
#define COLOR_STIPPLE "#800080"
#define COLOR_EDGE_GRAPH "#000000"
#define COLOR_EDGE_HEAD "#FFFFFF"

#endif