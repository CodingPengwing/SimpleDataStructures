/*  Data class file, change this file according to whatever data
    type or structure that needs to be implemented. As long as all
    the functions in here are well defined, the program will work.
*/

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "util.h"

#ifndef DATA_H
#define DATA_H

// If you change Data definition, you *have to* change data_Create(),
// data_Free(), data_Print(), data_Compare() and dataArray_Compare() functions
typedef struct data Data_t;
struct data {
    int x;
    int y;
    int z;
    char *string;
};

//  Create a new piece of Data
Data_t *data_Create(int x, int y, int z, char *string);

//  Free all the variables inside the Data
void data_Free(Data_t *data);

//  Print the Data
void data_Print(Data_t *data);

//  Compare Datas, return -1 if data_1 is smaller, return +1 if data_1 is larger
int data_Compare(Data_t *data_1, Data_t *data_2);

//  Compare Datas in Arrays (pointer to pointer to Data)
int dataArray_Compare(const void *data_1, const void *data_2);


Data_t *
data_Create(int x, int y, int z, char *string) 
{
    Data_t *data = (Data_t *) malloc(sizeof(*data));
    assert(data);
    data->x = x;
    data->y = y;
    data->z = z;

    size_t string_len = 1;
    if (string)
    {
        string_len += strlen(string);
        data->string = string_Create(string_len);
        strncpy(data->string, string, string_len);
    }
    else
        data->string = string_Create(string_len);
    
    return data;
}

void 
data_Free(Data_t *data)
{
    string_Free(data->string);
    free(data);
}

void 
data_Print(Data_t *data)
{
    printf("(%d, %d, %d, %s)", data->x, data->y, data->z, data->string);
}

int 
data_Compare(Data_t *data_1, Data_t *data_2)
{
    if (data_1->x < data_2->x) return -1;
    if (data_1->x > data_2->x) return +1;

    if (data_1->y < data_2->y) return -1;
    if (data_1->y > data_2->y) return +1;

    if (data_1->z < data_2->z) return -1;
    if (data_1->z > data_2->z) return +1;

    size_t len1 = strlen(data_1->string);
    size_t len2 = strlen(data_2->string);
    if (len1 == 0 && len2 != 0) return -1;
    if (len1 != 0 && len2 == 0) return +1;

    size_t n = (len1 < len2) ? len1 : len2;
    return strncmp(data_1->string, data_2->string, n);
}

int
dataArray_Compare(const void *data_1, const void *data_2)
{
    Data_t **d_1 = (Data_t **) data_1;
    Data_t **d_2 = (Data_t **) data_2;
    return data_Compare(*d_1, *d_2);
}

#endif