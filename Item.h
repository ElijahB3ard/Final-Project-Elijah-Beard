#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

/*
Types:
0 - void
1 - consumable
2 - seed
3 - material
4 - equipment

Rarities:
0 - void
1 - common
2 - rare
3 - precious

Attribute: 
0 - void
1 - energy
2 - money
3 - joja influence
4 - map
5 - score
*/

class Item
{
    private:
        string name;
        int cost;
        int type;
        int rarity;
        int reward;
        int attribute;

    public:
        Item();
        Item(string n, int c, int t, int r, int re, int a);
        string rarityName();
        string typeName();
        string attributeName();
        string getName();
        int getCost();
        int getReward();
};

#endif