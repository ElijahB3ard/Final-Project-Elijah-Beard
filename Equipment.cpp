#include "Equipment.h"

// Constructors
Equipment::Equipment() : Item()
{
    equipment_type = 0;
}
Equipment::Equipment(string n, int c, int t, int re, int a, int eT) : Item(n, c, t, re, a)
{
    if ((eT > 4) || (eT < 0))
    {
        equipment_type = 0;
    }
    else
    {
        equipment_type = eT;
    }
}

// Methods
string Equipment::equipmentName()
{
    if (equipment_type == 1)
    {
        return "pickaxe";
    }
    else if (equipment_type == 2)
    {
        return "axe";
    }
    else if (equipment_type == 3)
    {
        return "fishing pole";
    }
    else if (equipment_type == 4)
    {
        return "joja membership card";
    }
    else
    {
        return "void";
    }
}