#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "tree.h"
#include "log.h"
#include "myassert.h"

static size_t NumImage  = 0;
static FILE*  FileLog   = NULL;
static FILE*  FileGraph = NULL;
static size_t NullNodes = 0;

void PrintLogStart (void)
{
    struct stat sb = {};
    if (stat("./" FOLDER_LOG, &sb) || !S_ISDIR(sb.st_mode)) 
    { 
        system("mkdir " FOLDER_LOG);
        system("touch " FILE_GRAPH);
        system("touch " FILE_LOG);
    }

    FileLog = OpenFile (FILE_LOG);

    fprintf(FileLog,    "<!DOCTYPE html>\n"
                        "<html lang=\"eng\">\n"
                        "<head>\n"
                        "<meta charset = \"utf-8\"/>\n"
                        "<title>LOGS</title>\n"
                        "<style>\n"
                        "body {\n"
                        "\tbackground-color: " FILL_BACK_COLOR ";\n"
                        "}\n"
                        "</style>\n"
                        "</head>\n"
                        "<body>\n"
                        "<pre>\n"
                        "<header>\n"
                        "<h1> Logs for Binary Tree </h1>\n"
                        "</header>\n"
                        "<main>\n"
                        "<pre>\n"); 
}

void PrintLogFinish (void)
{
    fprintf(FileLog,    "</pre>\n"
                        "</main>\n"
                        "</body>\n"
                        "</html>\n"); 
    CloseFile (FileLog);
}

void _PrintLogTree (BinaryTree_t* myTree, const char* file,  const char* function, const size_t line)
{
    GenerateGraph (myTree);
    FILE* pPipe = GenerateImage ();

    fprintf(FileLog,    "\n<p>\n"
                        "<b><big> ### In file: %s,\tIn function: %s,\tIn line: %lu ### </big></b>\n", file, function, line);

    size_t counter_strings = 0;
    while (counter_strings < 6)
    {
        if (fgetc(pPipe) == '\n')
        {
            counter_strings++;
        }
    }
    int symbol = fgetc(pPipe);

    while (symbol != EOF)
    {
        fputc(symbol, FileLog);
        symbol = fgetc(pPipe);
    }

    //"<img src=\"images/%lu." TYPE_OF_IMAGE "\" alt=\"Printing binary tree №%lu\" >\n"
                        
    fprintf(FileLog,    "</p>\n"
                        "<hr size = \"4\" color = \"#000000\">\n\n");
    (NumImage)++;
}

void GenerateGraph (BinaryTree_t* myTree)
{
    FileGraph = OpenFile(FILE_GRAPH);

    fprintf (FileGraph,     "digraph G{\n"
                            "rankdir = TB;\n"
                            "bgcolor = \"" FILL_BACK_COLOR "\";\n"
                            "node[color = \"" COLOR_FRAME "\", fontsize = 10];\n"
                            "edge[color = \"" COLOR_FRAME "\", fontsize = 15];\n"

                            "subgraph cluster_list {\n"
                            "\tnode[style = filled, fontsize = 10];\n"
                            "\tedge[color = \"" COLOR_FRAME "\", fontsize = 15];\n"
                            "\tstyle = \"dashed\";\n"
                            "\tcolor = \"" COLOR_STIPPLE "\";\n");

    WriteTree(myTree);

    fprintf (FileGraph,     "}\n");

    WriteHead(myTree);

    fprintf (FileGraph,     "}\n");

    CloseFile (FileGraph);
} 

FILE* GenerateImage (void)
{
    FILE* pPipe = popen ("dot " FILE_GRAPH " -T " TYPE_OF_IMAGE, "r");
    MYASSERT(pPipe, ERR_BAD_OPEN_FILE, )
    return pPipe;
}

FILE* OpenFile (const char* file_text)
{
    FILE *file_write = fopen (file_text, "w");

    MYASSERT(file_write, OPEN_FILE, return 0);

    return file_write;
}

void CloseFile (FILE* file_text)
{
	MYASSERT(file_text, BAD_POINTER_PASSED_IN_FUNC, assert(0));
    int result = fclose(file_text);
	MYASSERT(!result, CLOSE_FILE, assert(0));
}

void WriteTree (BinaryTree_t* myTree)
{
    if (!(myTree->Root)) 
    {
        return;
    }
    else
    {
        WriteNode (myTree->Root);
        NullNodes = 0;
    }

}

void WriteNode (Node_t* CurrentNode)
{
    fprintf (FileGraph, "\tnode%p [shape = Mrecord, style = filled, fillcolor = \"" FILL_BACK_GRAPH "\", color = \"" COLOR_FRAME "\", label = \"{ PTR: %p | DATA: " SPECIFIER " | { <f0> LEFT: %p | <f1> RIGHT: %p }}\"];\n"
            , CurrentNode, CurrentNode, CurrentNode->Value, CurrentNode->Left, CurrentNode->Right);
    
    if (CurrentNode->Left)
    {
        WriteNode (CurrentNode->Left);
        fprintf (FileGraph, "\tnode%p: <f0> -> node%p [color = \"" COLOR_EDGE_GRAPH "\"]\n"
                , CurrentNode, CurrentNode->Left);
    }
    else
    {
        NullNodes++;
        WriteNullNode (CurrentNode);
    }
    if (CurrentNode->Right)
    {
        WriteNode (CurrentNode->Right);
        fprintf (FileGraph, "\tnode%p: <f1> -> node%p [color = \"" COLOR_EDGE_GRAPH "\"]\n", CurrentNode, CurrentNode->Right);
    }
    else
    {
        NullNodes++;
        WriteNullNode (CurrentNode);
    }
}

void WriteNullNode (Node_t* CurrentNode)
{
    fprintf (FileGraph, "\tnull%lu [shape = ellipse, style = filled, fillcolor = \"" FILL_BACK_GRAPH_NULL "\", color = \"" COLOR_FRAME "\", label = \"NULL\"];\n"
                        "\tnode%p -> null%lu [color = \"" COLOR_EDGE_GRAPH "\"];\n", NullNodes, CurrentNode, NullNodes);
}

void WriteHead(BinaryTree_t* myTree)
{
    fprintf (FileGraph, "All[shape = Mrecord, label = \" HEADER | <f0> Root: %p \", style = \"filled\", fillcolor = \"" FILL_BACK_GRAPH "\"];\n", myTree->Root);
    if (myTree->Root)
    {
        fprintf (FileGraph, "All:<f0> -> node%p [color = \"" COLOR_EDGE_HEAD "\"];\n", myTree->Root);                                           
    }
}
