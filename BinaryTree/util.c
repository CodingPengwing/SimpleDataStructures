
#include "util.h"

// Prints an error of the format "error: <error message>" and exits the
// program with a non-zero error code
void 
exit_with_error(char *error) 
{
    fprintf(stderr, "error: %s\n", error);
    exit(EXIT_FAILURE);
}

void
println(char *string)
{
    printf("%s\n", string);
}

// Checks the index to see if it's valid for the object's size
int 
check_index(size_t size, int index)
{
    if (index < 0 || index >= size) 
        return 0;
    return 1;
}

// Scans a word from the input, returns length of the word.
int
scan_word(char *buffer, size_t buffer_len, FILE *fp)
{
    int read_length = 0;
    char tmp;
    while (read_length < buffer_len-1)
    {
        if ((tmp = fgetc(fp)) == EOF) return EOF;
        if (!isalnum(tmp) && tmp != SINGLE_QUOTE) break;
        buffer[read_length++] = tmp;
    }
    buffer[read_length] = NULL_BYTE;
    return read_length;
}

// Create a new string
char *
string_Copy(char *string) 
{
    if (!string) exit_with_error("Error in string_Copy(): NULL input.");
    size_t len = strlen(string);
    // Malloc 1 extra byte for null byte
    char *new_string = (char *)malloc((len+1)*sizeof(char));
    assert(new_string);
    strncpy(new_string, string, len);
    new_string[len] = '\0';
    return new_string;
}

// Free a string
void 
string_Free(char *string) 
{
    free(string);
}
