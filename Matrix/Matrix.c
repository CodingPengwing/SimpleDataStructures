
#include "Matrix.h"

// Create a Matrix of size (rows x columns)
Matrix_t *
matrix_Create(size_t rows, size_t columns)
{
    Matrix_t *matrix = (Matrix_t *) malloc(rows * sizeof(*matrix));
    for (size_t i = 0; i < rows; i++)
        matrix[i] = array_Create(columns);        
    return matrix;
}

// Free a Matrix of size (rows x columns)
void 
matrix_Free(Matrix_t *matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
        array_Free(matrix[i], columns);
    free(matrix);
}

// Print a Matrix of size (rows x columns)
void 
matrix_Print(Matrix_t *matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        if(matrix[i]) 
        { 
            array_Print(matrix[i], columns);
            println("");
        }
        else println("[]");
    }
}

// Insert a Data into a Matrix at given (row - column) position
void
matrix_Insert(Matrix_t *matrix, Data_t *data, size_t row, size_t column)
{
    matrix[row][column] = data;
}
