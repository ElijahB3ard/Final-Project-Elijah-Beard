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
};