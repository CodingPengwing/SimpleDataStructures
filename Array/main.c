/*  Sanity check  */

#include "Array.h"
#include "Data.h"

int main(int argc, char const *argv[])
{
    int size = 10;
    Array_t *array = array_Create(size);
    
    int i;
    for (i = 0; i < size/2; i++)
    {
        Data_t *data = data_Create(i*5%4, i*3/2, i, "Cool code!");
        array_Insert(array, data, i);
    }
    
    for (i = size/2; i < size; i++)
    {
        Data_t *data = data_Create(i*7%4, i*5%2, i, NULL);
        array_Insert(array, data, i);
    }
    
    array_Print(array, size);
    array_Sort(array, size);
    array_Print(array, size);

    array_Free(array, size);
    return 0;
}