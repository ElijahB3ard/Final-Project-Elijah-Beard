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
        // --- Empty Item ---
        case 0:
            break;

        // --- Crops ---
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
        
        // --- Fish ---
        case 4:
            item_alpha.setName("trout");
            item_alpha.setType("food");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(3); // Energy
            item_alpha.setEquipmentType("Null");
            break;
        case 5:
            item_alpha.setName("salmon");
            item_alpha.setType("food");
            item_alpha.setRarity("rare");
            item_alpha.setAttributes(4); // Energy
            item_alpha.setEquipmentType("Null");
            break;
        case 6:
            item_alpha.setName("oarfish");
            item_alpha.setType("food");
            item_alpha.setRarity("rare");
            item_alpha.setAttributes(4); // Energy
            item_alpha.setEquipmentType("Null");
            break;
        case 7:
            item_alpha.setName("trumpetfish");
            item_alpha.setType("food");
            item_alpha.setRarity("precious");
            item_alpha.setAttributes(5); // Energy
            item_alpha.setEquipmentType("Null");
            break;
        case 8:
            item_alpha.setName("marlin");
            item_alpha.setType("food");
            item_alpha.setRarity("precious");
            item_alpha.setAttributes(5); // Energy
            item_alpha.setEquipmentType("Null");
            break;

        // --- Animal Product ---
        case 9:
            item_alpha.setName("egg");
            item_alpha.setType("food");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(3); // Energy
            item_alpha.setEquipmentType("Null");
            break;
        case 10:
            item_alpha.setName("milk");
            item_alpha.setType("food");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(3); // Energy
            item_alpha.setEquipmentType("Null");
            break;
        case 11:
            item_alpha.setName("honey");
            item_alpha.setType("food");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(1); // Energy
            item_alpha.setEquipmentType("Null");
            break;
        
        // --- Ore ---
        case 12:
            item_alpha.setName("copper");
            item_alpha.setType("material");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(10); // Money
            item_alpha.setEquipmentType("Null");
            break;
        case 13:
            item_alpha.setName("silver");
            item_alpha.setType("material");
            item_alpha.setRarity("rare");
            item_alpha.setAttributes(15); // Money
            item_alpha.setEquipmentType("Null");
            break;
        case 14:
            item_alpha.setName("gold");
            item_alpha.setType("material");
            item_alpha.setRarity("precious");
            item_alpha.setAttributes(20); // Money
            item_alpha.setEquipmentType("Null");
            break;
        
        // --- Crystal ---
        case 15:
            item_alpha.setName("amethyst");
            item_alpha.setType("material");
            item_alpha.setRarity("rare");
            item_alpha.setAttributes(20); // Money
            item_alpha.setEquipmentType("Null");
            break;
        case 16:
            item_alpha.setName("opal");
            item_alpha.setType("material");
            item_alpha.setRarity("rare");
            item_alpha.setAttributes(20); // Money
            item_alpha.setEquipmentType("Null");
            break;
        case 17:
            item_alpha.setName("ruby");
            item_alpha.setType("material");
            item_alpha.setRarity("precious");
            item_alpha.setAttributes(25); // Money
            item_alpha.setEquipmentType("Null");
            break;
        case 18:
            item_alpha.setName("saphire");
            item_alpha.setType("material");
            item_alpha.setRarity("precious");
            item_alpha.setAttributes(25); // Money
            item_alpha.setEquipmentType("Null");
            break;
        
        // --- Materials ---
        case 19:
            item_alpha.setName("wood");
            item_alpha.setType("material");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(2); // Money
            item_alpha.setEquipmentType("Null");
            break;
        case 20:
            item_alpha.setName("stone");
            item_alpha.setType("material");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(2); // Money
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
        // - axe -
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
        // - Fishing pole -
        case 30:
            item_alpha.setName("fishing pole (common)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(2); // Time
            item_alpha.setEquipmentType("fishing pole");
            break;
        case 31:
            item_alpha.setName("fishing pole (rare)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("rare");
            item_alpha.setAttributes(2); // Time
            item_alpha.setEquipmentType("fishing pole");
            break;
        case 32:
            item_alpha.setName("fishing pole (precious)");
            item_alpha.setType("equipment");
            item_alpha.setRarity("precious");
            item_alpha.setAttributes(2); // Time
            item_alpha.setEquipmentType("fishing pole");
            break;

        // --- Seeds ---
        case 33:
            item_alpha.setName("wheat seeds");
            item_alpha.setType("material");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(0); // Time
            item_alpha.setEquipmentType("seed");
            break;
        case 34:
            item_alpha.setName("melon seeds");
            item_alpha.setType("material");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(0); // Time
            item_alpha.setEquipmentType("seed");
            break;
        case 35:
            item_alpha.setName("corn seeds");
            item_alpha.setType("material");
            item_alpha.setRarity("common");
            item_alpha.setAttributes(0); // Time
            item_alpha.setEquipmentType("seed");
            break;
    }

    return item_alpha;
}