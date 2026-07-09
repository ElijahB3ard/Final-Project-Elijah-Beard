#include "Item.h"

// Constructors
Item::Item()
{
    name = "Unknown";
    cost = 0;
    type = 0;
    reward = 0;
    attribute = 0;
}
Item::Item(string n, int c, int t, int re, int a)
{
    // Name - n
    if (n == "")
    {
        name = "Unknown";
    }
    else
    {
        name = n;
    }

    // Cost - c
    if (c < 0)
    {
        cost = 0;
    }
    else
    {
        cost = c;
    }

    // Type - t
    if ((t > 4) || (t < 0))
    {
        type = 0;
    }
    else
    {
        type = t;
    }

    // Reward - re
    if (re < 0)
    {
        reward = 0;
    }
    else
    {
        reward = re;
    }

    // Attribute - a
    if ((a > 4) || (a < 0))
    {
        attribute = 0;
    }
    else
    {
        attribute = a;
    }
}

// Methods

string Item::typeName()
{
    if (type == 1)
    {
        return "consumable";
    }
    else if (type == 2)
    {
        return "seed";
    }
    else if (type == 3)
    {
        return "material";
    }
    else if (type == 4)
    {
        return "equipment";
    }
    else
    {
        return "void";
    }
}
string Item::attributeName()
{
    if (attribute == 1)
    {
        return "energy";
    }
    else if (attribute == 2)
    {
        return "money";
    }
    else if (attribute == 3)
    {
        return "joja influence";
    }
    else if (attribute == 4)
    {
        return "map";
    }
    else if (attribute == 5)
    {
        return "score";
    }
    else
    {
        return "void";
    }
}

// Getters
string Item::getName()
{
    return name;
}
int Item::getCost()
{
    return cost;
}
int Item::getReward()
{
    return reward;
}