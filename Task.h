#ifndef TASK_H
#define TASK_H
#include <string>
#include "Equipment.h"
using namespace std;

// Every task has a description, and if the task is complete, you will recieve some sort of reward
/*
Status:
0 - not started
1 - started - no item
2 - has item
*/
class Task
{
    private:
        string description;
        Item required_item;
        Equipment required_equipment;
        Item reward;
        Equipment equipment_reward;
        int status;
        int time;
        int exhaustion;

    public:
        // Constructors
        Task();
        Task(string d, Item rI, Equipment rE, Item i, Equipment eR, int s, int t, int e);
        // Methods
        void nextStatus();
        void setStatus(int s);
        // Getters
        string getDescription();
        Item getRequiredItem();
        Equipment getRequiredEquipment();
        int getStatus();

        Item getItemReward();
        Equipment getEquipmentReward();
        int getTime();
        int getExhaustion();
};

#endif