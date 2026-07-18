#include "Player.h"
#include <iostream>

// Constructors
    // Default constructor
    Player::Player()
    {
        name = "Unknown";
        char_name = "Unknown";
        character = 0;
        money = 0;
        exhaustion = 0;
        score = 0;
        reputation = 0;
        influence = 0;
        locations = Location();
    }
    // Parameterized constructor 
    Player::Player(string n, string cN, int c, int m, int e, int s, int r, int i, Location l, vector<vector<vector<string>>> d, vector<string> tD, vector<string> inv, vector<Location> lR, vector<string> v)
    {
        // Character is organized by the players personal identification name, however, dialogue in
        // the game is determined by which of the three characters is chosen at the beginning of the 
        // game, designated 'char_name'

        // Define validation variables
        int space_n = 0;
        char_name = cN;

        // Count number of spaces in player-entered name
        for (int i = 0; i < static_cast<int>(n.length()); i++)
        {
            // Find space
            if (n[i] == ' ')
            {
                space_n++;
            }
        }

        // Set name - invalid if player entered only spaces
        if ((space_n == static_cast<int>(n.length())) || (n == "") || (static_cast<int>(n.length()) > 20))
        {
            // For invalid name 
            name = "Unknown";
        }
        else
        {
            // Valid name
            name = n;
        }

        // Set character (for indexing dialogue)
        if ((c > 2) || (c < 0))
        {
            // Invalid character
            character = 0;
        }
        else
        {
            // valid character
            character = c;
        }

        // Set money
        if (m < 0)
        {
            // Invalid money
            money = 0;
        }
        else
        {
            // Valid money
            money = m;
        }

        // Set exhaustion
        if ((e > 20) || (e < 0))
        {
            // Invalid exhaustion
            exhaustion = 0;
        }
        else
        {
            // Valid exhaustion
            exhaustion = e;
        }

        // Set score
        if (s < 0)
        {
            // Invalid score
            score = 0;
        }
        else
        {
            // Valid score
            score = s;
        }

        // Set reputation
        if ((r > 10) || (r < 0))
        {
            // Invalid reputation
            reputation = 0;
        }
        else
        {
            // Valid reputation
            reputation = r;
        }

        // Set influence
        if ((i > 10) || (i < 0))
        {
            // Invalid influence
            influence = 0;
        }
        else
        {
            // Valid influence
            influence = i;
        }

        // Set location
        locations = l;

        dialogue = d;
        task_dialogue = tD;
        inventory = inv;
        location_repository = lR;

        day = 0;
        time = 24;

        vaccine = v;
        vaccine_progress = 0;
    }

// Getters
    // Return the players current location as a location object
    Location Player::getLocation()
    {
        return locations;
    }
    vector<Location> Player::getLocationRepository()
    {
        return location_repository;
    }
    // Return identifier of chosen character
    string Player::getCharName()
    {
        return char_name;
    }
    // Return the character identifying number for easy dialogue choices
    int Player::getCharacter()
    {
        return character;
    }
    // Return players reputation
    int Player::getReputation()
    {
        return reputation;
    }
    // Returns players black market influence
    int Player::getInfluence()
    {
        return influence;
    }
    // Returns players current balance of money
    int Player::getMoney()
    {
        return money;
    }

    int Player::getExhaustion()
    {
        return exhaustion;
    }

// Methods
    // Return the players reputation status with the NPCs 
    int Player::reputationStatus()
    {
        // Medium reputation
        if ((reputation >= 3) && (reputation < 8))
        {
            // Return statement
            return 1;
        }
        // High reputation
        else if ((reputation >= 8) && (reputation <= 10))
        {
            // Return statement 
            return 2;
        }
        // Low reputation - Default for invalid reputations
        else
        {
            // Return statement
            return 0;
        }
    }


    bool Player::changeLocation(Location l)
    {
        if (l.getUnlock())
        {
            locations = l;

            return true;
        }
        else
        {
            return false;
        }
    }

    void Player::updateLocation(Location l)
    {
        for (int i = 0; i < static_cast<int>(location_repository.size()); i++)
        {
            if (l.getName() == location_repository[i].getName())
            {
                location_repository[i] = l;

                if (locations.getName() == l.getName())
                {
                    locations = l;
                }
                return;
            }
        }
    }

    string Player::playerDialogue(int c, NPC n, vector<NPC> nR)
    {
        for (int i = 0; i < static_cast<int>(nR.size()); i++)
        {
            if (n.getName() == nR[i].getName())
            {
                return dialogue[i][character][c];
            }
        }

        return "No player dialogue found";
    }

    string Player::playerTaskDialogue(NPC n, vector<NPC> nR)
    {
        for (int i = 0; i < static_cast<int>(nR.size()); i++)
        {
            if (n.getName() == nR[i].getName())
            {
                return task_dialogue[i];
            }
        }

        return "No player intro task dialogue found";
    }

    vector<string> Player::getInventory()
    {
        return inventory;
    }

    void Player::addItemToInventory(string i)
    {
        inventory.push_back(i);
    }

    void Player::addEquipmentToInventory(string e)
    {
        inventory.push_back(e);
    }

    vector<string> Player::removeFromInventory(int i)
    {
        inventory.erase(inventory.begin() + i);

        return inventory;
    }

    void Player::setInventory(vector<string> i)
    {
        inventory = i;
    }

    void Player::setExhaustion(int e)
    {
        exhaustion = e;
    }

    int Player::getTime()
    {
        return time;
    }
    int Player::getDay()
    {
        return day;
    }
    int Player::getVaccineProgress()
    {
        return vaccine_progress;
    }
    vector<string> Player::getVaccine()
    {
        return vaccine;
    }

    void Player::setDay(int d)
    {
        day = d;
    }
    void Player::setTime(int t)
    {
        if (t <= 0)
        {
            time = 24 + t;
            day++;
        }
        else
        {
            time = t;
        }
    }
    void Player::setVaccineProgress(int p)
    {
        vaccine_progress = p;
    }


    void Player::setMoney(int m)
    {
        money = m;
    }

    void Player::setReputation(int r)
    {
        if (r > 10)
        {
            reputation = 10;
        }
        else if (r < 0)
        {
            reputation = 0;
        }
        else
        {
            reputation = r;
        }
    }