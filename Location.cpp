#include "Location.h"

// Constructors
    // Default constructor
    Location::Location()
    {
        // Default variables
        name = "Unknown";
        tasks.push_back(Task());
        npcs.push_back(NPC());
        is_unlocked = false;
    }
    // Parameterized constructor
    Location::Location(string n, vector<Task> t, vector<NPC> npc, bool iU)
    {
        vector<Task> new_task_vector;
        vector<NPC> new_npc_vector;

        // Set name:
        if (n == "")
        {
            // Invalid name
            name = "unknown";
        }
        else
        {
            // Valid name
            name = n;
        }

        // Set tasks:
        if (static_cast<int>(t.size()) == 0)
        {
            // Invalid task vector
            new_task_vector.push_back(Task());
        }
        else
        {
            // Valid task vector
            new_task_vector = t;
        }
        tasks = new_task_vector;

        // Set npcs:
        if (static_cast<int>(npc.size()) == 0)
        {
            // Invalid npc vector
            new_npc_vector.push_back(NPC());
        }
        else
        {
            // Valid npc vector
            new_npc_vector = npc;
        }
        npcs = new_npc_vector;


        // Set locking condition:
        is_unlocked = iU;
    }

// Getters
    // Get the location name
    string Location::getName()
    {
        return name;
    }
    // Get the list of location tasks
    vector<Task> Location::getTasks()
    {
        return tasks;
    }
    // Get the list of location npcs
    vector<NPC> Location::getNPCs()
    {
        return npcs;
    }

    bool Location::getUnlock()
    {
        return is_unlocked;
    }

// Methods
    // Unlock the location
    void Location::unlock()
    {
        is_unlocked = true;
    }
    
    void Location::setNPC(int i, NPC n)
    {
        npcs[i] = n;
    }