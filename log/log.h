#ifndef LOG_H
#define LOG_H

#define FILE_LOG "log.html"
#define FILE_GRAPH "graph.dot"
#define PLACE_IMAGE "./images/"
#define TYPE_OF_IMAGE "png"
const size_t SIZE_OF_COMMAND = 500;
#define FILL_BACK_COLOR "#ff7f50"
#define FILL_BACK_LIST "#ffe4c4"
#define COLOR_EDGE "#800000"

int     PrintLogStart   (BinaryTree_t* myTree);
int     PrintLogFinish  (BinaryTree_t* myTree);
int     PrintLogList    (BinaryTree_t* myTree, const char* function);
int     GenerateImage   (BinaryTree_t* myTree);
int     GenerateGraph   (BinaryTree_t* myTree, const char* function);
FILE*   OpenFileGraph   (void);
int     WriteVarsToGraph(BinaryTree_t* myTree);
int     WriteListToGraph(BinaryTree_t* myTree);

#endif