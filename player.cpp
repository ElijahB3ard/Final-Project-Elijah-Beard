#include "Player.h"

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
    Player::Player(string n, string cN, int c, int m, int e, int s, int r, int i, Location l)
    {
        // Character is organized by the players personal identification name, however, dialogue in
        // the game is determined by which of the three characters is chosen at the beginning of the 
        // game, designated 'char_name'

        // Define validation variables
        int space_n = 0;

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
    }

// Getters
    // Return identifier of chosen character
    int Player::getCharacter()
    {
        return character;
    }
    // Return players reputation
    int Player::getReputation()
    {
        return reputation;
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