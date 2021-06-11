
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "util.h"
#include "Data.h"
#include "Slot.h"

#define REHASH_REQUIRED -1

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct hashTable {
    Slot_t *table;
    size_t length;
} HashTable_t;

// Creates a new Hash Table, which is an array of Slots
HashTable_t *
hashTable_Create(size_t table_length);

// Frees a Hash Table
void 
hashTable_Free(HashTable_t *hashTable);

// Finds a free Slot to hash the Data into the table.
// If no free slots can be found the function returns REHASH_REQUIRED.
int 
hashTable_Find_Slot(HashTable_t *hashTable, Data_t *data, int shift_value);

// Inserts a Data into a Hash Table
void 
hashTable_Insert(HashTable_t *hashTable, Data_t *data, int index);

/* Prints a Hash Table
    0: <string>
    1: <string>
    2: <string>
    ...
*/
void 
hashTable_Print(HashTable_t *hashTable);

// Rehashes the Hash Table, recursively calling the function until the Hash Table
// is large enough to contain all previous Datas and the new Data being inserted
HashTable_t * 
hashTable_Rehash(HashTable_t *hashTable, Data_t *new_data, int shift_value, int RESIZE_FACTOR);

/*  Takes first line of input: N, M, K.
    N is the number of following input lines until the EOF.
    M is the size that the has table will be initialised to.
    K is the number that the hash functions will use to mod the hash value.
    Prints out the hash value for each string in each line.
*/
HashTable_t * 
hashTable_Fill(HashTable_t *hashTable, int num_input, int shift_value, FILE *file);

#endif // HASHTABLE_H
