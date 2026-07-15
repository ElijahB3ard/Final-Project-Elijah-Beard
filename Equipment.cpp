#include "Equipment.h"

// Constructors
    // Default constructor
    Equipment::Equipment() : Item()
    {
        equipment_type = "void";
    }
    // Parameterized constructor
    Equipment::Equipment(string n, int c, int t, int re, int a, string eT) : Item(n, c, t, re, a)
    {
        // Equipment type:
        if (eT == "")
        {
            // Invalid type
            equipment_type = "Unknown";
        }
        else
        {
            // Valid type
            equipment_type = eT;
        }
    }