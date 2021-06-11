/*  Nodes are what makes the Linked List.
    They contain some Data specified in "Data.h"
*/

#include "Data.h"

#ifndef NODE_H
#define NODE_H

typedef struct node Node_t;
struct node {
    Data_t *data; // Stored data
    Node_t *parent; // Parent node
    Node_t *left; // Left subtree
    Node_t *right; // Right subtree
};

// Create a new Node with a given piece of Data
Node_t *
node_Create(Data_t *data);

// Free the memory associated with a Node
void 
node_Free(Node_t *node);

int
node_Compare(Node_t *node_1, Node_t *node_2);

void
node_Print(Node_t *node);

#endif // NODE_H
