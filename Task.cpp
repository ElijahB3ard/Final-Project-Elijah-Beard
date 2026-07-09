#include "Task.h"

Task::Task()
{
    description = "void";
    required_item = Item();
    reward = Item();
    status = 0;
}

Task::Task(string d, Item rI, Item i, int s)
{
    if (d == "")
    {
        description == "Unknown";
    }
    else
    {
        description = d;
    }

    required_item = i;
    reward = i;
    
    if ((s > 2) || (s < 0))
    {
        status = 0;
    }
    else
    {
        status = s;
    }
}

void Task::setStatus(int s)
{
    status = s;
}

string Task::getDescription()
{
    return description;
}

Item Task::getRequiredItem()
{
    return required_item;
}

Item Task::completed(Item i)
{
    if ((status == 1) && (i.getName() == required_item.getName()))
    {
        status = 2;
        return reward;
    }
    else
    {
        return Item();
    }
}

string Task::statusName()
{
    if (status == 1)
    {
        return "started";
    }
    else if (status == 2)
    {
        return "complete";
    }
    else
    {
        return "not started";
    }
}