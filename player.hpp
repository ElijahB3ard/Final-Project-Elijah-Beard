#include <string>
#include "items.hpp"
#include "location.hpp"
using namespace std;

class Player
{
    private:
        string name, bundle;
        int day, energy, money, time, score;
        int friendship_points, joja_influence;
        Location location;
        vector<Items> inventory;
        vector<string> location_register;
    public:
    // Getters
        string getName()
        {
            return name;
        }
        int getDay()
        {
            return day;
        }
        int getEnergy()
        {
            return energy;
        }
        int getMoney()
        {
            return money;
        }
        int getTime()
        {
            return time;
        }
        int getScore()
        {
            return score;
        }
        int getFriendship()
        {
            return friendship_points;
        }
        int getJojaInfluence()
        {
            return joja_influence;
        }
        Location getCurrentLocation()
        {
            return location;
        }
        vector<Items> getInventory()
        {
            return inventory;
        }
        vector<string> getLocationRegister()
        {
            return location_register;
        }

    // Setters - Unbounded - Unverified
        void setName(string n)
        {
            name = n;
        }
        void setDay(int d)
        {
            day = d;
        }
        void setEnergy(int e)
        {
            energy = e;
        }
        void setMoney(int m)
        {
            money = m;
        }
        void setTime(int t)
        {
            time = t;
        }
        void setScore(int s)
        {
            score = s;
        }
        void setFriendship(int f)
        {
            friendship_points = f;
        }
        void setJojaInfluence(int j)
        {
            joja_influence = j;
        }
        void setLocation(Location l)
        {
            location = l;
        }
        void setInventory(vector<Items> i)
        {
            inventory = i;
        }
        void setLocationRegister(vector<string> l)
        {
            location_register = l;
        }
};

int changeAttribute(int value, int factor)
{
    return value + factor;
}
int friendshipCalculator(int joja, int reward) // Incomplete
{
    return 5 - joja;
}

Player choosePlayerOrigins(int i, vector<Items> item_repository, string name, Location location)
{
    Player player;
    vector<Items> item;
    vector<int> energy_options;
    vector<int> money_options;
    vector<int> starting_friendship;
    vector<int> starting_joja;
    vector<Items> starting_item;
    vector<string> location_list = {"Farm", "Town", "Community Center", "Beach", "JojaMart", "Mine", "Forest", "Town Hall", "Joja Headquarters"};
    vector<string> actual_location_list;
    int index = i - 1;

    // Character 1 - The Miner
    energy_options.push_back(10);
    money_options.push_back(100);
    starting_friendship.push_back(5);
    starting_joja.push_back(0);
    starting_item.push_back(item_repository[24]);

    // Character 2 - The Lumberjack
    energy_options.push_back(12);
    money_options.push_back(75);
    starting_friendship.push_back(5);
    starting_joja.push_back(0);
    starting_item.push_back(item_repository[27]);

    // Character 3 - The Village Friend
    energy_options.push_back(14);
    money_options.push_back(50);
    starting_friendship.push_back(8);
    starting_joja.push_back(0);
    starting_item.push_back(item_repository[0]);

    // Character 4 - The Joja Embassator
    energy_options.push_back(10);
    money_options.push_back(75);
    starting_friendship.push_back(friendshipCalculator(4, 0));
    starting_joja.push_back(4);
    starting_item.push_back(item_repository[0]);

    // Set character
    for (int i = 0; i < 5; i++)
    {
        actual_location_list.push_back(location_list[i]);
    }
    actual_location_list.push_back(location_list[4 + i]);
    player.setDay(1);
    player.setEnergy(energy_options[index]);
    player.setFriendship(starting_friendship[index]);
    item.push_back(starting_item[index]);
    player.setInventory(item);
    player.setJojaInfluence(starting_joja[index]);
    player.setLocation(location);
    player.setLocationRegister(actual_location_list);
    player.setMoney(money_options[index]);
    player.setName(name);
    player.setScore(0);
    player.setTime(0);

    // Return starting player
    return player;
}