#ifndef NPCTASK_H
#define NPCTASK_H
#include "Task.h"

class NPCTask : public Task
{
    private:
        int friendship_change;

    public:
        NPCTask();
        NPCTask(string d, Item rI, Item i, int s, int fC);
        int getFriendshipChange();
};  

#endif