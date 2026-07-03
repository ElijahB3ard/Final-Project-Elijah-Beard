#include <iostream>
#include <string>
#include "player.hpp"
using namespace std;

int main()
{
    int choice;
    string name;
    vector<Items> item_repository;
    Location farm;
    Player player;
    vector<string> location_register;

// Create Item Repository
    Items pickaxe;
    pickaxe.setName("Pickaxe");
    item_repository.push_back(pickaxe);
    Items axe;
    axe.setName("Axe");
    item_repository.push_back(axe);
    Items flower;
    flower.setName("Flower");
    item_repository.push_back(flower);
    Items membership_card;
    membership_card.setName("Membership Card");
    item_repository.push_back(membership_card);

// Create farm
    farm.setName("Farm");

// Choose a character
    cout << "Enter your name: ";
        cin >> name;
    cout << "Choose a character (1,2,3,4): ";
        cin >> choice;

    player = choosePlayerOrigins(choice, item_repository, name, farm);

    cout << "Your character: " << endl;
    cout << "Name: " << player.getName() << endl;
    cout << "Money: " << player.getMoney() << endl;
    cout << "Energy: " << player.getEnergy() << endl;
    cout << "Friendship: " << player.getFriendship() << endl;
    cout << "Joja: " << player.getJojaInfluence() << endl;
    cout << "Starting Item: " << player.getInventory()[0].getName() << endl;
    cout << "Starting Location: " << player.getCurrentLocation().getName() << endl;
    cout << "Score: " << player.getScore() << endl;
    cout << "Current time: " << player.getTime() << endl;
    cout << "Current day: " << player.getDay() << endl;
    cout << "Locations unlocked: ";
    location_register = player.getLocationRegister();
    for (int i = 0; i < static_cast<int>(player.getLocationRegister().size()); i++)
    {
        cout << location_register[i] << " ";
    }
    cout << endl;

    return 0;
}