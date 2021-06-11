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
    char *string;
    int frequency;
};

//  Create a new piece of Data
Data_t *data_Create(char *string);

// Create a new copy of the given Data
Data_t *data_Copy(Data_t *data);

//  Free all the variables inside the Data
void data_Free(Data_t *data);

//  Print the Data
void data_Print(Data_t *data);

//  Print the Data to a file
void data_Print_to_file(Data_t *data, FILE *fp);

//  Compare Datas, return -1 if data_1 is smaller, return +1 if data_1 is larger
int data_Compare(Data_t *data_1, Data_t *data_2);

//  Compare Datas in Arrays (when array is **Data), used for qsort()
int dataArray_Compare(const void *data_1, const void *data_2);

#endif // DATA_H
