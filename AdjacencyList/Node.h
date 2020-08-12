/*  Nodes are what makes the Linked List.
    They contain some Data specified in "Data.h"
*/

#include "Data.h"

#ifndef NODE_H
#define NODE_H

typedef struct node Node_t;
struct node {
    Data_t *data;
    Node_t *prev;
    Node_t *next;
};

// Create a new Node with a given piece of data_t
Node_t *
node_Create(Data_t *data) 
{
    Node_t *node = (Node_t *) malloc(sizeof(*node));
    assert(node);
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Free the memory associated with a Node
void 
node_Free(Node_t *node) 
{
    if (node->data) 
        data_Free(node->data);
    free(node);
}

void
node_Print(Node_t *node)
{
    data_Print(node->data);
}

void 
node_Swap_Positions(Node_t *node_1, Node_t *node_2)
{
    Data_t *tmp_data = node_1->data;
    node_1->data = node_2->data;
    node_2->data = tmp_data;
}

#endif