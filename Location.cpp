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
            tasks.push_back(Task());
        }
        else
        {
            // Valid task vector
            tasks = t;
        }
        
        // Set npcs:
        if (static_cast<int>(npc.size()) == 0)
        {
            // Invalid npc vector
            npcs.push_back(NPC());
        }
        else
        {
            // Valid npc vector
            npcs = npc;
        }

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

// Methods
    // Unlock the location
    void Location::unlock()
    {
        is_unlocked = true;
    }