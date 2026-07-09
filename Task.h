#ifndef TASK_H
#define TASK_H
#include <string>
#include "Equipment.h"
using namespace std;

// Every task has a description, and if the task is complete, you will recieve some sort of reward
/*
Status:
0 - not started
1 - started
2 - completed
*/
class Task
{
    private:
        string description;
        Item required_item;
        Item reward;
        int status;

    public:
        Task();
        Task(string d, Item rI, Item i, int s);
        void setStatus(int s);
        string getDescription();
        Item completed(Item i);
        Item getRequiredItem();
        string statusName();

};

#endif