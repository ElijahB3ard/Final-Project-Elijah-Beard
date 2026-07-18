#include "NpcTask.h"

// Constructors
    // Default constructor
    NPCTask::NPCTask() : Task()
    {
        friendship_change = 0;
    }
    // Parameterized constructor
    NPCTask::NPCTask(string d, Item rI, Equipment rE, Item i, Equipment e, int s, int t, int ex, int fC) : Task(d, rI, rE, i, e, s, t, ex)
    {
        friendship_change = fC;
    }

// Getters
    // Returns the change in reputation from completing a task
    int NPCTask::getFriendshipChange()
    {
        return friendship_change;
    }