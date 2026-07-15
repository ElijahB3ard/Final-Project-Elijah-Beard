#include "Item.h"

// Constructors
    // Default Constructor
    Item::Item()
    {
        // Set all variables to 0 or void, and "Unknown" for easy identification of an error
        name = "Unknown";
        cost = 0;
        type = 0;
        reward = 0;
        attribute = 0;
    }
    // Parameterized Constructor
    Item::Item(string n, int c, int t, int re, int a)
    {
        // Set name:
        if (n == "")
        {
            // If invalid input
            name = "Unknown";
        }
        else
        {
            // valid input
            name = n;
        }

        // Set cost:
        if (c < 0)
        {
            // Invalid input
            cost = 0;
        }
        else
        {
            // Valid input
            cost = c;
        }

        // Set type:
        if ((t > 4) || (t < 0))
        {
            // Invalid type
            type = 0;
        }
        else
        {
            // Valid type
            type = t;
        }

        // Set reward:
        if (re < 0)
        {
            // Invalid reward
            reward = 0;
        }
        else
        {
            // Valid reward
            reward = re;
        }

        // Set attribute:
        if ((a > 4) || (a < 0))
        {
            // Invalid attribute
            attribute = 0;
        }
        else
        {
            // Valid attribute
            attribute = a;
        }
    }

// Methods
    // Return the formal name of the items 'type'
    string Item::typeName()
    {
        // First type: Vaccine
        if (type == 1)
        {
            return "vaccine";
        }
        // Second type: Equipment
        else if (type == 2)
        {
            return "equipment";
        }
        // Zero type: Void
        else
        {
            return "void";
        }
    }
    // Return the formal name of the items 'attribute'
    string Item::attributeName()
    {
        return "Unconstructed function";
    }

// Getters
    // Return item name
    string Item::getName()
    {
        return name;
    }
    // Return the cost of the item
    int Item::getCost()
    {
        return cost;
    }
    // Return the value of the reward from using the item
    int Item::getReward()
    {
        return reward;
    }