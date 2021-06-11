
#include "Data.h"

//  Create a new piece of Data
Data_t *
data_Create(int x, int y, int z, char *string) 
{
    Data_t *data = (Data_t *) malloc(sizeof(*data));
    assert(data);
    data->x = x;
    data->y = y;
    data->z = z;
    if (string) data->string = string_Copy(string);
    else data->string = string_Copy("");
    return data;
}

// Update this data to new parameters.
// Warning: This function will never finish with data having NULL for its string.
// If it is given a NULL pointer for the string parameter, it will generate an 
// empty string. To keep the same string, the same data->string should be provided 
// for the string parameter.
void data_Update(Data_t *data, int x, int y, int z, char *string)
{
    data->x = x;
    data->y = y;
    data->z = z;
    // If they are the same pointer, they are the same string.
    if (data->string == string) return;
    // Otherwise free the old string
    if (data->string)
    {
        string_Free(data->string);
        data->string = NULL;
    }
    // Create a copy of the new string
    if (string) data->string = string_Copy(string);
    else data->string = string_Copy("");
}

//  Free all the variables inside the Data
void 
data_Free(Data_t *data)
{
    string_Free(data->string);
    free(data);
}

//  Print the Data
void 
data_Print(Data_t *data)
{
    printf("(%d, %d, %d, %s)", data->x, data->y, data->z, data->string);
}

//  Compare Datas, return -1 if data_1 < data_2, return +1 if data_1 > data_2 
int 
data_Compare(Data_t *data_1, Data_t *data_2)
{
    if (data_1->x < data_2->x) return -1;
    if (data_1->x > data_2->x) return +1;

    if (data_1->y < data_2->y) return -1;
    if (data_1->y > data_2->y) return +1;

    if (data_1->z < data_2->z) return -1;
    if (data_1->z > data_2->z) return +1;

    return strcmp(data_1->string, data_2->string);
}

//  Compare Datas in Arrays (when array is **Data), used for qsort()
int
dataArray_Compare(const void *data_1, const void *data_2)
{
    Data_t **d_1 = (Data_t **) data_1;
    Data_t **d_2 = (Data_t **) data_2;
    return data_Compare(*d_1, *d_2);
}
