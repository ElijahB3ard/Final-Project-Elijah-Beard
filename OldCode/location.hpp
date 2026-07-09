#include <string>
#include <vector>
#include "tasks.hpp"
#include "npcs.hpp"
using namespace std;

class Location
{
    private:
        string name;
        vector<Tasks> tasks;
        vector<NPCs> npcs;
        int trash;
        int location_progress;
    public:
    // Empty location
        Location()
        {
            vector<Items> empty_item = {initializeItems(0)};
            vector<Tasks> empty_task = {initializeTasks(0, empty_item)};

            name = "";
            tasks.push_back(initializeTasks(0, empty_item));
            npcs.push_back(initializeNPCs(0, empty_task));
            trash = 0;
            location_progress = 0;
        }
    // Setters
        void setName(string n)
        {
            name = n;
        }
        void setTask(Tasks task)
        {
            tasks.push_back(task);
        }
        void setNPC(NPCs npc)
        {
            npcs.push_back(npc);
        }
        void setTrash(int t)
        {
            trash = t;
        }
        void setLocationProgress(int p)
        {
            location_progress = p;
        }

    // Getters - Not verrified
        string getName()
        {
            return name;
        }
        Tasks getTask(int i)
        {
            return tasks[i];
        }
        NPCs getNPC(int i)
        {
            return npcs[i];
        }
        int getTrash()
        {
            return trash;
        }
        int getTaskQuantity()
        {
            return static_cast<int>(tasks.size());
        }
        int getNPCQuantity()
        {
            return static_cast<int>(npcs.size());
        }
        int getLocationProgress()
        {
            return location_progress;
        }
};

Location initializeLocation(int location_identity, vector<Tasks> task_repository, vector<NPCs> npc_repository)
{
    Location loc_alpha;

    switch (location_identity)
    {
        case 0:
            loc_alpha.setName("Farm");
            loc_alpha.setTask(task_repository[1]);
            loc_alpha.setTask(task_repository[2]);
            loc_alpha.setTask(task_repository[3]);
            loc_alpha.setTask(task_repository[4]);
            loc_alpha.setTask(task_repository[5]);
            loc_alpha.setTask(task_repository[6]);
            loc_alpha.setNPC(npc_repository[1]);
            loc_alpha.setTrash(0);
            loc_alpha.setLocationProgress(0);
    }

    return loc_alpha;
}


