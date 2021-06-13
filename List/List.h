/*  An implementation of a Linked List structure.
    It contains Nodes which contains Data
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "Data.h"
#include "Node.h"
#include "util.h"

#ifndef LIST_H
#define LIST_H

typedef struct linked_list List_t;
struct linked_list 
{
    Node_t *top;
    Node_t *bottom;
    int size;
};

// Create a new empty List and return a pointer to it
List_t *
list_Create();

// Print the List - [x_1, x_2, ..., x_n]
void 
list_Print(List_t *list);

// Recalculate the number of elements in a List
int 
list_Size(List_t *list);

// Add an element to the top of a List
void 
list_InsertTop(List_t *list, Data_t *data);

// Add an element to the bottom of a List
void 
list_InsertBottom(List_t *list, Data_t *data);

// Remove and return the top element from a List
Data_t *
list_RemoveTop(List_t *list);

// Remove and return the bottom element from a List
Data_t *
list_RemoveBottom(List_t *list);

// Remove specified Node from the List
Data_t *
list_RemoveCustom(List_t *list, Node_t *node);

// Free the memory associated with a List
void 
list_Free(List_t *list);

// Reverse the List
void 
list_Reverse(List_t *list);

// Sort the List
void
list_Sort(List_t *list);

// Check to see if List contains this Data
bool 
list_Contains(List_t *list, Data_t *data);

#endif // LIST_H
