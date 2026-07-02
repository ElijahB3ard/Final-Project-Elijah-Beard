#include <string>
#include "items.hpp"
#include "location.hpp"
using namespace std;

class Player
{
    private:
        string name;
        int day;
        int energy;
        int money;
        int friendship_points;
        int joja_influence;
        Location location;
        Items inventory;
        string bundle;
        int score;
};