
#include "List.h"

// Create a new empty List and return a pointer to it
List_t *
list_Create() 
{
    List_t *list = (List_t *) malloc(sizeof(*list));
    assert(list);
    list->top = NULL;
    list->bottom = NULL;
    list->size = 0;
    return list;
}

// Print the List - [x_1, x_2, ..., x_n]
void 
list_Print(List_t *list) 
{
    Node_t *current = list->top;
    printf("[");
    while (current) 
    {
        node_Print(current);
        // Print a comma unless we just printed the final element
        if (current != list->bottom) 
            printf(", ");
        current = current->next;
    }
    printf("]");
}

// Recalculate the number of elements in a List
int 
list_Size(List_t *list) 
{
    Node_t *current = list->top;
    int counter = 0;
    while (current) 
    {
        counter++;
        current = current->next;
    }
    list->size = counter;
    return list->size;
}

// Add an element to the top of a List
void 
list_InsertTop(List_t *list, Data_t *data) 
{
    Node_t *node = node_Create(data);
    if(list->size) 
    {
        node->next = list->top;
        list->top->prev = node;
        list->top = node;
    } 
    else 
        list->top = list->bottom = node;

    list->size++;
}

// Add an element to the bottom of a List
void 
list_InsertBottom(List_t *list, Data_t *data) 
{
    Node_t *node = node_Create(data);

    if(list->size) 
    {
        node->prev = list->bottom;
        list->bottom->next = node;
        list->bottom = node;
    } 
    else 
        list->top = list->bottom = node;

    list->size++;
}

// Remove and return the top element from a List
Data_t *
list_RemoveTop(List_t *list) 
{
    if (list->size == 0) 
        exit_with_error("can't remove from empty list");
    
    Node_t *old_top = list->top;
    Data_t *data = old_top->data;

    if (list->size > 1)
    {
        list->top = list->top->next;
        list->top->prev = NULL;
    }
    else 
        list->top = list->bottom = NULL;
    
    list->size--;
    // free old_top but not its Data
    old_top->data = NULL;
    node_Free(old_top);
    return data;
}

// Remove and return the bottom element from a List
Data_t *
list_RemoveBottom(List_t *list) 
{
    if (list->size == 0) 
        exit_with_error("can't remove from empty list");
    
    Node_t *old_bottom = list->bottom;
    Data_t *data = old_bottom->data;

    if (list->size > 1) 
    {
        list->bottom = list->bottom->prev;
        list->bottom->next = NULL;
    }
    else 
        list->top = list->bottom = NULL;

    list->size--;
    // free old_bottom but not its Data
    old_bottom->data = NULL;
    node_Free(old_bottom);
    return data;
}

// Remove specified Node from the List
Data_t *
list_RemoveCustom(List_t *list, Node_t *node) 
{
    if (list->size == 0) 
        exit_with_error("can't remove from empty list");
    
    // If Node is at the bottom or top of the List then  
    // use remove functions already provided
    if (!node->prev) 
        return list_RemoveTop(list);
    if (!node->next) 
        return list_RemoveBottom(list);
    
    Data_t *data = node->data;
    // Disconnect Node from List
    // Connect the corresponding adjacent Nodes together
    node->prev->next = node->next;
    node->next->prev = node->prev;

    // free Node but not its Data
    node->data = NULL;
    node_Free(node);
    list->size--;
    return data;
}

// Free the memory associated with a List
void 
list_Free(List_t *list) 
{
    while(list->size) 
    {
        Data_t *data = list_RemoveTop(list);
        data_Free(data);
    }
    free(list);
}

// Reverse the List
void 
list_Reverse(List_t *list) 
{
    Node_t *curr = list->top;
    Node_t *tmp;

    if (list->size <= 1) 
        return;

    while (curr) 
    {   
        // Swap "next" and "prev" pointers
        tmp = curr->next;
        curr->next = curr->prev;
        curr->prev = tmp;
        // Move to next Node in List, which is now "prev" Node
        curr = curr->prev;
    }
    // Swap top and bottom pointers
    tmp = list->top;
    list->top = list->bottom;
    list->bottom = tmp;
}

// Sort the List
void
list_Sort(List_t *list)
{
    // If List has fewer than 2 elements there's no need to sort
    if (list->size <= 1) return;

    // Use the sorting functionality of an array to sort a List.
    // Create an Node array of the same size as our List.
    Node_t* array[list->size];

    // Fill the Array with the current List components
    Node_t *current = list->top;
    for (size_t i = 0; i < list->size; i++)
    {
        array[i] = current;
        current = current->next;
    }

    // Sort the nodes
    qsort(array, list->size, sizeof(*array), node_CompareSort);

    // Link the Nodes back together in the new order
    for (size_t i = 0; i < list->size - 1; i++)
    {
        array[i]->next = array[i+1];
        array[i+1]->prev = array[i];
    }
    // Make the start and end NULL.
    array[0]->prev = array[list->size-1]->next = NULL;
    // Put the Nodes back into the List
    list->top = array[0];
    list->bottom = array[list->size-1];
}

// Check to see if List contains this Data
bool 
list_Contains(List_t *list, Data_t *data)
{
    Node_t *current = list->top;
    while (current)
    {
        if (data_Compare(current->data, data) == 0) 
            return true;
        current = current->next;
    }
    return false;
}
