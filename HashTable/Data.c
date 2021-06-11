
#include "Data.h"

// Creates a Data containing a string. This function cannot be given a NULL
// because it a NULL pointer cannot be hashed. Empty strings should be given
// instead of NULL pointer.
Data_t *
data_Create(char *string) 
{
    if (string == NULL) exit_with_error("Error: data_Create() was given NULL");
    Data_t *data = (Data_t *) malloc(sizeof(*data));    
    assert(data);
    data->string = string_Copy(string);
    return data;
}

void 
data_Free(Data_t *data)
{
    if (!data)
        exit_with_error("Error: data_Free() was given NULL");
    string_Free(data->string);
    free(data);
}

void 
data_Print(Data_t *data)
{
    if (!data)
        exit_with_error("Error: data_Print() was given NULL");
    printf("%s", data->string);
}

// Hash the given Data
int data_Hash(Data_t *data, size_t hashTable_length)
{
    if (!data)
        exit_with_error("Error: data_Hash() was given NULL");

    int i = 0;
    int hashValue = 0;
    char current_char = data->string[0];

    // The final hashValue will depend on what the MULTIPLY_FACTOR is,
    // as the binary length is assumed to be 6, MULTIPLY_FACTOR is set to 64
    while (current_char != NEWLINE && i < strlen(data->string))
    {
        hashValue %= hashTable_length;
        hashValue *= (MULTIPLY_FACTOR % hashTable_length);
        hashValue %= hashTable_length;
        hashValue += (char_to_int(current_char) % hashTable_length);
        hashValue %= hashTable_length;

        i++;
        current_char = data->string[i];
    }

    return hashValue;
}

Data_t *
data_Copy(Data_t *data)
{
    if (!data)
        exit_with_error("Error: data_Copy() was given NULL");
    if (data->string == NULL)
        exit_with_error("Error: data_Copy() Data is undefined");
        
    return data_Create(data->string);
}


// Testing the Data hashing functionality works.

/*  Takes first line of input: N, M, K.
    N is the number of following input lines until the EOF.
    M is the size that the has table will be initialised to.
    K is ignored in this function.
    Prints out the hash value for each string in each line.
*/
void test_data_Hash(int hashTable_length, int num_input, int shift_value, FILE *input_stream) 
{
    // This string will contain the input string every time scan_line()
    // is called
    char input_string[INPUT_SIZE] = "";
    Data_t *input = &(Data_t) {.string = input_string};

    // Scan until EOF or N runs out
    while (num_input && (fgets(input_string, INPUT_SIZE, input_stream) != NULL)) 
    {   
        // Calculate hash value and print
        int hashValue = data_Hash(input, hashTable_length);
        printf("Hash value is %d for string %s", hashValue, input_string);
        num_input--;
    }
}
