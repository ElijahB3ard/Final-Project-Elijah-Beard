#ifndef NPCTASK_H
#define NPCTASK_H
#include "Task.h"

class NPCTask : public Task
{
    private:
        int friendship_change;

    public:
        // Constructors
        NPCTask();
        NPCTask(string d, Item rI, Equipment rE, Item i, Equipment e, int s, int t, int ex, int fC);
        // Getters
        int getFriendshipChange();
};  

#endif