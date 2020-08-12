/*  An implementation of the Array structure.
    It contains whatever Data type or structure that is defined in "Data.h"
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

#include "Data.h"

#ifndef ARRAY_H
#define ARRAY_H

typedef Data_t * Array_t;

// Make a new Array of specified length
Array_t
array_Create(size_t length) 
{
    Array_t array = (Array_t) malloc(length * sizeof(*array));
    return array;
}

// Insert a Data into an Array at given index
void
array_Insert(Array_t array, Data_t *data, size_t index)
{
    array[index] = *data;
}

// Free an Array
void 
array_Free(Array_t array, size_t length)
{
    for (size_t i = 0; i < length; i++) 
        data_Free(&array[i]);
    free(array);
}

// Print the Array - [x_0, x_1, ... x_n-1]
void 
array_Print(Array_t array, size_t length)
{
    printf("[");
    for (size_t i = 0; i < length; i++)
    {
        data_Print(array);
        if (i != length-1) 
            printf(", ");
        array++;
    }
    printf("]\n");
}

// Sort an Array
void 
array_Sort(Array_t array, size_t length)
{
    qsort(array, length, sizeof(*array), data_Compare);
}

#endif