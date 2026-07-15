#include "Game.h"

// Constructors
    // Parameterized constructor
    Game::Game(vector<string> v, Player p)
    {
        // Game starts at day 0, and with 24 hours left on the first day
        time = 24;
        day = 0;

        // Game holds the vaccine and all items required to populate it
        if (static_cast<int>(v.size()) == 0)
        {
            // Invalid vaccine vector
            vaccine.push_back("Unknown");
        }
        else
        {
            // Valid vaccine vector
            vaccine = v;
        }

        // Player starts with no items for the vaccine
        vaccine_progress = 0;

        // The game holds the player
        player = p;
    }

// Methods
    // Subtract time of day. Return true if the day doesn't change
    bool Game::passTime(int t)
    {
        // Subtract 1 from 'time' for however many interations are called from the action 
        for (int i = 0; i < t; i++)
        {
            // Subtract time
            time--;

            // If time hits zero, return false (change day)
            if (time == 0)
            {
                // Return statement
                return false;
            }
        }

        // Return statement (If day doesnt need to change)
        return true;
    }
    // Move to next day. Return true if game doesnt end
    bool Game::nextDay()
    {
        // Change day by +1
        day++;

        // If day hits '8', return false, game will end
        if (day >= 8)
        {
            // Return statement
            return false;
        }

        // Return statement, game does not end
        return true;
    }