#include "Data.h"
#include "Node.h"
#include "Tree.h"

// Max chars in a word, including null byte
#define MAXCHARS 51
// Input file
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int
main(int argc, char const *argv[])
{
    Tree_t *tree = tree_Create();
    char buffer[MAXCHARS];
    FILE *fp_in = fopen(INPUT_FILE, "r");
    assert(fp_in);
    FILE *fp_out = fopen(OUTPUT_FILE, "w");
    assert(fp_out);
    int len;
    while ((len = scan_word(buffer, MAXCHARS, fp_in)) >= 0)
    {
        if (!len) continue;
        Data_t data;
        data.string = buffer;
        data.frequency = 0;
        tree_insert(tree, &data);
    }
    // tree_Print(tree);
    tree_Print_to_file(tree, fp_out);
    tree_Free(tree);
}
