#include <stdbool.h>
#include <assert.h>
#include "Data.h"

#ifndef SLOT_H
#define SLOT_H

// A slot in the Hash Table, the Hash Table contains M of these 
// Slots. If a Slot is occupied, that Slot has a Data hashed 
// into it. As such, the Hash Table is an array of Slots that can
// be indexed and hashed.
typedef struct slot {
    Data_t *data;
    bool occupied;
} Slot_t;

// Creates a new Slot
// These Slots will be what is contained in a Hash Table
Slot_t *
slot_Create();

// Checks whether a Slot is occupied
bool 
slot_Occupied(Slot_t *slot);

// Frees a Slot
void 
slot_Free(Slot_t *slot);

// Prints a Slot's Data
void 
slot_Print(Slot_t *slot);

// Inserts Data into a Slot. If the Slot is occupied, frees the old Data first.
void 
slot_Insert(Slot_t *slot, Data_t *data);

#endif // SLOT_H
