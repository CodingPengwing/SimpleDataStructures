/*  Data class, change this according to whatever Data type or 
    structure that needs to be implemented. As long as all the 
    functions in here are well defined, the program will work.
*/

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "util.h"

#ifndef DATA_H
#define DATA_H

#define INPUT_SIZE 258
#define NEWLINE '\n'

// Multiply factor depends on the binary length of the input. 
// For now the length is assumed to be 6, which gives 2^6 = 64
#define MULTIPLY_FACTOR 64

// If you change Data definition, you *have to* change data_Create(),
// data_Free(), data_Print(), data_Compare() and data_Hash() functions
typedef struct data Data_t;
struct data {
    char *string;
};

//  Creates a new piece of Data
Data_t *data_Create(char *string);

//  Frees all the variables inside the Data
void data_Free(Data_t *data);

//  Prints the Data
void data_Print(Data_t *data);

// Calculates the hash value for a Data given the Hash Table's length
int data_Hash(Data_t *data, size_t hashTable_length);

// Returns a deep copy of the given Data
Data_t *data_Copy(Data_t *data);

// Testing the Data hashing functionality works.

/*  Takes first line of input: N, M, K.
    N is the number of following input lines until the EOF.
    M is the size that the has table will be initialised to.
    K is ignored in this function.
    Prints out the hash value for each string in each line.
*/
void test_data_Hash(int hashTable_length, int num_input, int shift_value, FILE *input_stream);

#endif // DATA_H
