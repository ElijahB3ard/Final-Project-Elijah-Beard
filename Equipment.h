#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "Item.h"

/*
Equipment types:
0 - void
1 - pickaxe
2 - axe
3 - fishing pole
4 - joja membership card
*/

class Equipment : public Item
{
    private:
        int equipment_type;
    
    public:
        Equipment();
        Equipment(string n, int c, int t, int re, int a, int eT);
        string equipmentName();
};

#endif