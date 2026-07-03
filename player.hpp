#include <string>
#include "items.hpp"
#include "location.hpp"
using namespace std;

class Player
{
    private:
        string name, bundle, location_register[7];
        int day, energy, money, time, score;
        int friendship_points, joja_influence;
        Location location;
        Items inventory;
};