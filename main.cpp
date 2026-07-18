#include "GameFunctions.h"
#include <thread>
#include <chrono>
#include <iostream>

int main()
{
    cout << "≈" << '\n';

    string dummy;
    // int bound;
    string choice;
    int index;
    bool game_end = false;
    int day; 
    int progress;
    string end_condition;
    vector<vector<string>> menu_repository;
    string wait;

    blankTerminal();

    vector<Item> items = initializeItems();
    vector<Equipment> equipment = initializeEquipment();
    vector<Task> tasks = initializeTasks(items, equipment);
    vector<NPCTask> npc_tasks = initializeNpcTasks(items, equipment);
    vector<NPC> npcs = initializeNPCs(npc_tasks);
    vector<Location> locations = intiializeLocations(tasks, npcs);

    Player player = initializePlayer(locations);

    cout << "Enter something to start the game:" << endl;
        cin >> dummy;

    // Game loop
    while (!game_end)
    {
        newPage();
        cout << "\033[0m";
        menuTerminal(player);
        menu_repository = displayMenu(player);
        // bound = static_cast<int>(menu_repository.size());
        cout << "Make a choice: ";
            cin >> choice; 

        if (choice == "i")
        {
            cout << "Inventory: " << endl;
            for (int i = 0; i < static_cast<int>(player.getInventory().size()); i++)
            {
                cout << player.getInventory()[i] << endl;
            }
            cout << endl;
            cout << "Exit inventory:  ";
                cin >> choice;
        }
        else if (choice == "m")
        {
            string loc = player.getLocation().getName();

            string se = "", t = "", l = "", n = "", s = "", ly = "", o = "";

            if (loc == "Sepulcrum")
            {
                se = "*";
            }
            else if (loc == "Lyceum")
            {
                ly = "*";
            }
            else if (loc == "Null")
            {
                n = "*";
            }
            else if (loc == "Sanatorium")
            {
                s = "*";
            }
            else if (loc == "Liminalis")
            {
                l = "*";
            }
            else if (loc == "Theatre")
            {
                t = "*";
            }
            else
            {
                o = "*";
            }


            cout << "---------------- " << player.getLocation().getName() << " ----------------" << endl;
            cout << "Legend: * = you are here" << endl;
            cout << "Sepulcrum " << se << "                   Theatre " << t << endl;
            cout << "    |                           |" << endl;
            cout << "Liminalis " << l << "-------------------- Null " << n << "----------------- Sanatorium " << s << endl;
            cout << "                                |                          |" << endl;
            cout << "                              Lyceum " << ly << "                    Ossuary " << o << endl;
            cout << "-----------------------------------------------------------------" << endl;
            cout << "Exit? ";
                cin >> choice;
        }
        else
        {
            index = stoi(choice);
            player = executeCommand(index, player, menu_repository, npcs);

            if (player.getExhaustion() <= 0)
            {
                cout << "You passed out from exhaustion! (-12 time) (+5 exhaustion)" << endl;

                player.setTime(player.getTime() - 12);
                player.setExhaustion(player.getExhaustion() + 5);

                cout << "Continue? ";
                    cin >> choice;
            }
        }

        

        day = player.getDay();
        progress = player.getVaccineProgress();

        if (day == 5)
        {
            end_condition = "LOSE";
            game_end = true;
        }

        if (progress == 5)
        {
            end_condition = "WIN";
            game_end = true;
        }
    }

    cout << "The game is over!! You " << end_condition << "!!!" << endl;

    return 0;
}