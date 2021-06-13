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

// Create a new Node with a given piece of Data
Node_t *
node_Create(Data_t *data);

// Free the memory associated with a Node
void 
node_Free(Node_t *node);

void
node_Print(Node_t *node);

int
node_Compare(Node_t *node_1, Node_t *node_2);

void 
node_Swap_Data(Node_t *node_1, Node_t *node_2);

int
node_p_Compare(Node_t **node_1, Node_t **node_2);

#endif // NODE_H
