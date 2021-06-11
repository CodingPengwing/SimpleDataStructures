#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "Data.h"
#include "Node.h"

#ifndef TREE_H
#define TREE_H

// void 
// print_then_free(void *x);

typedef struct tree Tree_t;
struct tree 
{
    Node_t *root; // root node
    int (*compare_func)(Data_t*, Data_t*);  // function to compare nodes
    void (*print_func)(Data_t*);
    void (*print_file_func)(Data_t*, FILE*);
};

Tree_t *tree_Create();

int tree_is_empty(Tree_t *tree);

Node_t *tree_search(Tree_t *tree, Data_t *key);

void tree_insert(Tree_t *tree, Data_t *key);

void tree_traverse(Tree_t *tree, void action(Data_t*));

// Print the Tree in left->right order
void
tree_Print(Tree_t *tree);

// Print the Tree in left->right order to a file
void
tree_Print_to_file(Tree_t *tree, FILE *fp);

void tree_Free(Tree_t *tree);

#endif // TREE_H
