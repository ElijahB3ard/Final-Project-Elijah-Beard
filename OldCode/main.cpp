#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "game_functions.hpp"
using namespace std;

int main()
{
// Repository variables
    vector<Tasks> task_repository; Tasks new_task;
    vector<Items> item_repository; Items new_item;
    vector<NPCs> npc_repository; NPCs new_NPC;
    int tasks_quantity = 7;
    int items_quantity = 36;
    int npcs_quantity = 2;

// Populate repositories
    // Item repository
    for (int i = 0; i < items_quantity; i++)
    {
        new_item = initializeItems(i);
        item_repository.push_back(new_item);
    }

    // Task repsoitory
    for (int i = 0; i < tasks_quantity; i++)
    {
        new_task = initializeTasks(i, item_repository);
        task_repository.push_back(new_task);
    }

    // NPC repsoitory
    for (int i = 0; i < npcs_quantity; i++)
    {
        new_NPC = initializeNPCs(i, task_repository);
        npc_repository.push_back(new_NPC);
    }

// Player variables
    Player player;
    string player_name;

// Location variables
    Location farm = initializeLocation(0, task_repository, npc_repository);

// Character selection variables
    int characters_quantity = 4;

// Processor variables
    int choice;

// Display intro to the game
    newPage();
    displayIntro();

// Initialize character
    // I/O choose name
    cout << "Enter your name: ";
        cin >> player_name;

    // Show starting options
    newPage();
    displayCharacterOptions(item_repository, characters_quantity, farm);
    
    // I/O choose character
    newPage();
    cout << "Choose a character (1, 2, 3, 4): ";
        cin >> choice;

    // Initialize character formally
    player = initializePlayer(choice, item_repository, player_name, farm);

// Debug --------------------------------------------------------------------------
    player.addItem(item_repository[21]);
    player.addItem(item_repository[33]);
    player.addItem(item_repository[34]);
    player.addItem(item_repository[35]);
// Debug --------------------------------------------------------------------------

// The game loop
    // Manual condition
    while (choice != 0)
    {
        // Display stats
        newPage();
        cout << "Your stats: Energy: " << player.getEnergy() << " Money: " << player.getMoney() << " Time remaining: " << player.getTime() << endl;
        cout << endl;
    
        // Display map
        displayMap(player.getCurrentLocation());
        cout << endl;

        // Display location options
        displayOptions(item_repository, task_repository, npc_repository, player.getCurrentLocation());
        cout << endl;

        // I/O choose action
        cout << "Choose and option: ";
            cin >> choice;

        // execute action and update the player
        player = executeCommand(player, choice, task_repository);
        cout << endl;

        // I/O end game manual condition
        cout << "To end game, enter '0': ";
            cin >> choice;
    }

// Farmer::Farmer() : Character() <- inherited from


// DEBUG - Check Repositories
// Item
/*
    for (int i = 0; i < items_quantity; i++)
    {
        cout << "Item index:" << i << ": " << item_repository[i].getName() << endl;
    }
*/
/*
    //Task
    for (int i = 0; i < tasks_quantity; i++)
    {
        cout << "Task " << i + 1 << ": " << task_repository[i].getDescription() << endl;
        cout << "Required Item " << i + 1 << ": " << task_repository[i].getRequiredItem() << endl;
        cout << "Item reward " << i + 1 << ": " << task_repository[i].getItemReward().getName() << endl;
        cout << "Time " << i + 1 << ": " << task_repository[i].getTime() << endl;
        cout << endl;
    }
*/
/*
    //NPC
    for (int i = 0; i < npcs_quantity; i++)
    {
        cout << "NPC " << i + 1 << ": " << npc_repository[i].getName() << endl;
        cout << "NPC Task " << i + 1 << ": " << npc_repository[i].getTask().getDescription() << endl;
        cout << "Required Item: " << npc_repository[i].getTask().getRequiredItem() << endl;
        cout << "Required Reward: " << npc_repository[i].getTask().getItemReward().getName() << endl;
        cout << endl;
    }
*/

}