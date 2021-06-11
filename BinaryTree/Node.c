
#include "Node.h"

// Create a new Node with a given piece of data_t
Node_t *
node_Create(Data_t *data) 
{
    Node_t *node = (Node_t *) malloc(sizeof(*node));
    assert(node);
    node->data = data;
    node->parent = node->left = node->right = NULL;
    return node;
}

// Free the memory associated with a Node
void 
node_Free(Node_t *node) 
{
    if (node->data) data_Free(node->data);
    free(node);
}

int
node_Compare(Node_t *node_1, Node_t *node_2)
{
    return data_Compare(node_1->data, node_2->data);
}

void
node_Print(Node_t *node)
{
    data_Print(node->data);
}
