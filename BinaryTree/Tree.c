
#include "Tree.h"

Tree_t 
*tree_Create() 
{
    Tree_t *new = (Tree_t*)malloc(sizeof(*new));
    assert(new != NULL);
    // initialize tree to empty
    new->root = NULL;
    // save the Node comparator 
    new->compare_func = data_Compare;
    new->print_func = data_Print;
    new->print_file_func = data_Print_to_file;
    return new;
}

int
is_empty_tree(Tree_t *tree) 
{
    if (!tree) exit_with_error("Error in is_empty_tree(): NULL pointer.");
    return tree->root == NULL;
}

static Node_t *
recursive_search_tree(Node_t *root, Data_t *key, int compare(Data_t*, Data_t*)) 
{
    if (!root) return NULL;
    int outcome = compare(key, root->data);
    if (outcome < 0) return recursive_search_tree(root->left, key, compare);
    if (outcome > 0) return recursive_search_tree(root->right, key, compare);
    return root;
}

/*  Returns a pointer to the tree node storing object "key", if it exists, 
    otherwise returns a NULL pointer. */
Node_t *
tree_search(Tree_t *tree, Data_t *key) 
{
    if (!tree) exit_with_error("Error in search_tree(): NULL tree pointer.");
    if (key == NULL) exit_with_error("Error in is_empty_tree(): NULL pointer.");
    return recursive_search_tree(tree->root, key, tree->compare_func);
}

// Recursively searches the Tree to find the correct place to put this given 
// Data. Will always create a copy of the Data and insert.
static Node_t *
recursive_insert(Node_t *root, Data_t *data, int compare(Data_t*, Data_t*)) 
{
    if (root == NULL) 
    {
        Data_t *copy = data_Copy(data);
        copy->frequency = 1;
        Node_t *new = node_Create(copy);
        return new;
    }
    // Check whether we need to traverse further
    int outcome = compare(data, root->data);
    if (outcome < 0) 
    {
        root->left = recursive_insert(root->left, data, compare);
        root->left->parent = root;
    }
    if (outcome > 0) 
    {
        root->right = recursive_insert(root->right, data, compare);
        root->right->parent = root;
    }
    // If we find a Node that has Data equal to this data, increment frequency only,
    // do not insert anything.
    if (outcome == 0) root->data->frequency += 1;

    return root;
}

// Inserts data into its correct location in the Tree.
// Warning: the Data is never actually inserted, rather, a copy of the
// Data is made and inserted. It is recommended that static Data objects
// be created and given to this function. Otherwise, the user should free 
// the Data given to this function after it is called, if they no longer 
// need it. To find the Node that contains the inserted Data use 
// tree_search().
void
tree_insert(Tree_t *tree, Data_t *data) {
    if (!tree) exit_with_error("Error in insert_in_order(): NULL tree pointer.");
    if (!data) exit_with_error("Error in insert_in_order(): NULL data pointer.");
    // insert into tree
    tree->root = recursive_insert(tree->root, data, tree->compare_func);
}

// Recursively apply an action to the Data in each Node in the whole Tree.
static void
recursive_traverse(Node_t *root, void action(Data_t*)) {
    if (root) {
        recursive_traverse(root->left, action);
        action(root->data);
        recursive_traverse(root->right, action);
    }
}

// Applies the action at every node in the tree, in the order determined by
// by the compare function.
void
tree_traverse(Tree_t *tree, void action(Data_t*)) {
    assert(tree != NULL);
    recursive_traverse(tree->root, action);
}

// Recursively apply an action to the Data in each Node in the whole Tree.
static void
recursive_print(Node_t *root, void print(Data_t*, FILE*), FILE *fp) {
    if (root) {
        recursive_print(root->left, print, fp);
        print(root->data, fp); fprintf(fp, "\n");
        recursive_print(root->right, print, fp);
    }
}

// Print the Tree in left->right order
void
tree_Print(Tree_t *tree)
{
    recursive_print(tree->root, tree->print_file_func, stdin);
}

// Print the Tree in left->right order to a file
void
tree_Print_to_file(Tree_t *tree, FILE *fp)
{
    recursive_print(tree->root, tree->print_file_func, fp);
}

// Recursively free the Nodes in the Tree.
static void
recursive_free_tree(Node_t *root) {
    if (root) {
        recursive_free_tree(root->left);
        recursive_free_tree(root->right);
        free(root);
    }
}

// Release all memory space associated with the Tree.
void
tree_Free(Tree_t *tree) {
    assert(tree != NULL);
    recursive_free_tree(tree->root);
    free(tree);
}
