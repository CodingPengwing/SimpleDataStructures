/*  Sanity check  */

#include "Node.h"
#include "Data.h"
#include "List.h"

int main(int argc, char const *argv[])
{
    List_t *list = list_Create();
    for (size_t i = 0; i < 5; i++)
    {
        Data_t *data = data_Create(i*4%6, 0, 0, "Cool");
        list_InsertBottom(list, data);
    }
    for (size_t i = 0; i < 5; i++)
    {
        Data_t *data = data_Create(i*6%4, 1, 1, "Beans");
        list_InsertBottom(list, data);
    }

    println("Original list:");
    list_Print(list);
    println("");

    println("Sorted list:");
    list_Sort(list);
    list_Print(list);
    println("");
    
    list_Free(list);
    return 0;
}
