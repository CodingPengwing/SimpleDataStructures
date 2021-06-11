
#include "Slot.h"

// Creates a new Slot
// These Slots will be what is contained in a Hash Table
Slot_t *
slot_Create()
{
    Slot_t *slot = (Slot_t *) malloc(sizeof(*slot));
    if (!slot)
        exit_with_error("Error: slot_Create() failed to malloc");

    slot->data = NULL;
    slot->occupied = false;
    return slot;
}

// Checks whether a Slot is occupied
bool 
slot_Occupied(Slot_t *slot)
{
    if (!slot)
        exit_with_error("Error: slot_Occupied() was given NULL");

    return slot->occupied;
}

// Frees a Slot
void 
slot_Free(Slot_t *slot)
{
    if (!slot)
        exit_with_error("Error: slot_Free() was given NULL");

    if (slot_Occupied(slot)) 
        data_Free(slot->data);

    // Only free the Slot pointer if "table" variable inside HashTable_t was 
    // declared as Slot_t ** . Then in HashTable_Create(), we would also need
    // to malloc() each individual Slot.

    // Otherwise leave it commented.
    //free(slot);
}

// Prints a Slot's Data
void 
slot_Print(Slot_t *slot)
{
    if (!slot)
        exit_with_error("Error: slot_Print() was given NULL");

    if (slot_Occupied(slot))
        data_Print(slot->data);
}

// Inserts Data into a Slot. If the Slot is occupied, frees the old Data first.
void 
slot_Insert(Slot_t *slot, Data_t *data)
{
    if (!slot || !data)
        exit_with_error("Error: slot_Insert() was given NULL");

    if (slot_Occupied(slot))
        data_Free(slot->data);
    slot->data = data;
    slot->occupied = true;
}
