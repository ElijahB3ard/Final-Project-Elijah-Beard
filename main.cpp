#include "GameFunctions.h"
#include <thread>
#include <chrono>
#include <iostream>

int main()
{
    vector<Item> items = initializeItems();
    vector<Equipment> equipment = initializeEquipment();
    vector<Task> tasks = initializeTasks(items, equipment);
    vector<NPCTask> npc_tasks = initializeNpcTasks(items, equipment);
    vector<NPC> npcs = initializeNPCs(npc_tasks);
    vector<Location> locations = intiializeLocations(tasks, npcs);

    return 0;
}