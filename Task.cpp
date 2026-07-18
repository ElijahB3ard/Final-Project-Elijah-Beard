#include "Task.h"

// Constructors
    // Default constructor
    Task::Task()
    {
        // Give default values
        description = "void";
        required_item = Item();
        reward = Item();
        equipment_reward = Equipment();
        status = 0;
        time = 0;
    }
    // Parameterized constructor
    Task::Task(string d, Item rI, Equipment rE, Item i, Equipment eR, int s, int t, int e)
    {
        // Set description
        if (d == "")
        {
            // Invalid description
            description = "Unknown";
        }
        else
        {
            // Valid description
            description = d;
        }

        // Default variables - unidentifiable
        required_item = rI;
        required_equipment = rE;
        reward = i;
        equipment_reward = eR;
        
        // Set status
        if ((s > 3) || (s < 0))
        {
            // Invalid status
            status = 0;
        }
        else
        {
            // Valid status
            status = s;
        }

        // Set time
        if ((t > 24) || (t < 0))
        {
            // Invalid time
            time = 0;
        }
        else
        {
            // Valid time
            time = t;
        }

        // Set exhaustion
        if ((e > 20) || (e < 0))
        {
            // Invalid value
            exhaustion = 0;
        }
        else
        {
            exhaustion = e;
        }
    }

// Methods
    // Increase the status
    void Task::nextStatus()
    {
        // Increment status
        status++;
    }
    void Task::setStatus(int s)
    {
        status = s;
    }

// Getters
    // Return task description
    string Task::getDescription()
    {
        return description;
    }
    // Return required item
    Item Task::getRequiredItem()
    {
        return required_item;
    }
    // Return required equipment
    Equipment Task::getRequiredEquipment()
    {
        return required_equipment;
    }
    // Return which stage in the task the player is at
    int Task::getStatus()
    {
        return status;
    }

// Debug
Item Task::getItemReward()
{
    return reward;
}
Equipment Task::getEquipmentReward()
{
    return equipment_reward;
}
int Task::getTime()
{
    return time;
}
int Task::getExhaustion()
{
    return exhaustion;
}
