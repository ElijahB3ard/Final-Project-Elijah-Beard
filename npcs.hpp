#include <string>
using namespace std;

class NPCs
{
    private:
        string name;
        Tasks task;
        int friendship_change;
    public:
    // Constructor
        NPCs()
        {
            vector<Items> empty_item = {initializeItems(0)};
            name = "";
            task = initializeTasks(0, empty_item);
            friendship_change = 0;
        }
    // Getters
        string getName()
        {
            return name;
        }
        Tasks getTask()
        {
            return task;
        }
        int getFriendshipChange()
        {
            return friendship_change;
        }

    // Setters - unverrified
        void setName(string n)
        {
            name = n;
        }
        void setTask(Tasks t)
        {
            task = t;
        }
        void setFriendshipChange(int f)
        {
            friendship_change = f;
        }
};

NPCs initializeNPCs(int npc_identifier, vector<Tasks> task_repository)
{
    NPCs npc_alpha;

    switch (npc_identifier)
    {
        case 0:
            break;
        case 1:
            npc_alpha.setName("Howler");
            npc_alpha.setTask(task_repository[4]);
            break;
    }

    return npc_alpha;
}
