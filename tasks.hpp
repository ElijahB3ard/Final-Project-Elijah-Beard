#include <string>
using namespace std;

class Tasks
{
    private:
        string description, required_equipment, location_reward;
        int time, attribute_reward;
        Items item_reward;
    public:
    // Empty task
        Tasks()
        {
            description = "";
            required_equipment = "";
            location_reward = "";
            time = 0;
            attribute_reward = 0;
            item_reward = initializeItems(0);
        }
    // setters - unverrified
        void setDescription(string d)
        {
        description = d;
        }
        void setRequiredItem(string r)
        {
            required_equipment = r;
        }
        void setLocationReward(string l)
        {
            location_reward = l;
        }
        void setTime(int t)
        {
            time = t;
        }
        void setAttributeReward(int a)
        {
            attribute_reward = a;
        }
        void setItemReward(Items i)
        {
            item_reward = i;
        }

    // getters
        string getDescription()
        {
            return description;
        }
        string getRequiredItem()
        {
            return required_equipment;
        }
        string getLocationReward()
        {
            return location_reward;
        }
        int getTime()
        {
            return time;
        }
        int getAttributeReward()
        {
            return attribute_reward;
        }
        Items getItemReward()
        {
            return item_reward;
        }
};

Tasks initializeTasks(int task_identifier, vector<Items> item_repository)
{
    Tasks task_alpha;

    switch (task_identifier)
    {
        case 0:
            break;
        case 1:
            task_alpha.setDescription("Till Soil");
            task_alpha.setRequiredItem("Hoe");
            task_alpha.setTime(2);
            task_alpha.setItemReward(item_repository[0]);
            task_alpha.setLocationReward("");
            task_alpha.setAttributeReward(0);
            break;
        case 2:
            task_alpha.setDescription("Plant Seeds");
            task_alpha.setRequiredItem("Seed");
            task_alpha.setTime(2);
            task_alpha.setItemReward(item_repository[0]);
            task_alpha.setLocationReward("");
            task_alpha.setAttributeReward(0);
            break;
        case 3:
            task_alpha.setDescription("Harvest Crop");
            task_alpha.setRequiredItem("");
            task_alpha.setTime(2);
            task_alpha.setItemReward(item_repository[1]);
            task_alpha.setLocationReward("");
            task_alpha.setAttributeReward(0);
            break;
        case 4:
            task_alpha.setDescription("Harvest Crop");
            task_alpha.setRequiredItem("");
            task_alpha.setTime(2);
            task_alpha.setItemReward(item_repository[2]);
            task_alpha.setLocationReward("");
            task_alpha.setAttributeReward(0);
            break;
        case 5:
            task_alpha.setDescription("Harvest Crop");
            task_alpha.setRequiredItem("");
            task_alpha.setTime(2);
            task_alpha.setItemReward(item_repository[3]);
            task_alpha.setLocationReward("");
            task_alpha.setAttributeReward(0);
            break;
        case 6:
            task_alpha.setDescription("Rest");
            task_alpha.setRequiredItem("");
            task_alpha.setTime(2);
            task_alpha.setItemReward(item_repository[0]);
            task_alpha.setLocationReward("");
            task_alpha.setAttributeReward(10);
            break;
    }

    return task_alpha;
}