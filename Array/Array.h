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

typedef Data_t * DataArray_t;

// Make a new Array of specifed size
DataArray_t
array_Create(size_t size) 
{
    DataArray_t array = (DataArray_t) malloc(size * sizeof(*array));
    return array;
}

// Free an Array
void 
array_Free(DataArray_t array, size_t size)
{
    for (size_t i = 0; i < size; i++) 
        data_Free(&array[i]);
    free(array);
}

// Print the Array - [x_0, x_1, ... x_n-1]
void 
array_Print(DataArray_t array, size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        data_Print(array);
        if (i != size-1) printf(", ");
        array++;
    }
    printf("]\n");
}

// Sort an Array
void 
array_Sort(DataArray_t array, size_t size)
{
    qsort(array, size, sizeof(*array), data_Compare);
}

#endif