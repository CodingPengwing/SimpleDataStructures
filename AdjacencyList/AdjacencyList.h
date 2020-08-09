
#include <stdlib.h>
#include <stdio.h>

#include "Data.h"
#include "Node.h"
#include "List.h"
#include "util.h"

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

typedef List_t ** AdjacencyList_t;

AdjacencyList_t adjacencyList_Create(size_t length)
{
    AdjacencyList_t adj_list = (AdjacencyList_t) malloc(length * sizeof(*adj_list));
    for (size_t i = 0; i < length; i++) 
        adj_list[i] = list_Create();    
    return adj_list;
}


void adjacencyList_Free(AdjacencyList_t adj_list, size_t length)
{
    for (size_t i = 0; i < length; i++) 
        list_Free(adj_list[i]);
    free(adj_list);
}


void adjacencyList_Print(AdjacencyList_t adj_list, size_t length)
{
    printf("$\n");
    for (size_t i = 0; i < length; i++) 
        list_Print(adj_list[i]);
    printf("$\n");
}


void adjacencyList_InsertFront(AdjacencyList_t adj_list, int list_index, Data_t *data)
{
    list_InsertTop(adj_list[list_index], data);
}


void adjacencyList_InsertBack(AdjacencyList_t adj_list, int list_index, Data_t *data)
{
    list_InsertBottom(adj_list[list_index], data);
}


void adjacencyList_RemoveFront(AdjacencyList_t adj_list, int list_index)
{
    list_RemoveTop(adj_list[list_index]);
}


void adjacencyList_RemoveBack(AdjacencyList_t adj_list, int list_index)
{
    list_RemoveBottom(adj_list[list_index]);
}


#endif