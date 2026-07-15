#ifndef GAME_H
#define GAME_H
#include "Player.h"

class Game
{
    private:
        int time;
        int day;
        vector<string> vaccine;
        double vaccine_progress;
        Player player;
    public:
        // Constructor
        Game(vector<string> v, Player p);
        // Methods
        bool passTime(int t);
        bool nextDay();
};

#endif