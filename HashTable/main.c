
#include <string.h>

#include "util.h"
#include "Data.h"
#include "HashTable.h"

#define TEST false

int main(int argc, char const *argv[])
{   
    int N, M, K;
    FILE *input_stream = stdin;
    char input[INPUT_SIZE] = "";

    // Scan first line for N, M and K
    // N being number of inputs
    // M being hashTable size
    // K being the shift value 
    fgets(input, INPUT_SIZE, input_stream);
    sscanf(input, "%d %d %d", &N, &M, &K);

    int num_input = N;
    int hashTable_length = M;
    int shift_value = K;

    if (TEST)
    {
        // this is to test the hash function works for the given input, if this function
        // is used, hashTable_Fill() can not be used because the input is already consumed
        test_data_Hash(hashTable_length, num_input, shift_value, input_stream);
    }

    else
    {
        // Create a Hash Table
        HashTable_t *hashTable = hashTable_Create(hashTable_length);
        
        // Fill the Hash Table with data from the input_stream
        hashTable = hashTable_Fill(hashTable, num_input, shift_value, input_stream);

        printf("Here's the Hash Table: \n");
        // Print the Hash Table
        hashTable_Print(hashTable);
        hashTable_Free(hashTable);
    }
    
    return 0;
}
