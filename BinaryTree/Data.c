
#include "Data.h"

//  Create a new piece of Data
Data_t *
data_Create(char *string)
{
    Data_t *data = (Data_t *)malloc(sizeof(*data));
    assert(data);
    if (string) data->string = string_Copy(string);
    else data->string = string_Copy("");
    return data;
}

// Create a new copy of the given Data
Data_t *
data_Copy(Data_t *data)
{
    Data_t *new = data_Create(data->string);
    new->frequency = data->frequency;
    return new;
}

// Update this data to new parameters. The current implementation prevents updating
// the string, as this would affect the correct ordering of the Data inside the Tree.
void data_Update(Data_t *data, int frequency)
{
    data->frequency = frequency;
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
    printf("(%3d - %s)", data->frequency, data->string);
}

//  Print the Data to a file
void 
data_Print_to_file(Data_t *data, FILE *fp)
{
    fprintf(fp, "(%3d - %s)", data->frequency, data->string);
}

//  Compare Datas, return -1 if data_1 < data_2, return +1 if data_1 > data_2
int 
data_Compare(Data_t *data_1, Data_t *data_2)
{
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
