#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
using namespace std;

// Display Functions
void newPage()
{
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }
}
void displayIntro()
{
    string dummy;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "                    Welcome to Stardew Valley" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "                          Elijah Beard" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Press 'enter' to continue ";
        cin >> dummy;
}
void displayCharacterOptions(vector<Items> item_repository, int characters_quantity, Location location)
{
// Define variables
    vector<Player> characters;
    vector<string> names = {"The Miner", "The Lumberjack", "The Villager", "The Traitor"};

// Populate character vector with possible characters (dummy characters)
    for (int i = 0; i < characters_quantity; i++)
    {
        characters.push_back(initializePlayer(i + 1, item_repository, "", location));
    }

// Output
    cout << "-----------------------------------------------------------------" << endl;
    cout << "                      Character Selection" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;
    for (int i = 0; i < characters_quantity; i++)
    {
        cout << "--- " << names[i] << " ---" << endl;
        cout << "Gold: " << characters[i].getMoney() << endl;
        cout << "Energy: " << characters[i].getEnergy() << endl;
        cout << "Starting Item: " << characters[i].getInventory()[0].getName() << endl;
        cout << endl;
    }
}
void displayOptions(vector<Items> item_repository, vector<Tasks> task_repository, vector<NPCs> npc_repository, Location location)
{
// Display
    cout << "------------ The menu: ------------" << endl;

// Display options for:
// œ∑´®†¥¨œ∑´®†¥¨ˆøˆ¨¥†®´∑´®†¥¨ˆøThe Farm
    if (location.getName() == "Farm")
    {
    // Display Tasks
        cout << "1. " << task_repository[6].getDescription() << endl;
        for (int i = 0; i < 5; i++)
        {
            if (location.getLocationProgress() == i)
            {
                cout << "2. " << task_repository[i + 1].getDescription() << endl;
            }
        }

    // Talk to NPCs
        cout << "3. Talk to " << npc_repository[1].getName() << endl;
        cout << "4. View inventory" << endl;
    }
}
void displayMap(Location location)
{
    if (location.getName() == "Farm")
    {
        cout << "------------------ The Farm --------------------" << endl;
        cout << "       |            |  |                 |" << endl;
        cout << "       |____________| ˚|_________________|" << endl;
        cout << "          |""""|" << endl;
        cout << "          |~~~~|" << endl;
        cout << endl;
        cout << endl;
        if (location.getLocationProgress() == 0)
        {
            cout << "               ___________________" << endl;
            cout << "              /|                 |" << endl;
            cout << "              ||                 |" << endl;
            cout << "              ||                 |" << endl;
            cout << "              ||_________________|" << endl;
            cout << "              |/----------------/" << endl;
        }
        else if (location.getLocationProgress() == 1)
        {
            cout << "               ___________________" << endl;
            cout << "              /|~~~~~~~~~~~~~~~~~|" << endl;
            cout << "              ||~~~~~~~~~~~~~~~~~|" << endl;
            cout << "              ||~~~~~~~~~~~~~~~~~|" << endl;
            cout << "              ||_________________|" << endl;
            cout << "              |/----------------/" << endl;
        }
        else if (location.getLocationProgress() == 2)
        {
            cout << "               ___________________" << endl;
            cout << "              /| | | | | | | | | |" << endl;
            cout << "              ||| | | | | | | | ||" << endl;
            cout << "              || | | | | | | | | |" << endl;
            cout << "              ||_________________|" << endl;
            cout << "              |/----------------/" << endl;
        }
        else if (location.getLocationProgress() == 3)
        {
            cout << "               ___________________" << endl;
            cout << "              /|~o~~~o~~~o~~~o~~~|" << endl;
            cout << "              ||~~~o~~~o~~~o~~~O~|" << endl;
            cout << "              ||~~o~~~o~~~o~~~o~~|" << endl;
            cout << "              ||_________________|" << endl;
            cout << "              |/----------------/" << endl;
        }
        else if (location.getLocationProgress() == 4)
        {
            cout << "               ___________________" << endl;
            cout << "              /|§ § § § § § § § §|" << endl;
            cout << "              || § § § § § § § § |" << endl;
            cout << "              ||§ § § § § § § § §|" << endl;
            cout << "              ||_________________|" << endl;
            cout << "              |/----------------/" << endl;
        }
        cout << endl;
        cout << "------------------------------------------------" << endl;
    }
}



// Execution Functions
Player executeCommand(Player player, int choice, vector<Tasks> task_repository)
{
// Initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 4); 

// Define variables
    Location location_beta = player.getCurrentLocation();
    Player player_beta = player;
    bool found = false;
    int loc_progress = location_beta.getLocationProgress();
    int dialogue_option = distrib(gen);

    int count;
                vector<Items> inventory = player_beta.getInventory();
                Items item;
                item.setName("BIG HARRY BALL SACK");
                vector<Items> unique = {item};
                vector<int> counts;
                bool is_unique = false;            
    


// Execute command for:
// The Farm
    if (player.getCurrentLocation().getName() == "Farm")
    {
    // Find player choice
    // Execute command
        switch(choice)
        {
        // Rest option
            case 1: // Task1400, task[6]
            // Output
                cout << "You chose: " << task_repository[6].getDescription() << endl;
                cout << endl;
                cout << "You slept like a baby! (energy +" << task_repository[6].getAttributeReward() << ") (time -" << task_repository[6].getTime() << ")" << endl;
            
            // Change player attributes 
                player_beta.setEnergy(task_repository[6].getAttributeReward() + player_beta.getEnergy());
                player_beta.setTime(player_beta.getTime() - task_repository[6].getTime());
            
            // Break statement
                break;
            
        // Crop options
            case 2: // Till, Planet, Harvest
                switch (loc_progress)
                {
                // Define task based off location progress
                // No farm progress
                    case 0: // Task1100, task[1]
                    // Output
                        cout << "You chose: " << task_repository[1].getDescription() << endl;
                        cout << endl;

                    // Determine player ability to do task
                        for(int i = 0; i < static_cast<int>(player_beta.getInventory().size()); i++)
                        {
                        // Execute if player can do task
                            if (player_beta.getInventory()[i].getEquipmentType() == "hoe")
                            {
                            // Output
                                cout << "You tilled soil! You can now plant seeds! (Time -" << task_repository[1].getTime() << ")" << endl;
                            
                            // Change location attributes
                                location_beta.setLocationProgress(1);

                            // Change player attributes
                                player_beta.setTime(player_beta.getTime() - task_repository[1].getTime());

                            // Update the player ability condition
                                found = true;

                            // Exit for loop
                                break;
                            }
                        }

                    // If player cannot do task
                        if (found == false)
                        {
                        // Output
                            cout << "You need a hoe to till soil!" << endl;
                        }
                    
                    // Break statement
                        break;

                // Soil has been tilled and is ready for seeds
                    case 1: // Task1200, task[2]
                    // Output
                        cout << "You chose: " << task_repository[2].getDescription() << endl;
                        cout << endl;

                    // Determine player ability to do task
                        for(int i = 0; i < static_cast<int>(player_beta.getInventory().size()); i++)
                        {
                        // Execute if player can do task
                            if (player_beta.getInventory()[i].getEquipmentType() == "seed")
                            {
                            // Output
                                cout << "You planeted " << player_beta.getInventory()[i].getName() << "! You can harvest in 2 days! (time -"
                                    << task_repository[2].getTime() << ")" << endl;

                            // Update location progress based on which seeds were planted
                                if (player_beta.getInventory()[i].getName() == "wheat seeds")
                                {
                                // Allow for wheat to be harvested
                                    location_beta.setLocationProgress(2);
                                }
                                else if (player_beta.getInventory()[i].getName() == "melon seeds")
                                {
                                // Allow for melon to be harvested
                                    location_beta.setLocationProgress(3);
                                }
                                else if (player_beta.getInventory()[i].getName() == "corn seeds")
                                {
                                // Allow for corn to be harvested
                                    location_beta.setLocationProgress(4);
                                }

                            // Change player attributes
                                player_beta.setTime(player_beta.getTime() - task_repository[1].getTime());

                            // Remove seeds from inventory
                                player_beta.removeItem(player_beta.getInventory()[i].getName());

                            // Update the player ability condition
                                found = true;
                            
                            // Exit the loop
                                break;
                            }
                        }

                    // If player cannot do task
                        if (found == false)
                        {
                        // Output
                            cout << "You need seeds to plant crops!" << endl;
                        }
                    
                    // Break statement
                        break;

                // Wheat planeted and ready to be harvested
                    case 2: // Task1301, task[3]
                    // Output
                        cout << "You chose: " << task_repository[loc_progress + 1].getDescription() << endl;
                        cout << endl;
                        cout << "You harvested 5 " << task_repository[loc_progress + 1].getItemReward().getName() << "! (time -" << task_repository[loc_progress + 1].getTime() << ")" << endl;
                        
                    // Add 5 wheat to inventory
                        for (int i = 0; i < 5; i++)
                        {
                            player_beta.addItem(task_repository[loc_progress + 1].getItemReward());
                        }

                    // Reset location progress
                        location_beta.setLocationProgress(0);

                    // Break statement
                        break;

                // Melon planted and ready to be harvested
                    case 3: // Task1302, task[4]
                    // Output
                        cout << "You chose: " << task_repository[loc_progress + 1].getDescription() << endl;
                        cout << endl;
                        cout << "You harvested 5 " << task_repository[loc_progress + 1].getItemReward().getName() << "! (time -" << task_repository[loc_progress + 1].getTime() << ")" << endl;
                        
                    // Add 5 melon to inventory
                        for (int i = 0; i < 5; i++)
                        {
                            player_beta.addItem(task_repository[loc_progress + 1].getItemReward());
                        }
                    
                    // Reset location progress
                        location_beta.setLocationProgress(0);

                    // Break statement
                        break;

                // Corn planted and ready to be harvested 
                    case 4: // Task1303, task[5]
                    // Output
                        cout << "You chose: " << task_repository[loc_progress + 1].getDescription() << endl;
                        cout << endl;
                        cout << "You harvested 5 " << task_repository[loc_progress + 1].getItemReward().getName() << "! (time -" << task_repository[loc_progress + 1].getTime() << ")" << endl;
                        
                    // Add 5 corn to inventory
                        for (int i = 0; i < 5; i++)
                        {
                            player_beta.addItem(task_repository[loc_progress + 1].getItemReward());
                        }
                    
                    // Reset location progress
                        location_beta.setLocationProgress(0);

                    // Break statement
                        break;
                }

            // Break crop options
                break;
        
        // Speak with NPC
            case 3: // Npc1, NPC[1]
            // Define variable
                
            
            // Output
                cout << "You chose to talk to " << location_beta.getNPC(1).getName() << "!" << endl;
                cout << endl;
                cout << "Howler: ";

            // Random Output
                if (player_beta.getFriendship() > 2)
                {
                    switch (dialogue_option)
                    {
                        case 1:
                            cout << "Ruff Ruff!" << endl;
                            break;
                        case 2:
                            cout << "Woof Woof!" << endl;
                            break;
                        case 3:
                            cout << "Woof!" << endl;
                            break;
                        case 4:
                            cout << "*Wags tail violently*" << endl;
                            break;
                    }
                }
                else
                {
                    switch (dialogue_option)
                    {
                        case 1:
                            cout << "Grrrrrr" << endl;
                            break;
                        case 2:
                            cout << "Grrrrrrrrrrr" << endl;
                            break;
                        case 3:
                            cout << "*Whine*" << endl;
                            break;
                        case 4:
                            cout << "Hmph" << endl;
                            break;
                    }
                }

            // Break statement
                break;
//œ∑´®†¥ˆ¬∆˚©ƒ∂ß≈∂∆©¬˙ View inventory
            case 4:
/*
                for (int i = 0; i < static_cast<int>(inventory.size()); i++)
                {
                    cout << "Nonunique " << i + 1 << ": " << inventory[i].getName() << endl;
                }
*/

                newPage();
                // iterate through inventory. The first time an element appears, add it to unique, but if it appears again, do not add it to unique
                for (int i = 0; i < static_cast<int>(inventory.size()); i++)
                {
                    cout << "Inventory[" << i << "] = " << inventory[i].getName() << endl;
                    cout << "   unique.size() = " << static_cast<int>(unique.size()) << endl;

                    cout << endl;
                    cout << endl;
                    cout << "THIS IS THE UNIQUE VECTOR --BEFORE--: ";
                    for (int k = 0; k < static_cast<int> (unique.size()); k++)
                    {
                        cout << unique[k].getName() << "   ";
                    }
                    cout << endl;
                    cout << endl;
                    for (int j = 0; j < static_cast<int>(unique.size()); j++)
                    {
                        if (inventory[i].getName() != unique[j].getName())
                        {
                            unique.push_back(inventory[i]);
                        }
                    }

                    cout << endl;
                    cout << endl;
                    cout << "THIS IS THE UNIQUE VECTOR --AFTER--: ";
                    for (int k = 0; k < static_cast<int> (unique.size()); k++)
                    {
                        cout << unique[k].getName() << "   ";
                    }
                    cout << endl;
                    cout << endl;
                }
                


                for (int i = 0; i < static_cast<int>(unique.size()); i++)
                {
                    cout << "Unique " << i + 1 << ": " << unique[i].getName() << endl;
                }

                cout << "--------------------------------------------------------------------------" << endl;
                cout << "Your inventory:" << endl;
                for (int i = 0; i < player_beta.getInventory().size(); i++)
                {
                    count = 0;

                    for (int j = 0; j < player_beta.getInventory().size(); j++)
                    {
                        if (inventory[i].getName() == inventory[j].getName())
                        {
                            count++;
                        }
                    }

                    counts.push_back(count);

                }

                for (int i = 0; i < static_cast<int>(unique.size()); i++)
                {
                    cout << "[" << counts[i] << "] - " << unique[i].getName() << endl;
                }
                break;
        } // End of switch statement
    } // End of location condition

// Update player/ location attributes
    player_beta.setLocation(location_beta);

// Return statement
    return player_beta;
}







