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
    public:
    // Setters
        void setName(string n)
        {
            name = n;
        }
        void setTrash(int t)
        {
            trash = t;
        }

    // Getters - Not verrified
        string getName()
        {
            return name;
        }
        int getTrash()
        {
            return trash;
        }
};