/*  An implementation of an Adjacency List structure.
    Uses the Lists defined in "List.h" to make 
    Arrays of Lists - which are Adjacency Lists.
*/

#include <stdlib.h>
#include <stdio.h>

#include "Data.h"
#include "Node.h"
#include "List.h"
#include "util.h"

#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

// Giving an array of Lists (technically pointers to lists) 
// the name Adjacency List - which is exactly what it is.
typedef List_t ** AdjacencyList_t;

// Make a new Adjacency List
AdjacencyList_t adjacencyList_Create(size_t length)
{
    AdjacencyList_t adjList = (AdjacencyList_t) malloc(length * sizeof(*adjList));
    for (size_t i = 0; i < length; i++) 
        adjList[i] = list_Create();    
    return adjList;
}

// Free an Adjacency List
void adjacencyList_Free(AdjacencyList_t adjList, size_t length)
{
    for (size_t i = 0; i < length; i++) 
        list_Free(adjList[i]);
    free(adjList);
}

// Print an Adjacency List
void adjacencyList_Print(AdjacencyList_t adjList, size_t length)
{
    for (size_t i = 0; i < length; i++) 
        list_Print(adjList[i]);
}

// Insert a Data into the first position of the index-specified List
void adjacencyList_InsertFront(AdjacencyList_t adjList, int list_index, Data_t *data)
{
    list_InsertTop(adjList[list_index], data);
}

// Insert a Data into the last position of the index-specified List
void adjacencyList_InsertBack(AdjacencyList_t adjList, int list_index, Data_t *data)
{
    list_InsertBottom(adjList[list_index], data);
}

// Remove a Data from the first position of the index-specified List
void adjacencyList_RemoveFront(AdjacencyList_t adjList, int list_index)
{
    list_RemoveTop(adjList[list_index]);
}

// Remove a Data from the last position of the index-specified List
void adjacencyList_RemoveBack(AdjacencyList_t adjList, int list_index)
{
    list_RemoveBottom(adjList[list_index]);
}

#endif