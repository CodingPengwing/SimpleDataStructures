/*  Sanity check  */

#include "Node.h"
#include "Data.h"
#include "List.h"

int main(int argc, char const *argv[])
{
    List_t *list = list_Create();
    int i;
    for (i = 3; i >= 0; i--)
    {
        Data_t *data = data_Create(i+i*4, 0, 0, "Cool");
        list_InsertBottom(list, data);
    }
    for (i = 2; i < 8; i++)
    {
        Data_t *data = data_Create(i*5%3, 0, 0, "SO cool");
        list_InsertBottom(list, data);
    }

    list_Print(list);
    list_Sort(list);
    list_Print(list);
    list_Free(list);
    return 0;
}
