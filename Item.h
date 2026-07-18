#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

/*
Items are the heart of the game. Each item has a 'name' to distinguish it to the player. Most items can be sold for money, designated
by the 'cost' variable. Every item has a 'type'. An items type distinguishes what you can do with the item. Although all items can
be sold, only certain items can be consumed by the player, or used to plant crops, or are materials in which nothing can be done, or
are equipment, which has its own class which inherits from this one. Every item has a 'reward', which will only ever be nonzero for
consumables. This reward is returned as how much the item changes one of your stats when you consume it. Which stat is changed is 
designated by 'attribute', where the attribute designation gets passed to the player, telling it which stat to change.

Types:
0 - void
1 - vaccine
2 - equipment

Attribute: 
0 - void
1 - money
2 - exhaustion
3 - score
4 - reputation
5 - influence
*/

class Item
{
    private:
        string name;
        int cost;
        int type;
        int reward;
        int attribute;

    public:
        // Constructors
        Item();
        Item(string n, int c, int t, int re, int a);
        // Methods
        string typeName();
        string attributeName();
        // Getters
        string getName();
        int getCost();
        int getReward();
};

#endif