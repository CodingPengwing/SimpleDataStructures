/*  Sanity check  */

#include "Data.h"
#include "List.h"
#include "Node.h"
#include "AdjacencyList.h"

int main(int argc, char const *argv[])
{
    size_t size = 10;
    AdjacencyList_t adjList = adjacencyList_Create(size);
    char *strings[] = {"I", "am", "just", "so", "epic", "look", "at", "this", "code", "though"};

    int i;
    for (i = 0; i < 50; i++)
    {
        Data_t *data = data_Create(i, i*10, i*20, strings[i%10]);
        adjacencyList_InsertBack(adjList, i%size, data);
    }
    adjacencyList_Print(adjList, size);
    adjacencyList_Free(adjList, size);
    
    return 0;
}