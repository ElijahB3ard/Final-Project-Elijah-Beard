#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "Item.h"

/*
The equipment class inherits from the item class. A piece of equipment is an item, but with a special designation as to
which piece of equipment it is. This is needed because different types of equipment are used for different tasks
*/

class Equipment : public Item
{
    private:
        string equipment_type;
    
    public:
        // Constructors
        Equipment();
        Equipment(string n, int c, int t, int re, int a, string eT);
};

#endif