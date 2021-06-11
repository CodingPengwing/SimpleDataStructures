
#include "util.h"

// Prints an error of the format "error: <error message>" and exits the
// program with a non-zero error code
void 
exit_with_error(char *error) 
{
    assert(error);
    fprintf(stderr, "error: %s\n", error);
    exit(EXIT_FAILURE);
}

//  chr() gives the int values corresponding to each char.
//  It uses the ascii values of each char and modifies it
//  to fit into the range 0 - 62. This int value is then
//  used to calculate the hash value in data_Hash().
int char_to_int(char c) 
{
    int ascii = (int)c;

    // Digits ascii range
    if (48 <= ascii && ascii <= 57) 
        return ascii + 4;
    
    // Uppercase letters ascii range
    if (65 <= ascii && ascii <= 90) 
        return ascii - 39;
    
    // Lowercase letters ascii range
    if (97 <= ascii && ascii <= 122) 
        return ascii - 97;
    
    return UNDEFINED;
}

// Checks the index to see if it's valid for the object's size
int 
check_index(size_t size, int index)
{
    if (index < 0 || index >= size) 
        return false;
    return true;
}

// Scans a for line of input from stdin depending on the input_length parameter given
int
scan_line(char *line, size_t input_length) 
{
    if (!line) exit_with_error("Error: scan_line() was given NULL");

    size_t i = 0;
    if (fgets(line, input_length, stdin)) 
    {
        while (line[i]!= '\n') i++;
        return i;
    }
    return EOF;
}

// Create a new string
char *
string_Create(size_t length) 
{
    char *string = (char *) malloc(length * sizeof(char));
    if (!string) exit_with_error("Error: string_Create() failed to malloc");

    for (size_t i = 0; i < length; i++) 
        string[i] = '\0';
    return string;
}

// Frees a string
void 
string_Free(char *string) 
{
    if (!string) exit_with_error("Error: string_Free() was given NULL");
    free(string);
}

// Changes all new line characters to null byte
void
string_clean_newline(char *string)
{
    if (!string) exit_with_error("Error: string_CleanNewLine() was given NULL");

    for (size_t i = 0; i < strlen(string); i++)
    {
        if (string[i] == '\n')
            string[i] = '\0'; 
    }
}
