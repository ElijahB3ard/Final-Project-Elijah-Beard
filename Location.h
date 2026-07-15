#ifndef LOCATION_H
#define LOCATION_H
#include "Task.h"
#include "NPC.h"

/*
Every location has a 'name' which is displayed to the player for identification. Every location will have 'tasks' which the player can 
perform, whether that be resting or harvesting materials or contributing to the vaccine and such. Every location has 'npcs' that you
can speak with, and which can give you tasks
*/

class Location
{
    private:
        string name;
        vector<Task> tasks;
        vector<NPC> npcs;
        bool is_unlocked;

    public:
        // Constructors
        Location();
        Location(string n, vector<Task> t, vector<NPC> npc, bool iU);
        // Getters
        string getName();
        vector<Task> getTasks();
        vector<NPC> getNPCs();
        // Method
        void unlock();
};

#endif