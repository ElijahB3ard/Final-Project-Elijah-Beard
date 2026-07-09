#include "Equipment.h"
#include "NpcTask.h"
#include <iostream>

void newPage()
{
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }
}

int main()
{
    string dummy;
    int choice = 1;

    newPage();
    cout << "Welcome to Stardew Valley!" << endl;
    cout << "This project is in the process of being completely redone! There is currently not a player class!" << endl;
    cout << "Despite this ailment, we can still pretend like there is a game loop!" << endl;
    cout << "Enter something to continue: ";
        cin >> dummy;

    while (choice != 0)
    {
        newPage();
        cout << "Welcome to the menu! This will display your: " << endl;
        cout << "Energy - " << endl;
        cout << "Money - " << endl;
        cout << "Current location - " << endl;
        cout << endl;
        cout << "Then you will be presented with your options:" << endl;
        cout << "1. Do location task" << endl;
        cout << "2. Talk to NPC (will extend to multiple lines if there are multiple NPCs)" << endl;
        cout << "3. View Inventory" << endl;
        cout << "4. View Full Map" << endl;
        cout << "Then you will be prompted to make a choice: ";
            cin >> choice;
        
        switch(choice)
        {
            case 1:
                newPage();
                cout << "This will display your location task" << endl;
                break;
            case 2:
                newPage();
                cout << "This will display the NPC menu. You can either just talk to them, or you can do an NPC task" << endl;
                break;
            case 3:
                newPage();
                cout << "This will give you a list of your inventory, and include how many of each item you have so you dont see the same item twice" << endl;
                break;
            case 4:
                newPage();
                cout << "This will show you your map, with every location that is locked and unlocked (with those designations specified in the map)" << endl;
                break;
            default:
                newPage();
                cout << "Invalid input" << endl;
        }

        cout << endl;
        cout << "Press 1 to continue, Press 0 to end the game: ";
            cin >> choice;
    }

    newPage();
    cout << "Congradulations! You either won or lost the game!" << endl;

    return 0;
}