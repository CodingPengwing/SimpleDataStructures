
#include "HashTable.h"

// Creates a new Hash Table, which is an array of Slots
HashTable_t *
hashTable_Create(size_t table_length)
{
    HashTable_t *hashTable = (HashTable_t *) malloc(sizeof(HashTable_t));
    if (!hashTable)
        exit_with_error("Error: hashTable_Create() failed to malloc");

    hashTable->table = (Slot_t *) malloc(table_length * sizeof(Slot_t));
    if (!hashTable->table)
        exit_with_error("Error: hashTable_Create() failed to malloc");

    for (size_t i = 0; i < table_length; i++) 
        hashTable->table[i] = *slot_Create();

    hashTable->length = table_length;
    return hashTable;
}

// Frees a Hash Table
void 
hashTable_Free(HashTable_t *hashTable)
{
    if (!hashTable)
        exit_with_error("Error: hashTable_Free() was given NULL");

    for (size_t i = 0; i < hashTable->length; i++) 
        slot_Free(&hashTable->table[i]);

    free(hashTable);
}

// Finds a free Slot to hash the Data into the table.
// If no free slots can be found the function returns REHASH_REQUIRED.
int 
hashTable_Find_Slot(HashTable_t *hashTable, Data_t *data, int shift_value)
{
    if (!hashTable || !data)
        exit_with_error("Error: hashTable_Find_Slot() was given NULL");

    int initial_hashValue;
    int new_hashValue;
    new_hashValue = initial_hashValue = data_Hash(data, hashTable->length);

    // if the slot is occupied calculate new hashValue
    while (slot_Occupied(&hashTable->table[new_hashValue])) 
    {
        new_hashValue += shift_value;
        new_hashValue = new_hashValue % hashTable->length;
        // if the hashValue has looped a full cycle, a rehash is needed
        if (new_hashValue == initial_hashValue) 
            return REHASH_REQUIRED;
    }
    return new_hashValue;
}

// Inserts a Data into a Hash Table
void 
hashTable_Insert(HashTable_t *hashTable, Data_t *data, int index)
{
    if (!hashTable || !data)
        exit_with_error("Error: hashTable_Insert() was given NULL");

    slot_Insert(&hashTable->table[index], data);
}

/* Prints a Hash Table
    0: <string>
    1: <string>
    2: <string>
    ...
*/
void 
hashTable_Print(HashTable_t *hashTable)
{
    if (!hashTable)
        exit_with_error("Error: hashTable_Print() was given NULL");

    for (int i = 0; i < hashTable->length; i++) 
    {
        printf("%d: ", i);
        slot_Print(&hashTable->table[i]);
        printf("\n");
    }
}

// Rehashes the Hash Table, recursively calling the function until the Hash Table
// is large enough to contain all previous Datas and the new Data being inserted
HashTable_t * 
hashTable_Rehash(HashTable_t *hashTable, Data_t *new_data, int shift_value, int RESIZE_FACTOR)
{    
    if (!hashTable || !new_data)
        exit_with_error("Error: hashTable_Insert() was given NULL");

    // Initial RESIZE_FACTOR is always 2, however as the function
    // recurses this will be 2^n , n being the number of times
    // the function has been called

    int current_length = hashTable->length;

    // Make a new table with the new size
    int new_length = current_length * RESIZE_FACTOR; 
    HashTable_t *new_hashTable = hashTable_Create(new_length);

    Slot_t *current_slot;
    Data_t *data_to_insert;
    int hashValue;

    // The loop with process all previous Datas up to M times, when it
    // reaches the (M+1) iteration, all previous Datas have been processed
    // and we now need to process the final new_data
    for (size_t i = 0; i < current_length + 1; i++) 
    {
        // If we are still processing all the old Datas
        if (i < current_length) 
        {   
            current_slot = &hashTable->table[i];
            // If the Slot is not occupied then move on to find an occupied one
            if (!slot_Occupied(current_slot))
                continue;
            data_to_insert = data_Copy(current_slot->data);
        } 
        // Finished processing old Datas, now try to insert new_data
        else
            data_to_insert = new_data;
        
        // Find a free Slot in the Hash Table for our Data
        hashValue = hashTable_Find_Slot(new_hashTable, data_to_insert, shift_value);
        
        // If there is space in the Hash Table, insert the Data
        if (hashValue != REHASH_REQUIRED)  
            hashTable_Insert(new_hashTable, data_to_insert, hashValue);

        // Otherwise, we need to rehash again. Double RESIZE_FACTOR, free the new
        // Hash Table that has just been made and recursively call the function
        // again with the new RESIZE_FACTOR
        else
        {
            RESIZE_FACTOR *= 2;
            hashTable_Free(new_hashTable);
            return hashTable_Rehash(hashTable, new_data, shift_value, RESIZE_FACTOR);
        } 
    }

    // Once every Data has been hashed into a new table, we can
    // replace the old table with the new table
    hashTable_Free(hashTable);
    return new_hashTable;
}



/*  Takes first line of input: N, M, K.
    N is the number of following input lines until the EOF.
    M is the size that the has table will be initialised to.
    K is the number that the hash functions will use to mod the hash value.
    Prints out the hash value for each string in each line.
*/
HashTable_t * 
hashTable_Fill(HashTable_t *hashTable, int num_input, int shift_value, FILE *file) {

    int hashValue;
    // RESIZE_FACTOR in case we need to rehash our table, for now we are doubling the size each time
    const int RESIZE_FACTOR = 2;

    // This string will contain the input string every time fgets() is called
    char input[INPUT_SIZE] = "";

    // Scan until EOF or num_input runs out
    while (num_input && (fgets(input, INPUT_SIZE, file) != NULL)) 
    {
        string_clean_newline(input);
        Data_t *data = data_Create(input);
        // Find a free Slot
        hashValue = hashTable_Find_Slot(hashTable, data, shift_value);

        // If rehash is not required, insert Data
        if (hashValue != REHASH_REQUIRED) 
            hashTable_Insert(hashTable, data, hashValue);
        
        // Else rehash the Hash Table until it is large enough to contain all 
        // previous Datas and the new Data
        else 
            hashTable = hashTable_Rehash(hashTable, data, shift_value, RESIZE_FACTOR);
        
        num_input--;
    }
    return hashTable;
}
