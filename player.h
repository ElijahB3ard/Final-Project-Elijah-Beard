#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Location.h"

// The question is whether I want time and day to be a game function or a player function - It will be a game function

class Player
{
    private:
        string name;
        string char_name;
        int character;
        int money;
        int exhaustion;
        int score;
        int reputation;
        int influence;
        Location locations;
    
    public:
        // Constructors
        Player();
        Player(string n, string cN, int c, int m, int e, int s, int r, int i, Location l);
        // Methods
        int reputationStatus();
        bool changeStats(int r, int a);
        // Getters
        int getCharacter();
        int getReputation();
        
};

#endif