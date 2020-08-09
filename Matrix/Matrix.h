/*  An implementation of a 2d Array structure.
    Uses the Arrays defined in "Array.h" to 
    make Arrays of Arrays - a Matrix.
*/

#include <stdlib.h>
#include <stdio.h>
#include "Array.h"
#include "Data.h"

#ifndef GRID_H
#define GRID_H

typedef DataArray_t * DataMatrix_t;

DataMatrix_t 
grid_Create(size_t rows, size_t columns)
{
    DataMatrix_t grid = (DataMatrix_t) malloc(rows * sizeof(*grid));
    for (size_t i = 0; i < rows; i++)
        grid[i] = array_Create(columns);        
    return grid;
}

void 
grid_Free(DataMatrix_t grid, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
        array_Free(grid[i], columns);
    free(grid);
}

void 
grid_Print(DataMatrix_t grid, size_t rows, size_t columns)
{
    printf("#\n");
    for (size_t i = 0; i < rows; i++)
        array_Print(grid[i], columns);
    printf("#\n");
}

#endif