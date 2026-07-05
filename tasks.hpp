#include <string>
using namespace std;

class Tasks
{
    private:
        string description, required_equipment, location_reward;
        int time, attribute_reward;
        Items item_reward;
    public:
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

Tasks initializeTask(string d, string re, string lr, int t, int ar, Items ir)
{
    Tasks task;

    task.setDescription(d), task.setRequiredItem(re), task.setLocationReward(lr);
    task.setTime(t), task.setAttributeReward(ar);
    task.setItemReward(ir);

    return task;
}