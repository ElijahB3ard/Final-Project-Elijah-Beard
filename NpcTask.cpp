#include "NpcTask.h"

NPCTask::NPCTask() : Task()
{
    friendship_change = 0;
}

NPCTask::NPCTask(string d, Item rI, Item i, int s, int fC) : Task(d, rI, i, s)
{
    friendship_change = fC;
}

int NPCTask::getFriendshipChange()
{
    return friendship_change;
}

