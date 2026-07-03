#include <string>
using namespace std;

class Items
{
    private:
        string name, type, rarity, equipment_type;
        int attributes[5];
    public:
        void setName(string n)
        {
            name = n;
        }

        string getName()
        {
            return name;
        }
};