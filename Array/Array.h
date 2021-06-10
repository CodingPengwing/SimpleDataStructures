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
Array_t *
array_Create(size_t length);

// Free an Array
void 
array_Free(Array_t *array, size_t length);

// Print the Array - [x_0, x_1, ... x_n-1]
void 
array_Print(Array_t *array, size_t length);

// Insert a Data into an Array at given index
void
array_Insert(Array_t *array, Data_t *data, size_t index);

// Sort an Array
void 
array_Sort(Array_t *array, size_t length);

#endif // ARRAY_H
