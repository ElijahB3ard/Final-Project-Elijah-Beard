#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include "Location.h"
#include "Task.h"

void newPage();

vector<Item> initializeItems();
vector<Equipment> initializeEquipment();
vector<Task> initializeTasks(vector<Item> iR, vector<Equipment> eR);
vector<NPCTask> initializeNpcTasks(vector<Item> iR, vector<Equipment> eR);
vector<NPC> initializeNPCs(vector<NPCTask> tR);
vector<Location> intiializeLocations(vector<Task> tR, vector<NPC> nR);

#endif