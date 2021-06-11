#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#ifndef UTIL_H
#define UTIL_H

#define UNDEFINED -1

// Prints an error of the format "error: <error message>" and exits the
// program with a non-zero error code
void 
exit_with_error(char *error);

//  chr() gives the int values corresponding to each char.
//  It uses the ascii values of each char and modifies it
//  to fit into the range 0 - 62. This int value is then
//  used to calculate the hash value in data_Hash().
int char_to_int(char c);

// Checks the index to see if it's valid for the object's size
int 
check_index(size_t size, int index);

// Scans a line of input depending on the input_length parameter given
int
scan_line(char *line, size_t input_length);

// Create a new string
char *
string_Copy(char *string);

// Frees a string
void 
string_Free(char *string);

// Changes all new line characters to null byte
void
string_clean_newline(char *string);

#endif // UTIL_H
