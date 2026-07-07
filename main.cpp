#include <iostream>
#include <string>
#include <vector>
#include "game_functions.hpp"
using namespace std;

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
    newPage();
}
void displayCharacterOptions(vector<Items> item_repository, int characters_quantity, Location location)
{
    vector<Player> characters;
    vector<string> names = {"The Miner", "The Lumberjack", "The Villager", "The Traitor"};

    for (int i = 0; i < characters_quantity; i++)
    {
        characters.push_back(choosePlayerOrigins(i + 1, item_repository, "", location));
    }

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



void displayLocation(Location location)
{
    cout << "Current location: " << location.getName() << endl;
    cout << endl;
    for (int i = 0; i < location.getTaskQuantity(); i++)
    {
        cout << "Available task: " << location.getTask(i).getDescription() << endl;
        cout << "   Required Item: " << location.getTask(i).getRequiredItem() << endl;
        cout << "   Item reward: " << location.getTask(i).getItemReward().getName() << endl;
    }
    cout << endl;
    cout << "Location NPC Quantity: " << location.getNPCQuantity() << endl;
    for (int i = 0; i < location.getNPCQuantity(); i++)
    {
        cout << "NPC: " << location.getNPC(i).getName() << endl;
        cout << "   NPC Task: " << location.getNPC(i).getTask().getDescription() << endl;
        cout << "   NPC Task Reward: " << location.getNPC(i).getTask().getItemReward().getName() << endl;
    }
    cout << endl;
    cout << "Trash: " << location.getTrash() << endl;
}

int main()
{
// Define variables
    // Population Variables
    vector<Tasks> task_repository;
    vector<Items> item_repository;
    vector<NPCs> npc_repository;
    Tasks new_task;
    Items new_item;
    NPCs new_NPC;
    string player_name;
    int characters_quantity = 4;
    int tasks_quantity = 7;
    int items_quantity = 36;
    int npcs_quantity = 2;
    int choice;
    Location location;

    Player player;

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

    Location farm = initializeLocation(0, task_repository, npc_repository);

// Begin Game!!
    newPage();
    displayIntro();
    cout << "Enter your name: ";
        cin >> player_name;
    newPage();
    displayCharacterOptions(item_repository, characters_quantity, farm);
    cout << "Choose a character (1,2,3,4): ";
        cin >> choice;
    player = choosePlayerOrigins(choice, item_repository, player_name, farm);
    newPage();
    cout << "Your name: " << player.getName() << endl;
    cout << "Your gold: " << player.getMoney() << endl;
    cout << "Your energy: " << player.getEnergy() << endl;
    cout << "Your starting item: " << player.getInventory()[0].getName() << endl;
    newPage();
    

// DEBUG - Check Repositories
// Item
/*
    for (int i = 0; i < items_quantity; i++)
    {
        cout << "Item index:" << i << ": " << item_repository[i].getName() << endl;
    }

    Task
    for (int i = 0; i < tasks_quantity; i++)
    {
        cout << "Task " << i + 1 << ": " << task_repository[i].getDescription() << endl;
        cout << "Required Item " << i + 1 << ": " << task_repository[i].getRequiredItem() << endl;
        cout << "Item reward " << i + 1 << ": " << task_repository[i].getItemReward().getName() << endl;
        cout << endl;
    }
    NPC
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