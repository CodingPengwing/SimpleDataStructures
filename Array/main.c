/*  Sanity check  */

#include "Array.h"
#include "Data.h"

int main(int argc, char const *argv[])
{
    int size = 10;
    DataArray_t array = array_Create(size);
    
    int i;
    for (i = 0; i < size/2; i++)
    {
        array[i] = *data_Create(0, 0, 0, "Woah cool code");
    }
    for (i = size/2; i < size; i++)
    {
        array[i] = *data_Create(0, 0, 0, NULL);
    }
    
    array_Print(array, size);
    array_Sort(array, size);
    array_Print(array, size);

    return 0;
}