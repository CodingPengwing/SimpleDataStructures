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
    // buffer for reading words
    char buffer[MAXCHARS];
    // Input and output files
    FILE *fp_in = fopen(INPUT_FILE, "r");
    assert(fp_in);
    FILE *fp_out = fopen(OUTPUT_FILE, "w");
    assert(fp_out);

    // Create tree
    Tree_t *tree = tree_Create();
    int len;
    // Scan input and insert into tree
    while ((len = scan_word(buffer, MAXCHARS, fp_in)) >= 0)
    {
        if (!len) continue;
        Data_t data;
        data.string = buffer;
        data.frequency = 0;
        tree_insert(tree, &data);
    }
    // Print our trees in increasing order of Nodes
    tree_Print(tree);
    tree_Print_to_file(tree, fp_out);

    // Ensure everybody's freedom, recursively
    tree_Free(tree);
}
