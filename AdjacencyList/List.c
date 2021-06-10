
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
    Node_t *curr_node = list->top;
    Node_t *tmp;

    if (list->size <= 1) 
        return;

    while (curr_node) 
    {   
        // Swap "next" and "prev" pointers
        tmp = curr_node->next;
        curr_node->next = curr_node->prev;
        curr_node->prev = tmp;
        // Move to next Node in List, which is now "prev" Node
        curr_node = curr_node->prev;
    }
    // Swap top and bottom pointers
    tmp = list->top;
    list->top = list->bottom;
    list->bottom = tmp;
}

// Move all values that are bigger than the pivot to the bottom of the List
void 
list_Sift(List_t *list, Data_t *pivot) 
{
    if (list->size <= 1) return;
    Node_t *curr = list->top;
    Node_t *swap;

    // Remove any Node with value > pivot, insert them at the 
    // bottom of tmp_list
    while (curr) 
    {
        if (data_Compare(curr->data, pivot) > 0) 
        {
            swap = curr->next;
            // try to find the next node that is <= pivot
            while (swap)
            {
                if (data_Compare(swap->data, pivot) <= 0) break;
                else swap = swap->next;
            }
            // if swap is NULL, there is no more shuffling to be done
            if (!swap) break;
            // else swap the data of the 2 nodes
            node_Swap_Data(curr, swap);
        } 
        curr = curr->next;
    }
}

// This is a O(n^2) implementation of sorting, the code is quite short but the
// computation are quite taxing. It might be better to just copy all the elements 
// into an array, sort them using the standard qsort() function, and then copy back
// into the List. The user can explore the Array package to see how an array of Data 
// can be easily created and sorted.
void
list_Sort(List_t *list)
{
    Node_t *current = list->top;
    while (current)
    {
        // Move all elements bigger than current Data to bottom of List
        list_Sift(list, current->data);
        current = current->next;
    }
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
