/*  Sanity check  */

#include "Data.h"
#include "List.h"
#include "Node.h"
#include "AdjacencyList.h"

int main(int argc, char const *argv[])
{
    size_t length = 10;
    char *strings[] = {"I", "am", "just", "so", "epic", "look", "at", "this", "code", "though"};

    AdjacencyList_t *adjList = adjacencyList_Create(length);
    for (size_t i = 0; i < 30; i++)
    {
        Data_t *data = data_Create(i, i*10, i*20, strings[i%10]);
        adjacencyList_InsertBack(adjList, i%length, data);
    }
    for (size_t i = 0; i < 20; i++)
    {
        Data_t *data = data_Create(i, i*10, i*20, strings[i%10]);
        adjacencyList_InsertFront(adjList, i%length, data);
    }

    printf("Ta da! Here's the adjacency list:\n");
    adjacencyList_Print(adjList, length);
    for (size_t i = 0; i < length; i++)
    {
        list_Sort(adjList[i]);
    }
    adjacencyList_Print(adjList, length);
    
    adjacencyList_Free(adjList, length);
    return 0;
}