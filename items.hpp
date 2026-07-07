#include <string>
using namespace std;

// Class is defined and compiles, but does not have bounds on functions
class Items
{
    private:
        string name, type, rarity, equipment_type;
        int attributes;
    public:
    // Empty Item
        Items()
        {
            name = "";
            type = "";
            rarity = "";
            equipment_type = "";
            attributes = 0;
        }
    // Setters - unverrifies
        void setName(string n)
        {
            name = n;
        }
        void setType(string t)
        {
            type = t;
        }
        void setRarity(string r)
        {
            rarity = r;
        }
        void setEquipmentType(string et)
        {
            equipment_type = et;
        }
        void setAttributes(int a)
        {
            attributes = a;
        }

    // Getters
        string getName()
        {
            return name;
        }
        string getType()
        {
            return type;
        }
        string getRarity()
        {
            return rarity;
        }
        string getEquipmentType()
        {
            return equipment_type;
        }
        int getAttributes()
        {
            return attributes;
        }
};

// Complete for Farm (1/9), Compiles
Items initializeItems(int item_identifier)
{
    Items item_alpha;

    switch (item_identifier)
    {
        case 0:
            break;
        case 1:
            item_alpha.setName("wheat");
            item_alpha.setType("food");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(0);
            item_alpha.setEquipmentType("Null");
            break;
        case 2:
            item_alpha.setName("melon");
            item_alpha.setType("food");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(4); // Energy
            item_alpha.setEquipmentType("Null");
            break;
        case 3:
            item_alpha.setName("corn");
            item_alpha.setType("food");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(4); // Energy
            item_alpha.setEquipmentType("Null");
            break;
        // --- Equipment ---
        // - Hoe -
        case 21:
            item_alpha.setName("hoe (common)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(3); // Time
            item_alpha.setEquipmentType("hoe");
            break;
        case 22:
            item_alpha.setName("hoe (rare)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("rare");
            item_alpha.setAttributes(2); // Time
            item_alpha.setEquipmentType("hoe");
            break;
        case 23:
            item_alpha.setName("hoe (precious)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("precious");
            item_alpha.setAttributes(1); // Time
            item_alpha.setEquipmentType("hoe");
            break;
        // - Pickaxe -
        case 24:
            item_alpha.setName("pickaxe (common)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(3); // Time
            item_alpha.setEquipmentType("pickaxe");
            break;
        case 25:
            item_alpha.setName("pickaxe (rare)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("rare");
            item_alpha.setAttributes(2); // Time
            item_alpha.setEquipmentType("pickaxe");
            break;
        case 26:
            item_alpha.setName("pickaxe (precious)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("precious");
            item_alpha.setAttributes(1); // Time
            item_alpha.setEquipmentType("pickaxe");
            break;
        case 27:
            item_alpha.setName("axe (common)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(3); // Time
            item_alpha.setEquipmentType("axe");
            break;
        case 28:
            item_alpha.setName("axe (rare)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("rare");
            item_alpha.setAttributes(2); // Time
            item_alpha.setEquipmentType("axe");
            break;
        case 29:
            item_alpha.setName("axe (precious)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("precious");
            item_alpha.setAttributes(1); // Time
            item_alpha.setEquipmentType("axe");
            break;

        // --- Seeds ---
        case 33:
            item_alpha.setName("wheat seeds");
            item_alpha.setType("materials");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(0); // Time
            item_alpha.setEquipmentType("Null");
            break;
        case 34:
            item_alpha.setName("melon seeds");
            item_alpha.setType("materials");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(0); // Time
            item_alpha.setEquipmentType("Null");
            break;
        case 35:
            item_alpha.setName("corn seeds");
            item_alpha.setType("materials");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(0); // Time
            item_alpha.setEquipmentType("Null");
            break;
    }

    return item_alpha;
}