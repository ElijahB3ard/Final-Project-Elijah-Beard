#include "GameFunctions.h"
#include <iostream>
#include <fstream>

void newPage()
{
    for (int i = 0; i < 100; i++)
    {
        cout << endl;
    }
}

// Initialize game objects
    // Initialize and create the Item Repository
    vector<Item> initializeItems()
    {
        // Define variables
        ifstream itemFile("items.txt");
        string n,c,t,r,a;
        vector<Item> item_repository;

        // Construct Item, then populate the repository with it
        if (itemFile.is_open())
        {
            // Initialize variables
            while (getline(itemFile, n, '|') && // Name
                   getline(itemFile, c, '|') && // Cost
                   getline(itemFile, t, '|') && // Type
                   getline(itemFile, r, '|') && // Reward
                   getline(itemFile, a))        // Attribute
            {
                // Populate repository
                item_repository.push_back(Item(n, stoi(c), stoi(t), stoi(r), stoi(a)));
            }
            // Close file
            itemFile.close();
        }
        // File not openning error message
        else
        {
            cout << "Error loading Item file!" << endl;
        }

        // Return statement
        return item_repository;
    }
    // Initialize and create the Equipment Repository
    vector<Equipment> initializeEquipment()
    {
        // Initialize variables
        ifstream equipmentFile("equipment.txt");
        string n, c, t;
        vector<Equipment> equipment_repository;

        // Construct object, add to repository
        if (equipmentFile.is_open())
        {
            // Populate variables
            while (getline(equipmentFile, n, '|') && // Name
                   getline(equipmentFile, c, '|') && // Cost
                   getline(equipmentFile, t))        // Type
            {
                // Add to the repository
                equipment_repository.push_back(Equipment(n, stoi(c), 2, 0, 0, t));
            }
            // Close the file
            equipmentFile.close();
        }
        // File error message
        else
        {
            cout << "Error loading Equipment file!" << endl;
        }

        // return statement
        return equipment_repository;
    }
    // Initialize and create the Task Repository
    vector<Task> initializeTasks(vector<Item> iR, vector<Equipment> eR)
    {
        // Define variables
        ifstream taskFile("tasks.txt");
        string d, rI, rE, ir, er, t;
        vector<Task> task_repository;

        // Define transitional variables
        Item reqI, iRew;
        Equipment reqE, eRew;

        // Create task object and add to the repository
        if (taskFile.is_open())
        {
            // Populate variables
            while (getline(taskFile, d, '|') &&  // Description
                   getline(taskFile, rI, '|') && // Required Item
                   getline(taskFile, rE, '|') && // Required Equipment
                   getline(taskFile, ir, '|') && // Item reward
                   getline(taskFile, er, '|') && // Equipment reward
                   getline(taskFile, t))         // Time
            {
                // Convert required_item string
                for (int i = 0; i < static_cast<int>(iR.size()); i++)
                {
                    // Find item definition in the repository
                    if (rI == iR[i].getName())
                    {
                        // Copy foudn item to transitional variable
                        reqI = iR[i];
                        break;
                    }
                    // If no item found in repository, populate with void item
                    else
                    {
                        // Void item
                        reqI = Item();
                    }
                }
                // Convert required_equipment string 
                for (int i = 0; i < static_cast<int>(eR.size()); i++)
                {
                    // Find equipment in the repository
                    if (rE == eR[i].getName())
                    {
                        // Copy known equipment to transitional variable
                        reqE = eR[i];
                        break;
                    }
                    // If no equipment found, populate with void equipment
                    else
                    {
                        // Void Equipment
                        reqE = Equipment();
                    }
                }
                // Convert item_reward string
                for (int i = 0; i < static_cast<int>(iR.size()); i++)
                {
                    // Search for item in the repository
                    if (ir == iR[i].getName())
                    {
                        // Copy found item to transitional variable
                        iRew = iR[i];
                        break;
                    }
                    // If none found, give void item
                    else
                    {
                        // Void item
                        iRew = Item();
                    }
                }
                // Convert equipment_reward string
                for (int i = 0; i < static_cast<int>(eR.size()); i++)
                {
                    // Find equipment in the repository
                    if (er == eR[i].getName())
                    {
                        // Copy known equipment to transitional variable
                        eRew = eR[i];
                        break;
                    }
                    // If no equipment found, populate with void equipment
                    else
                    {
                        // Void Equipment
                        eRew = Equipment();
                    }
                }

                // Populate repository
                task_repository.push_back(Task(d, reqI, reqE, iRew, eRew, 0, stoi(t)));
            }
            // Close file
            taskFile.close();
        }
        // Conditional file error message
        else
        {
            cout << "Error loading Task file!" << endl;
        }

        // Return statement
        return task_repository;
    }
    // Initialize and create the NPC Task Repository (only used for the NPC repository)
    vector<NPCTask> initializeNpcTasks(vector<Item> iR, vector<Equipment> eR)
    {
        // Define variables
        ifstream npctaskFile("npc_tasks.txt");
        string d, rI, rE, ir, er, t, rep;
        vector<NPCTask> npctask_repository;

        // Define transitional variables
        Item reqI, iRew;
        Equipment reqE, eRew;

        // Create object and populate repository
        if (npctaskFile.is_open())
        {
            // Populate variables
            while (getline(npctaskFile, d, '|') &&  // Description
                   getline(npctaskFile, rI, '|') && // Required item
                   getline(npctaskFile, rE, '|') && // Required Equipment
                   getline(npctaskFile, ir, '|') && // Item Reward
                   getline(npctaskFile, er, '|') && // Equipment Reward 
                   getline(npctaskFile, t, '|') &&  // Time
                   getline(npctaskFile, rep))       // Reputation Change
            {
                // Convert required_item string
                for (int i = 0; i < static_cast<int>(iR.size()); i++)
                {
                    // Find item definition in the repository
                    if (rI == iR[i].getName())
                    {
                        // Copy foudn item to transitional variable
                        reqI = iR[i];
                        break;
                    }
                    // If no item found in repository, populate with void item
                    else
                    {
                        // Void item
                        reqI = Item();
                    }
                }
                // Convert required_equipment string 
                for (int i = 0; i < static_cast<int>(eR.size()); i++)
                {
                    // Find equipment in the repository
                    if (rE == eR[i].getName())
                    {
                        // Copy known equipment to transitional variable
                        reqE = eR[i];
                        break;
                    }
                    // If no equipment found, populate with void equipment
                    else
                    {
                        // Void Equipment
                        reqE = Equipment();
                    }
                }
                // Convert item_reward string
                for (int i = 0; i < static_cast<int>(iR.size()); i++)
                {
                    // Search for item in the repository
                    if (ir == iR[i].getName())
                    {
                        // Copy found item to transitional variable
                        iRew = iR[i];
                        break;
                    }
                    // If none found, give void item
                    else
                    {
                        // Void item
                        iRew = Item();
                    }
                }
                // Convert equipment_reward string
                for (int i = 0; i < static_cast<int>(eR.size()); i++)
                {
                    // Find equipment in the repository
                    if (er == eR[i].getName())
                    {
                        // Copy known equipment to transitional variable
                        eRew = eR[i];
                        break;
                    }
                    // If no equipment found, populate with void equipment
                    else
                    {
                        // Void Equipment
                        eRew = Equipment();
                    }
                }

                // Create object and add to repository
                npctask_repository.push_back(NPCTask(d, reqI, reqE, iRew, eRew, 0, stoi(t), stoi(rep)));
            }
            // Close file
            npctaskFile.close();
        }
        // File reading error message
        else
        {
            cout << "Failed to load NPCTask File!" << endl;
        }

        // Return statement
        return npctask_repository;
    }
    // Initialize and create NPCs (using previous NPC task repository)
    vector<NPC> initializeNPCs(vector<NPCTask> tR)
    {
        // Define variables
        ifstream npcFile("npcs.txt");
        ifstream odFile("openning_dialogue.txt");
        ifstream sdFile("speaking_dialogue.txt");
        ifstream tdFile("task_dialogue.txt");
        ifstream cdFile("completed_dialogue.txt");
        string n, t;
        vector<vector<vector<string>>> oD; // 3 x 3 x 3
        vector<vector<vector<vector<vector<string>>>>> sD;
        vector<vector<vector<vector<string>>>> tD;
        vector<vector<vector<string>>> cD;
        string name;
        string dialogue;
        vector<NPC> npc_repository;

        // Define transitional variables
        NPCTask task;

        // Define identifying variables
        int oD_index = 0;
        int sD_index = 0;
        int tD_index = 0;
        int cD_index = 0;
        vector<string> oD_names;
        vector<string> sD_names;
        vector<string> tD_names;
        vector<string> cD_names;

        // Populates Openning dialogue vector
        if (odFile.is_open())
        {   
            // Move through each dialogue block and add to appropriate nested vector
            while (getline(odFile, name))
            {
                // Create the name repository (for identification)
                oD_names.push_back(name);

                // Create dimensions of matrix 3 x 3
                vector<vector<string>> character;
                vector<string> reputation;

                // Iterate through next 9 lines, assign to proper nested vector
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++)
                    {
                        // Populate reputation block
                        getline(odFile, dialogue);
                        reputation.push_back(dialogue);
                    }
                    // Populate character block
                    character.push_back(reputation);
                }
                // Add instance to character list, move on to next NPC
                oD.push_back(character);
            }
            // Close file, reset value for next loop
            odFile.close();
        }
        // File loading error message
        else
        {
            cout << "Cant open openning dialogue file!" << endl;
        }
        // Speaking dialogue vector
        if (sdFile.is_open())
        {
            // Move through each NPC
            while (getline(sdFile, name))
            {
                // Populate name repository
                sD_names.push_back(name);

                // Create dimensions of matrix 3 x 3 x 3 x 2
                vector<vector<vector<vector<string>>>> character;
                vector<vector<vector<string>>> reputation;
                vector<vector<string>> choice;
                vector<string> status;

                // Add dialogue lines to proper nested vector
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        for (int l = 0; l < 3; l++) {
                            for (int m = 0; m < 2; m++)
                            {
                                // Add Status lines
                                getline(sdFile, dialogue);
                                status.push_back(dialogue);
                            }
                            // Add Choice lines
                            choice.push_back(status);
                        }
                        // Add Reputation lines
                        reputation.push_back(choice);
                    }
                    // Add Character lines
                    character.push_back(reputation);
                }
                // Add to NPC list, move on to next character
                sD.push_back(character);
            }
            // Close file, reset value for next loop
            sdFile.close();
        }
        // File loading error message
        else
        {
            cout << "Cant open speaking dialogue file!" << endl;
        }
        // Task Dialogue vector
        if (tdFile.is_open())
        {
            // Move through each NPC
            while (getline(tdFile, name))
            {
                // Populate name repository
                tD_names.push_back(name);

                // Define dimensions of matrix 3 x 3 x 3
                vector<vector<vector<string>>> character;
                vector<vector<string>> reputation;
                vector<string> status;

                // Add dialogue to proper nested vector
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        for (int l = 0; l < 3; l++)
                        {
                            // Populate Status vector
                            getline(tdFile, dialogue);
                            status.push_back(dialogue);
                        }
                        // Populate Reputation vector
                        reputation.push_back(status);
                    }
                    // Populate Character vector 
                    character.push_back(reputation);
                }
                // Add to NPC list
                tD.push_back(character);
            }
            // Close file
            tdFile.close();
        }
        // File loading error message
        else
        {
            cout << "Cant open Task Dialogue file!" << endl;
        }
        // Completed Dialogue vector
        if (cdFile.is_open())
        {
            // Move through each NPC
            while (getline(cdFile, name))
            {
                // Populate name repository
                cD_names.push_back(name);

                // Define dimensions of matrix 3 x 3
                vector<vector<string>> character;
                vector<string> reputation;

                // Add dialogue to proper nested vector
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++)
                    {
                        // Populate Reputation vector
                        getline(cdFile, dialogue);
                        reputation.push_back(dialogue);
                    }
                    // Populate Character vector
                    character.push_back(reputation);
                }
                // Add to NPC list, move on to next npc
                cD.push_back(character);
            }
            // Close file.
            cdFile.close();
        }
        // File loading error message
        else
        {
            cout << "Cant open completed dialogue file!" << endl;
        }

        // Populate the NPC repository
        if (npcFile.is_open())
        {
            // Create object, populate repository
            while (getline(npcFile, n, '|') && // name
                   getline(npcFile, t))        // task
            {
                // Convert task string
                for (int j = 0; j < static_cast<int>(tR.size()); j++)
                {
                    // Copy task from repository
                    if (t == tR[j].getDescription())
                    {
                        // Assign to transitional variable
                        task = tR[j];
                        break;
                    }
                    // If no task found, give void task
                    else
                    {
                        // Void task
                        task = NPCTask();
                    }
                }

                // Find openning dialogue index for current NPC
                for (int j = 0; j < static_cast<int>(oD_names.size()); j++)
                {
                    // Find index of current NPC
                    if (n == oD_names[j])
                    {
                        // Copy index to identifier
                        oD_index = j;
                        break;
                    }
                    // Error message (debug)
                    else if (j == (static_cast<int>(oD_names.size()) - 1))
                    {
                        cout << "Error finding openning dialogue npc index!" << endl;
                    }
                }

                // Find speaking dialogue index for current NPC 
                for (int j = 0; j < static_cast<int>(sD_names.size()); j++)
                {
                    // Find index of current NPC
                    if (n == sD_names[j])
                    {
                        // Copy index to identifier
                        sD_index = j;
                        break;
                    }
                    // Error message (debug)
                    else if (j == (static_cast<int>(sD_names.size()) - 1))
                    {
                        cout << "Error finding speaking dialogue npc index!" << endl;
                    }
                }
                // Find task dialogue index for current NPC
                for (int j = 0; j < static_cast<int>(tD_names.size()); j++)
                {
                    // Find index of current NPC
                    if (n == tD_names[j])
                    {
                        // Copy index to indentifier
                        tD_index = j;
                        break;
                    }
                    // Error message (debug)
                    else if (j == (static_cast<int>(tD_names.size()) - 1))
                    {
                        cout << "Error finding task dialogue npc index!" << endl;
                    }
                }
                // Find completed dialogue index for current NPC
                for (int j = 0; j < static_cast<int>(cD_names.size()); j++)
                {
                    // Find index of current NPC
                    if (n == cD_names[j])
                    {
                        // Copy index to identifier
                        cD_index = j;
                        break;
                    }
                    // Error message (debug)
                    else if (j == (static_cast<int>(cD_names.size()) - 1))
                    {
                        cout << "Error finding completed dialogue npc index!" << endl;
                    }
                }

                // Create NPC and add to repository
                npc_repository.push_back(NPC(n, task, oD[oD_index], sD[sD_index], tD[tD_index], cD[cD_index], 0));
            }
        }
        // File loading error message
        else
        {
            cout << "Cant open main NPC file!" << endl;
        }

        // Return statement
        return npc_repository;
    }
    // Initiialize and create locations
    vector<Location> intiializeLocations(vector<Task> tR, vector<NPC> nR)
    {
        // Define variables
        ifstream locationFile("locations.txt");
        vector<Location> location_repository;
        string value, designation;

        // Transitional variables
        string name;
        vector<Task> t;
        vector<NPC> npc;
        bool unlock;

        // Construct Location and populate repository
        if (locationFile.is_open())
        {
            // Loop through each designated location
            while (getline(locationFile, value, '|') && // Value
                getline(locationFile, designation))  // Name/ Task/ NPC/ Unlock/ Void
            {
                // Set location name
                if (designation == "name")
                {
                    // Set name
                    name = value;
                }
                // Add to task vector (different from default repository)
                else if (designation == "task")
                {
                    // Find task in task repository
                    for (int i = 0; i < static_cast<int>(tR.size()); i++)
                    {   
                        // Copy task
                        if (value == tR[i].getDescription())
                        {
                            // Add to task vector
                            t.push_back(tR[i]);
                            break;
                        }
                    }
                }
                // Add to NPC vector
                else if (designation == "npc")
                {
                    // Find NPC in NPC repository
                    for (int i = 0; i < static_cast<int>(nR.size()); i++)
                    {
                        // Copy NPC
                        if (value == nR[i].getName())
                        {
                            // Add NPC to vector
                            npc.push_back(nR[i]);
                            break;
                        }
                    }
                }
                // Set unlock condition
                else if (designation == "unlock")
                {
                    // Convert to integer
                    unlock = stoi(value);
                }

                // Create Location and add to the location repository
                location_repository.push_back(Location(name, t, npc, unlock));
            }
        }
        // Error loading file message
        else
        {
            cout << "Error loading the location file!" << endl;
        }

        // Return statement
        return location_repository;
    }