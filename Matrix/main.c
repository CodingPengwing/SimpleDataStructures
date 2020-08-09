/*  Sanity check  */
#include "Array.h"
#include "Data.h"
#include "Matrix.h"

int main(int argc, char const *argv[])
{
    int rows = 5, columns = 10;
    DataMatrix_t grid = grid_Create(rows, columns);

    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            Data_t data = *data_Create(i, j, (i+j)/2, "Cool");
            grid[i][j] = data;
        }
    }
    grid_Print(grid, rows, columns);
    grid_Free(grid, rows, columns);
    return 0;
}