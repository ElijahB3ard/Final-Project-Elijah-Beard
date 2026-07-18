#include "GameFunctions.h"
#include <iostream>
#include <fstream>
#include <iomanip>

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
        string d, rI, rE, ir, er, t, e;
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
                   getline(taskFile, t, '|') &&  // Time
                   getline(taskFile, e))         // Exhaustion
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
                task_repository.push_back(Task(d, reqI, reqE, iRew, eRew, 0, stoi(t), stoi(e)));
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
        string d, rI, rE, ir, er, t, e, rep;
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
                   getline(npctaskFile, e, '|') &&  // Exhaustion
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
                npctask_repository.push_back(NPCTask(d, reqI, reqE, iRew, eRew, 0, stoi(t), stoi(e), stoi(rep)));
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
                    reputation.clear();
                }
                // Add instance to character list, move on to next NPC
                oD.push_back(character);
                character.clear();
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
                            status.clear();
                        }
                        // Add Reputation lines
                        reputation.push_back(choice);
                        choice.clear();
                    }
                    // Add Character lines
                    character.push_back(reputation);
                    reputation.clear();
                }
                // Add to NPC list, move on to next character
                sD.push_back(character);
                character.clear();
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
                        status.clear();
                    }
                    // Populate Character vector 
                    character.push_back(reputation);
                    reputation.clear();
                }
                // Add to NPC list
                tD.push_back(character);
                character.clear();
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
                    reputation.clear();
                }
                // Add to NPC list, move on to next npc
                cD.push_back(character);
                character.clear();
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
                // When void is found, populate location repository
                else if (designation == "void")
                {
                    // Create Location and add to the location repository
                    location_repository.push_back(Location(name, t, npc, unlock));

                    // Reset transitional vectors (so I don't need a new one for each location - otherwise, I cant use .push_back())
                    t.clear();
                    npc.clear();
                }
                // Error bounding for 'designation'
                else
                {
                    cout << "Some other designation found!!!" << endl;
                }
            }
            // Close file
            locationFile.close();
        }
        // Error loading file message
        else
        {
            cout << "Error loading the location file!" << endl;
        }

        // Return statement
        return location_repository;
    }

// Initialize player
    // Character selection and creation of the Player object that will be used for the duration of the game
    Player initializePlayer(vector<Location> lR)
    {
        // Define file variables
            // Txt of different characters and attributes
            ifstream characterFile("characters.txt");
            // Txt of dialogue options for the npc_speaking section of the NPC interface
            ifstream playerDialogueFile("player_dialogue.txt");
            // Txt of dialogue that the player says when asking for a quest
            ifstream playerTaskDialogueFile("player_task_dialogue.txt");
            // Txt of vaccine items required
            ifstream vaccineFile("vaccine.txt");

        // Define variables
        vector<Player> characters;
        vector<string> inventory = {"Scalpel", "Wings"};
        vector<string> vaccine;
        Location null;
        string n, m, r, in, player_name, name, component;
        bool found = false;
        // int choice;
        int cI = 0;
                
        // Define dialogue nested variables 3 x 3
        string line;
        vector<string> plane;
        vector<vector<string>> volume;

        // Define dialogue transitional variables
        vector<vector<vector<string>>> pD;
        vector<string> pTD;

        // Populate player task dialogue (pTD)
        if (playerTaskDialogueFile.is_open())
        {
            // Each line corresponds to a different NPC
            while (getline(playerTaskDialogueFile, line))
            {
                // Populate vector
                pTD.push_back(line);
            }
            // Close file
            playerTaskDialogueFile.close();
        }
        // Task dialogue error loading message
        else
        {
            // Output
            cout << "Error loading player task dialogue file!" << endl;

            // End program and return default player
            return Player();
        }
        
        // Reset nested variable
        line = "";

        // Populate player speaking dialogue (pD)
        if (playerDialogueFile.is_open())
        {
            // Take first line and ignore it
            while (getline(playerDialogueFile, name))
            {
                // Each player has 9 dialogue options per NPC
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++)
                    {
                        // Populate choice vector
                        getline(playerDialogueFile, line);
                        plane.push_back(line);
                    }
                    // Populate character vector, reset nested variables
                    volume.push_back(plane);
                    plane.clear();
                }
                // Populate NPC vector, reset nested variables 
                pD.push_back(volume);
                volume.clear();
            }
            // Close file
            playerDialogueFile.close();
        }
        // File loading error message
        else
        {
            // Output
            cout << "Error loading player dialogue!" << endl;

            // End function and return default player
            return Player();
        }        

        // Populate the vaccine with the names of required objects
        if (vaccineFile.is_open())
        {
            // Loop through each line, adding to vector
            while (getline(vaccineFile, component))
            {
                // Add to vaccine
                vaccine.push_back(component);
            }
        }
        // File loading error message
        else
        {
            // Output
            cout << "Couldn't load vaccine file!" << endl;
        }

        // Locate starting location in repository
        for (int i = 0; i < static_cast<int>(lR.size()); i++)
        {
            // Locate and make copy
            if (lR[i].getName() == "Null")
            {
                // Copy location, stop search
                null = lR[i];
                found = true;
                break;
            }
        }
        // Error finding location message
        if (!found)
        {
            // Output
            cout << "Could not find Null in repository!" << endl;

            // End function, return default player
            return Player();
        }

        // Input player name
        cout << "Enter your name: ";
            cin >> player_name;

        // Create player object
        if (characterFile.is_open())
        {
            // Loop through each line
            while (getline(characterFile, n, '|') &&
                   getline(characterFile, m, '|') &&
                   getline(characterFile, r, '|') &&
                   getline(characterFile, in))
            {
                // Create player object, populate character vector
                characters.push_back(Player(player_name, n, cI, stoi(m), 20, 0, stoi(r), stoi(in), null, pD, pTD, inventory, lR, vaccine));
                // Increment character identifier
                cI++;
            }
            // Close file
            characterFile.close();
        }
        // File loading error message
        else
        {
            // Output
            cout << "Error loading or finding 'characters.txt'" << endl;

            // Return default player, end function
            return Player();
        }

        // Output - character list
        /*
        cout << "Choose a character from the following list:" << endl;
        for (int i = 0; i < static_cast<int>(characters.size()); i++)
        {
            cout << endl;
            cout << "-------- " << characters[i].getCharName() << " (" << i << ") --------" << endl;
            cout << "Money: " << characters[i].getMoney() << endl;
            cout << "Reputation: " << characters[i].getReputation() << endl;
            cout << "Black Market Influence: " << characters[i].getInfluence() << endl;
        }
        cout << endl;
        */

        // Input
        /*
        cout << "Enter choice: ";
            cin >> choice;
        */

        // Valid input check
        // Return character the player wishes to play for the duration of the game
        return characters[0];
    }

// Display functions
    // Move to the next page of the game
    void newPage()
    {
        // Loop for 50 iterations
        for (int i = 0; i < 50; i++)
        {
            // Output
            cout << endl;
        }

        // Return statement
        return;
    }
    // Show the players current and relevant stats
    void displayPlayerStats(Player p)
    {
        // Output
            // Money
            cout << "Money: " << p.getMoney() << endl;
            // Exhaustion
            cout << "Exhaustion: " << p.getExhaustion() << endl;
            // Reputation
            cout << "Reputation: " << p.getReputation() << endl;
            // Influence
            cout << "Influence: " << p.getInfluence() << endl;
            // Time
            cout << "Time left: " << p.getTime() << endl;
            // Day
            cout << "Day: " << p.getDay() << endl;
            // Vaccine progress
            cout << "Vaccine progress: " << p.getVaccineProgress() << endl;

        // Return statement
        return;
    }
    // Show all of the players current game options, then return them in a vector for easy access
    vector<vector<string>> displayMenu(Player player)
    {
        // Define variables
        vector<vector<string>> menu_repository;
        vector<string> travel_repository;
        vector<string> npc_repository;
        vector<string> location_task;
        Task task;
        NPC npc;
        int i = 0;
        int j = 0;
        // int k = 0;

        // Get players current location
        Location location = player.getLocation();
        
        // Output
        // Loop through every task at given location

  

        while (i != static_cast<int>(location.getTasks().size()))
        {
            task = location.getTasks()[i];

            if (task.getDescription().substr(0, 6) == "Travel")
            {
                travel_repository.push_back(task.getDescription());
            }
            i++;
        }

        menu_repository.push_back(travel_repository);

        i = 0;


        while (i != static_cast<int>(location.getNPCs().size()))
        {
            npc = location.getNPCs()[i];

            npc_repository.push_back(npc.getName());

            i++;
        }
        menu_repository.push_back(npc_repository);

        // Define where to continue menu option designator

        // k = 3;
        // Loop through every NPC at given location
        while (j != static_cast<int>(location.getTasks().size()))
        {
            
            // Output
            task = location.getTasks()[j];


            if (task.getDescription().substr(0,6) != "Travel")
            {
                location_task.push_back(task.getDescription());
                menu_repository.push_back(location_task);
                location_task.clear();
            }
            
            // Add option to the repositor
            // Iterate to next NPC
            j++;
        }

        // Return the menu options. Returns 'Travel to' designation and exclusively the name of the NPC that can be interracted with
        return menu_repository;
    }

// Methods
    // Take player choice from the menu options and process, then update the player accordingly
    Player executeCommand(int c, Player player, vector<vector<string>> mR, vector<NPC> nR)
    {
        // Define variables
        vector<string> inventory = player.getInventory();
        vector<string> choice = mR[c - 1];
        //bool found = false;
        int second_choice;

        // Define player variables
        int exhaustion;
        int time;

        // Define 'Travel to Location' variables
        string possible_travel = "void";

        // Define 'Talk to NPC' variables
        vector<Location> location_repository = player.getLocationRepository();
        vector<NPC> location_npcs;
        Location location = player.getLocation();
        NPCTask new_task;
        NPC new_npc;
        //int npc_count = 0;

        bool found = false;


        // Define 'Task' variables
        vector<Task> location_tasks;
        string required_item, required_equipment, item_rew, equip_rew;
        Task task;
        int task_count = 0;
        
        // Repositories
            // Create location task repository
            for (int i = 0; i < static_cast<int>(location.getTasks().size()); i++)
            {
                // Populate repository
                location_tasks.push_back(location.getTasks()[i]);
                // Add to task count
                task_count++;
            }
            // Create location NPC repository
            for (int i = 0; i < static_cast<int>(location.getNPCs().size()); i++)
            {
                // Populate repository
                location_npcs.push_back(location.getNPCs()[i]);
                // Add to npc count
                //npc_count++;
            }

        // Choices
            // Locomote
            if (c == 1)
            {
                newPage();
                travelTerminal(player);

                cout << "Make choice:";
                    cin >> second_choice;

                string travel_to = mR[0][second_choice - 1].substr(10);

                for (int i = 0; i < static_cast<int>(location_repository.size()); i++)
                {
                    // The index in the repository that matches the desired location becomes the new location
                    if (travel_to == location_repository[i].getName())
                    {
                        // Change players location
                        player.changeLocation(location_repository[i]);
                        player.updateLocation(location_repository[i]);
                        //found = true;

                        // Break statement
                        break;
                    }
                }
                for (int i = 0; i < task_count; i++)
                {
                    if (mR[0][second_choice - 1] == location_tasks[i].getDescription())
                    {
                        // Change player attributes
                        time = player.getTime() - location_tasks[i].getTime();
                        exhaustion = player.getExhaustion() - location_tasks[i].getExhaustion();
                        //found = true;
                        
                        // Update players
                        player.setTime(time);
                        player.setExhaustion(exhaustion);

                        // Break statement
                        break;
                    }
                }

                return player;
            }
            // Talk to NPC
            else if (c == 2)
            {
                newPage();
                npcInitialTerminal(player);

                cout << "Make a choice (FIRE): ";
                    cin >> second_choice;

                cout << "Location npc: " << location_npcs[second_choice - 1].getName() << endl;
                player = npcInterface(location_npcs[second_choice - 1], player, nR);
                
                new_npc = player.getLocation().getNPCs()[second_choice - 1];

                if (new_npc.getTask().getStatus() == 3)
                {
                    // Define variables
                    Item item_reward = new_npc.getTask().getItemReward();
                    Equipment equipment_reward = new_npc.getTask().getEquipmentReward();
                    string required_item = new_npc.getTask().getRequiredItem().getName();
                    string required_equipment = new_npc.getTask().getRequiredEquipment().getName();

                    // If an item reward exists 
                    if (item_reward.getName() != "void")
                    {
                        // Add item to inventory
                        inventory.push_back(item_reward.getName());
                    }
                    // If an equipment reward exists
                    if (equipment_reward.getName() != "void")
                    {
                        // Add equipment to inventory
                        inventory.push_back(equipment_reward.getName());
                    }

                    // Add item(s) to new inventory
                    player.setInventory(inventory);

                    // Loop through inventory
                    for (int i = 0; i < static_cast<int>(inventory.size()); i++)
                    {
                        // If an item in your inventory is equal to the required item or equipment, remove from inventory
                        if ((required_item == inventory[i]) ||
                            (required_equipment == inventory[i]))
                        {
                            // Remove object from inventory, reassign inventory
                            inventory = player.removeFromInventory(i);
                            break;
                        }
                    }

                    // Set new inventory
                    player.setInventory(inventory);

                    // Change status so the item is not removed multiple times
                    new_task = new_npc.getTask();
                    new_task.setStatus(4);
                    new_npc.setTask(new_task);
                }

                // Transfer data and update player
                location.setNPC(second_choice - 1, new_npc);

                // Update players current location
                player.changeLocation(location);
                player.updateLocation(location);

                return player;
            }
            else
            {
                if (choice[0] == "Add to vaccine")
                {
                    cout << "Your inventory: " << endl;

                    for (int i = 0; i < static_cast<int>(inventory.size()); i++)
                    {
                        cout << "{" << i + 1 << "} " << inventory[i] << endl;
                    }
                    cout << endl;
                    cout << "vaccine components:" << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << player.getVaccine()[i] << endl;
                    }
                    cout << endl;
                    cout << "Choose item to add to vaccine:";
                        cin >> second_choice;

                    for (int i = 0; i < static_cast<int>(player.getVaccine().size()); i++)
                    {
                        if (inventory[second_choice - 1] == player.getVaccine()[i])
                        {
                            cout << inventory[second_choice - 1] << " added to vaccine!" << endl;
                            found = true;


                            player.setVaccineProgress(player.getVaccineProgress() + 1);

                            cout << "Current progress: " << player.getVaccineProgress() << "/5" << endl;
                            cout << "Continue? ";
                                cin >> second_choice;

                            return player;
                        }
                    }

                    

                    if (!found)
                    {
                        cout << "Item does not belong to vaccine!" << endl;
                        cout << "continue? ";
                            cin >> second_choice;
                    }

                    return player;
                }
                else if (choice[0] == "Pick flower")
                {
                    player.addItemToInventory("Flower");
                }
                else if (choice[0] == "Measure impossible room")
                {
                    for (int i = 0; i < static_cast<int>(player.getInventory().size()); i++)
                    {
                        if (player.getInventory()[i] == "Abacus")
                        {
                            player.addItemToInventory("Measurement");
                            cout << "You successfully measured impossible room!!" << endl;
                            found = true;
                            cout << "Exit? ";
                                cin >> second_choice;

                            return player;
                        }
                    }
                    if (!found)
                    {
                        cout << "You cant make the measurement!" << endl;
                    }

                    return player;
                }
                else if (choice[0] == "Stop by the black market")
                {
                    cout << "Welcome to the black market!!" << endl;
                    cout << "Select something you would like to buy: " << endl;
                    cout << "{1} Hematic Needle (50)" << endl;
                    cout << "{2} Wings (40)" << endl;
                    cout << "Choice (0 for no item): ";
                        cin >> second_choice;

                    if (second_choice == 0)
                    {
                        cout << "Come again soon if you dare!" << endl;
                        return player;
                    }
                    else if (second_choice == 1)
                    {
                        if (player.getMoney() >= 50)
                        {
                            player.addEquipmentToInventory("Hematic Needle");
                            player.setMoney(player.getMoney() - 50);
                            player.setReputation(player.getReputation() - 3);

                            cout << "You bought the hematic needle! (-3 reputation) (-50 money)" << endl;
                            cout << "Exit? ";
                                cin >> second_choice;

                            return player;
                        }
                        else
                        {
                            cout << "You dont have the money for this!" << endl;
                            cout << "Exit? ";
                                cin >> second_choice;

                            return player;
                        }
                    }
                    else
                    {
                        if (player.getMoney() >= 40)
                        {
                            player.addEquipmentToInventory("Wings");
                            player.setMoney(player.getMoney() - 40);
                            player.setReputation(player.getReputation() - 3);

                            cout << "You bought wings! (-3 reputation) (-40 money)" << endl;
                            cout << "Exit? ";
                                cin >> second_choice;

                            return player;
                        }
                        else
                        {
                            cout << "You dont have the money for this!" << endl;
                            cout << "Exit? ";
                                cin >> second_choice;

                            return player;
                        }
                    }
                }
                else if (choice[0] == "Steal medical supplies")
                {
                    cout << "You stole medical supplies but got caught, the town folk think of you much less now" << endl;
                    player.addEquipmentToInventory("Hematic Needle");
                    player.setReputation(player.getReputation() - 5);
                    cout << "Continue? ";
                        cin >> second_choice;

                    return player;
                }
                else if (choice[0] == "Perform autopsy")
                {
                    for (int i = 0; i < static_cast<int>(player.getInventory().size()); i++)
                    {
                        if (player.getInventory()[i] == "Scalpel")
                        {
                            cout << "You performed the autopsy! It took significant time and energy!" << endl;
                            cout << "You found chemical Faith in the cadaver" << endl;
                            found = true;

                            player.setTime(player.getTime() - 24);
                            player.setExhaustion(player.getExhaustion() - 5);
                            player.addItemToInventory("Faith");

                            cout << "Continue? ";
                                cin >> second_choice;
                            
                            return player;
                        }
                    }
                    if (!found)
                    {
                        cout << "You do not have the equipment to perform the autopsy!" << endl;
                        cout << "Continue? ";
                            cin >> second_choice;

                        return player;
                    }
                }
                else if (choice[0] == "Extract blood")
                {
                    for (int i = 0; i < static_cast<int>(player.getInventory().size()); i++)
                    {
                        if (player.getInventory()[i] == "Hematic Needle")
                        {
                            cout << "You drew blood! (-5 time) (-2 exhaustion)" << endl;
                            cout << "You have found the Blood of God!" << endl;
                            found = true;

                            player.addItemToInventory("Blood of God");
                            player.setTime(player.getTime() - 5);
                            player.setExhaustion(player.getExhaustion() - 3);

                            cout << "Continue? ";
                                cin >> second_choice;
                            
                            return player;

                        }
                    }
                    if (!found)
                    {
                        cout << "Could not extract blood :/" << endl;
                        cout << "Continue? ";
                            cin >> second_choice;

                        return player;
                    }
                }
                else if (choice[0] == "Watch play")
                {
                    for (int i = 0; i < static_cast<int>(player.getInventory().size()); i++)
                    {
                        if (player.getInventory()[i] == "Actors Promise")
                        {
                            cout << "You watched the play! It revealed great things about the world! (-6 time) (-1 energy)" << endl;
                            cout << "You aquired the Knowledge of Babel and its codex" << endl;
                            found = true;

                            player.addItemToInventory("Codex of Babel");
                            player.setTime(player.getTime() - 6);
                            player.setExhaustion(player.getExhaustion() - 1);

                            cout << "Continue? ";
                                cin >> second_choice;

                            return player;

                        }
                    }
                    if (!found)
                    {
                        cout << "You need an actor to perform in the play!" << endl;
                        cout << "Continue? ";
                            cin >> second_choice;

                        return player;
                    }
                }
                else if (choice[0] == "Rest")
                {
                    cout << "You've chosen to rest! 12 hours have passed, but you have gained 10 energy!" << endl;

                    player.setTime(player.getTime() - 12);
                    player.setExhaustion(player.getExhaustion() + 10);

                    cout << "Continue? ";
                        cin >> second_choice;

                    return player;
                }
                else if (choice[0] == "Pray")
                {
                    cout << "You have learned to bow to a cosmological deity beyond your comprehension, and you find you have nothing but hate (-4 energy) (-2 time)" << endl;

                    player.addItemToInventory("Hate");
                    player.setTime(player.getTime() - 2);
                    player.setExhaustion(player.getExhaustion() - 4);

                    cout << "Continue? ";
                        cin >> second_choice;

                    return player;
                }
                else if (choice[0] == "Read")
                {
                    cout << "Your curiosity and knowledge have given you metaphysical wings (-2 time)" << endl;
                    cout << "You got 'wings'" << endl;

                    player.addItemToInventory("Wings");
                    player.setTime(player.getTime() - 2);

                    cout << "continue? ";
                        cin >> second_choice;
                }
                
                return player;
            }
            

            return player;
    }





       
/*
        // Talk to NPC
            // Choice will be only the NPC name in which we want to talk to
            for (int i = 0; i < npc_count; i++)
            {
                if (choice == location_npcs[i].getName())
                {
                    // Pass to the NPC interface, return the new NPC with updated attributes
                    player = npcInterface(location_npcs[i], player, nR);
                    new_npc = player.getLocation().getNPCs()[i];
                    found = true;

                    // Add reward to inventory
                    if (new_npc.getTask().getStatus() == 3)
                    {
                        // Define variables
                        Item item_reward = new_npc.getTask().getItemReward();
                        Equipment equipment_reward = new_npc.getTask().getEquipmentReward();
                        string required_item = new_npc.getTask().getRequiredItem().getName();
                        string required_equipment = new_npc.getTask().getRequiredEquipment().getName();

                        // If an item reward exists 
                        if (item_reward.getName() != "void")
                        {
                            // Add item to inventory
                            inventory.push_back(item_reward.getName());
                        }
                        // If an equipment reward exists
                        if (equipment_reward.getName() != "void")
                        {
                            // Add equipment to inventory
                            inventory.push_back(equipment_reward.getName());
                        }

                        // Add item(s) to new inventory
                        player.setInventory(inventory);

                        // Loop through inventory
                        for (int i = 0; i < static_cast<int>(inventory.size()); i++)
                        {
                            // If an item in your inventory is equal to the required item or equipment, remove from inventory
                            if ((required_item == inventory[i]) ||
                                (required_equipment == inventory[i]))
                            {
                                // Remove object from inventory, reassign inventory
                                inventory = player.removeFromInventory(i);
                                break;
                            }
                        }

                        // Set new inventory
                        player.setInventory(inventory);

                        // Change status so the item is not removed multiple times
                        
                    }

                    // Transfer data and update player
                    location.setNPC(i, new_npc);

                    // Update players current location
                    player.changeLocation(location);
                    player.updateLocation(location);

                    // Return Edited player
                    return player;
                }
            }





        // Tasks
        // View Inventory task
            // If choice has the name 'Inventory', display the players inventory
            if (choice == "Inventory")
            {
                // Output header
                cout << endl;
                cout << "---------- Inventory ----------" << endl;

                // Loop through whole inventory
                for (int i = 0; i < static_cast<int>(inventory.size()); i++)
                {
                    // Display every element of inventory
                    cout << inventory[i] << endl;
                }

                // Set time change
                player.setTime(player.getTime() - 1);

                // Output format
                cout << endl;

                // Return unaltered player
                return player;
            }










        // Basic tasks
            // If a task does not have a designtation it is a basic task
            for (int i = 0; i < task_count; i++)
            {
                if (choice == location_tasks[i].getDescription())
                {
                    // Initialize task variables
                    task = location_tasks[i];
                    required_item = task.getRequiredItem().getName();
                    required_equipment = task.getRequiredEquipment().getName();
                    item_rew = task.getItemReward().getName();
                    equip_rew = task.getEquipmentReward().getName();

                    // Set task found to true
                    found = true;
                    
                    // If no required items for specific task, add item to inventory and break
                    if (required_equipment == "void" && required_item == "void")
                    {
                        // If an item reward exists, give to player
                        if (item_rew != "void")
                        {
                            // Add item reward to inventory
                            inventory.push_back(item_rew);
                        }
                        // If an equipment reward exists, give to player
                        if (equip_rew != "void")
                        {
                            // Add equipment reward to inventory
                            inventory.push_back(equip_rew);
                        }

                        // Update player attrbiutes
                        player.setInventory(inventory);
                        player.setTime(player.getTime() - task.getTime());
                        player.setExhaustion(player.getExhaustion() - task.getExhaustion());

                        // Return statement
                        return player;
                    }
                    // If task has a required item or equipment, take from inventory, then add reward
                    else
                    {
                        // Loop through inventory
                        for (int j = 0; j < static_cast<int>(inventory.size()); j++)
                        {
                            // If the item in the inventory is equal to a required task item, task is complete
                            if ((inventory[j] == required_item) ||
                                (inventory[j] == required_equipment))
                            {
                                // Update player attributes
                                cout << "Task complete" << endl;
                                player.setTime(player.getTime() - task.getTime());
                                player.setExhaustion(player.getExhaustion() - task.getExhaustion());

                                // If an item reward exists
                                if (item_rew != "void")
                                {
                                    // Add to inventory
                                    inventory.push_back(item_rew);
                                }
                                // If an equipment reward exists
                                if (equip_rew != "void")
                                {
                                    // Add to inventory
                                    inventory.push_back(equip_rew);
                                }

                                // Update inventory
                                player.setInventory(inventory);

                                // Remove used item from inventory, update player
                                inventory = player.removeFromInventory(j);
                                player.setInventory(inventory);

                                // Return statement
                                return player;
                            }
                        }
                    }
                }
            }

        // Error bounding return statement
        return player;
    }   
*/
    // Shows the NPC tasks/ dialogue and processes the requested option
    Player npcInterface(NPC npc, Player player, vector<NPC> nR)
    {
        // Define variables
        vector<string> inventory = player.getInventory();
        Location location = player.getLocation();
        NPCTask npc_task = npc.getTask();
        string npc_name = npc.getName();
        // int character = player.getCharacter();
        // int reputation = player.reputationStatus();
        int status = npc_task.getStatus();
        int npc_index;

        // Input variables
        int choice;

        // Find npc index in location
        for (int i = 0; i < static_cast<int>(location.getNPCs().size()); i++)
        {
            // Find index of npc in the location's NPC repository
            if (npc_name == location.getNPCs()[i].getName())
            {
                // Set index
                npc_index = i;
                break;
            }
        }

        // Check if item is in inventory after starting task - status(2) = Has item in inventory
        if (status != 0 && status != 3 && status != 4)
        {
            // Loop through player inventory
            for (int i = 0; i < static_cast<int>(inventory.size()); i++)
            {
                // If player has required item or equipment in inventory
                if ((inventory[i] == npc_task.getRequiredItem().getName()) ||
                    (inventory[i] == npc_task.getRequiredEquipment().getName()))
                {
                    // Change the tasks status to 2
                    npc_task.setStatus(2);
                    status = npc_task.getStatus();
                    break;
                }
            }
        }


        // Run NPC dialogue -- NPC menu
        // If task has not been started, can run speaking dialogue as long as wanted
        // If task has been started, can no longer run speaking dialogue
        // If task is completed, can no longer run task, but can run speaking dialogue as long as wanted
            // If task has not been started yet - status 0
            if (status == 0)
            {
                newPage();
                // NPC openning output 
                openDialogueTerminal(player, npc, nR);

                // Input
                cout << "Choose and option: ";
                    cin >> choice;

                // If player chooses task dialogue
                if (choice == 1)
                {

                    // Run NPC task dialogue and increase status
                    taskDialogueTerminal(player, npc);
                    npc_task.nextStatus();

                    cout << "Exit dialogue: ";
                        cin >> choice;
                    // Update NPC task inside location, and location inside player
                    npc.setTask(npc_task);
                    location.setNPC(npc_index, npc);
                    player.updateLocation(location);
                    player.setTime(player.getTime() - 1);

                    // Return new player - return to menu
                    return player;
                }
                // If player chooses speaking dialogue
                else
                {
                    // Run NPC speaking dialogue - Do not need to update dialogue status, will always be 0 at this step 
                    speakingDialogueTerminal(choice - 2, npc, player);
                    cout << "Choose option: ";
                        cin >> choice;
                    npc.setDialogueStatus(1);
                    speakingDialogueTerminal(choice - 2, npc, player);
                    cout << "Exit dialogue: ";
                        cin >> choice;

                    // Update player
                    player.setTime(player.getTime() - 2);

                    // Return statement - return to menu
                    return player;
                }
            }
            // If task has been started, but the player does not have the item in their inventory - status 1
            else if (status == 1)
            {
                // Run NPC task dialogue - No npc update needed, only one state of this dialogue
                taskDialogueTerminal(player, npc);
                cout << "Exit dialogue: ";
                    cin >> choice;
                // Update player
                player.setTime(player.getTime() - 1);

                // Return statement - return to menu
                return player;
            }
            // If task has been started, and the player has the item in their inventory - status 2
            else if (status == 2)
            {
                // Run task dialogue
                taskDialogueTerminal(player, npc);
                // Input - ask player if they want to give the item to the NPC
                cout << "Give item to " << npc.getName() << "? (yes - 1, no - 0): ";
                    cin >> choice;

                // If player gives item to NPC - Change attributes for completing task
                if (choice == 1)
                {
                    // Run completed dialogue
                    completeDialogueTerminal(npc, player);

                    cout << "Exit dialogue: ";
                        cin >> choice;

                    // Update task status to complete - status > 2
                    npc_task.setStatus(3);
                    npc.setTask(npc_task);

                    // Update npc inside location, update location inside player
                    location.setNPC(npc_index, npc);
                    player.updateLocation(location);
                    player.setExhaustion(player.getExhaustion() - npc_task.getExhaustion());
                    player.setTime(player.getTime() - 1);
                    player.setReputation(player.getReputation() + npc_task.getFriendshipChange());

                    // Return statement
                    return player;
                }
                // If player does NOT give item to NPC
                else
                {
                    // Update player
                    player.setTime(player.getTime() - 1);

                    // Return unchanged npc - return to menu
                    return player;
                }
            }
            // If task has been complete - no longer can view task
            else
            {
                // Output - Player speaking dialogue
                cout << "(1) " << player.playerDialogue(0, npc, nR) << endl;
                cout << "(2) " << player.playerDialogue(1, npc, nR) << endl;
                cout << "(3) " << player.playerDialogue(2, npc, nR) << endl;
                cout << endl;

                // Input
                cout << "Choose and option: ";
                    cin >> choice;

                // Run speaking dialogue
                npcSpeakingDialogue(choice - 1, npc, player);

                // Update player
                player.setTime(player.getTime() - 2);

                // Return unchanged npc - return to menu
                return player;
            }
    }

// Dialogue functions
    // Get speaking dialogue from npc
    string npcSpeakingDialogue(int choice, NPC npc, Player player)
    {
        // Define variables
        int c = player.getCharacter();
        int r = player.reputationStatus();

            // Input hold for player processing
            return npc.speakingDialogue(c, r, choice);

    }
    // Get task dialogue from npc
    string npcTaskDialogue(NPC npc, Player player)
    {
        // Define variables
        int c = player.getCharacter();
        int r = player.reputationStatus();

        // Output
        return npc.taskDialogue(c, r);
    }
    // Get completed dialogue from npc
    string npcCompleteDialogue(NPC npc, Player player)
    {
        // Define variables
        int c = player.getCharacter();
        int r = player.reputationStatus();

        // Output
        return npc.completedTaskDialogue(c, r);
    }

// Graphics engine
    void testTerminal()
    {
        for (int i = 0; i < 55; i++) {
            for (int j = 0; j < 42; j++)
            {
                if ((i%2) == 0)
                {
                    if ((j%2) == 0)
                    {
                        cout << "\033[40m";
                        cout << "  ";
                    }
                    else
                    {
                        cout << "\033[47m";
                        cout << "  ";
                    }
                }
                else
                {
                    if (j%2 == 0)
                    {
                        cout << "\033[47m";
                        cout << "  ";
                    }
                    else
                    {
                        cout << "\033[40m";
                        cout << "  ";
                    }
                }
                
            }
            cout << endl;
        }

        cout << "\033[0m";
    }

    void blankTerminal()
    {
        string my_message = "Hello world!";

        if (static_cast<int>(my_message.length() % 2 != 0))
        {
            my_message += " ";
        }

        string message;
        int start; // the j value we want to start at
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 43; j++)
            {
                if ((i == 0) || (i == 41))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if ((j == 0) || (j == 42))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if (i > 41)
                {
                    // The goal is to print 'Hello world here'
                    // We can do this by disecting into 2 character strings
                    if (i == 42)
                    {
                        start = 1;
                        cout << "\033[41m";
                        message = getTwoString(my_message, j, start, 42);
                        cout << message; // 2 character string
                    }
                    else
                    {
                        cout << "\033[41m";
                        cout << "  ";
                    }

                }
                else
                {
                    cout << "\033[40m";
                    cout << "  ";
                }
            }
            cout << "\033[0m";
            cout << endl;
        }
        cout << "\033[0m";
    }

    void statsTerminal(Player player)
    {
        string m = "Money: " + to_string(player.getMoney());
        string barr = "";

        for (int i = 0; i < player.getReputation(); i++)
        {
            barr += "~~";
        }
        string r = "Reputation: " + barr;
        string bare = "";

        for (int i = 0; i < player.getExhaustion(); i++)
        {
            bare += "~";
        }
        string e = "Exhaustion: " + bare;


        string d = "Day " + to_string(player.getDay());

        if (static_cast<int>(m.length()) % 2 != 0)
        {
            m += " ";
        }
        if (static_cast<int>(r.length()) % 2 != 0)
        {
            r += " ";
        }
        if (static_cast<int>(e.length()) % 2 != 0)
        {
            e += " ";
        }
        if (static_cast<int>(d.length()) % 2 != 0)
        {
            d += " ";
        }

        string line, blank;
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 43; j++)
            {
                if ((i == 0) || (i == 41))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if ((j == 0) || (j == 42))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if (i > 41)
                {
                    // The goal is to print 'Hello world here'
                    // We can do this by disecting into 2 character strings
                    if (i == 42)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString(m, j, 2, 8);
                        cout << line;
                        line = getTwoString(r, j, 8, 25);
                        cout << line;
                        line = getTwoString(e, j, 25, 42);
                        cout << line;
                    }
                    else if (i == 43)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                
                        line = "Time left: " + to_string(player.getTime());
                        if (static_cast<int>(line.length()) % 2 != 0)
                        {
                            line += " ";
                        }
                        line = getTwoString(line, j, 2, 42);
                        cout << line;
                    }
                    else if (i == 44)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString("Day " + to_string(player.getDay()) + " ", j, 2, 42);
                        cout << line;
                    }
                    else if (i == 54)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 31);
                        cout << line;
                        line = getTwoString("{i} Inventory ", j, 31, 38);
                        cout << line;
                        line = getTwoString("{m} Map ", j, 38, 42);
                        cout << line;
                    }
                    else
                    {
                        cout << "\033[41m";
                        cout << "  ";
                    }

                }
                else
                {
                    cout << "\033[40m";
                    cout << "  ";
                }
            }
            cout << "\033[0m";
            cout << endl;
        }
        cout << "\033[0m";
    }

    void menuTerminal(Player player)
    {
        string m = "Money: " + to_string(player.getMoney());
        string barr = "";

        for (int i = 0; i < player.getReputation(); i++)
        {
            barr += "~~";
        }
        string r = "Reputation: " + barr;
        string bare = "";

        for (int i = 0; i < player.getExhaustion(); i++)
        {
            bare += "~";
        }
        string e = "Exhaustion: " + bare;


        string d = "Day " + to_string(player.getDay());

        if (static_cast<int>(m.length()) % 2 != 0)
        {
            m += " ";
        }
        if (static_cast<int>(r.length()) % 2 != 0)
        {
            r += " ";
        }
        if (static_cast<int>(e.length()) % 2 != 0)
        {
            e += " ";
        }
        if (static_cast<int>(d.length()) % 2 != 0)
        {
            d += " ";
        }

        string line, blank, space;
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 43; j++)
            {
                if ((i == 0) || (i == 41))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if ((j == 0) || (j == 42))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if (i > 41)
                {
                    // The goal is to print 'Hello world here'
                    // We can do this by disecting into 2 character strings
                    if (i == 42)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString(m, j, 2, 8);
                        cout << line;
                        line = getTwoString(r, j, 8, 25);
                        cout << line;
                        line = getTwoString(e, j, 25, 42);
                        cout << line;
                    }
                    else if (i == 43)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                
                        line = "Time left: " + to_string(player.getTime());
                        if (static_cast<int>(line.length()) % 2 != 0)
                        {
                            line += " ";
                        }
                        line = getTwoString(line, j, 2, 42);
                        cout << line;
                    }
                    else if (i == 44)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString("Day " + to_string(player.getDay()) + " ", j, 2, 42);
                        cout << line;
                    }
                    else if (i == 46)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;
                        line = getTwoString("Options:", j, 12, 42);
                        cout << line;
                    }
                    else if (i == 47)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;
                        line = getTwoString("{1} Journey to a different district ", j, 12, 42);
                        cout << line;
                    }
                    else if (i == 48)
                    {
                        cout << "\033[41m";
                        cout << getTwoString("  ", j, 1, 12);
                        cout << getTwoString("{2} Speak with the morituri ", j, 12, 42);
                    }
                    else if (i == 49)
                    {
                        Location location = player.getLocation();
                        vector<Task> tasks = location.getTasks();
                        vector<Task> new_tasks;

                        for (int k = 0; k < static_cast<int>(tasks.size()); k++)
                        {
                            if (tasks[k].getDescription().substr(0,6) != "Travel")
                            {
                                new_tasks.push_back(tasks[k]);
                            }
                        }

                        if (static_cast<int>(new_tasks.size()) > 0)
                        {
                            if ((static_cast<int>(new_tasks[0].getDescription().length()) % 2) != 0)
                            {
                                space = " ";
                            }
                            else
                            {
                                space = "";
                            }

                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 12);
                            cout << getTwoString("{3} " + new_tasks[0].getDescription() + space, j, 12, 42);
                        }
                        else
                        {
                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 42);
                        }
                    }
                    else if (i == 50)
                    {
                        Location location = player.getLocation();
                        vector<Task> tasks = location.getTasks();
                        vector<Task> new_tasks;

                        for (int k = 0; k < static_cast<int>(tasks.size()); k++)
                        {
                            if (tasks[k].getDescription().substr(0,6) != "Travel")
                            {
                                new_tasks.push_back(tasks[k]);
                            }
                        }

                        if (static_cast<int>(new_tasks.size()) > 1)
                        {
                            if ((static_cast<int>(new_tasks[1].getDescription().length()) % 2) != 0)
                            {
                                space = " ";
                            }
                            else
                            {
                                space = "";
                            }

                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 12);
                            cout << getTwoString("{4} " + new_tasks[1].getDescription() + space, j, 12, 42);
                        }
                        else
                        {
                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 42);
                        }
                    }
                    else if (i == 51)
                    {
                        Location location = player.getLocation();
                        vector<Task> tasks = location.getTasks();
                        vector<Task> new_tasks;

                        for (int k = 0; k < static_cast<int>(tasks.size()); k++)
                        {
                            if (tasks[k].getDescription().substr(0,6) != "Travel")
                            {
                                new_tasks.push_back(tasks[k]);
                            }
                        }

                        if (static_cast<int>(new_tasks.size()) > 2)
                        {
                            if ((static_cast<int>(new_tasks[2].getDescription().length()) % 2) != 0)
                            {
                                space = " ";
                            }
                            else
                            {
                                space = "";
                            }

                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 12);
                            cout << getTwoString("{5} " + new_tasks[2].getDescription() + space, j, 12, 42);
                        }
                        else
                        {
                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 42);
                        }
                    }
                    else if (i == 52)
                    {
                        Location location = player.getLocation();
                        vector<Task> tasks = location.getTasks();
                        vector<Task> new_tasks;

                        for (int k = 0; k < static_cast<int>(tasks.size()); k++)
                        {
                            if (tasks[k].getDescription().substr(0,6) != "Travel")
                            {
                                new_tasks.push_back(tasks[k]);
                            }
                        }

                        if (static_cast<int>(new_tasks.size()) > 3)
                        {
                            if ((static_cast<int>(new_tasks[3].getDescription().length()) % 2) != 0)
                            {
                                space = " ";
                            }
                            else
                            {
                                space = "";
                            }

                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 12);
                            cout << getTwoString("{6} " + new_tasks[3].getDescription() + space, j, 12, 42);
                        }
                        else
                        {
                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 42);
                        }
                    }
                    else if (i == 53)
                    {
                        Location location = player.getLocation();
                        vector<Task> tasks = location.getTasks();
                        vector<Task> new_tasks;

                        for (int k = 0; k < static_cast<int>(tasks.size()); k++)
                        {
                            if (tasks[k].getDescription().substr(0,6) != "Travel")
                            {
                                new_tasks.push_back(tasks[k]);
                            }
                        }

                        if (static_cast<int>(new_tasks.size()) > 4)
                        {
                            if ((static_cast<int>(new_tasks[4].getDescription().length()) % 2) != 0)
                            {
                                space = " ";
                            }
                            else
                            {
                                space = "";
                            }

                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 12);
                            cout << getTwoString("{4} " + new_tasks[4].getDescription() + space, j, 12, 42);
                        }
                        else
                        {
                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, 42);
                        }
                    }
                    else if (i == 54)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 31);
                        cout << line;
                        line = getTwoString("{i} Inventory ", j, 31, 38);
                        cout << line;
                        line = getTwoString("{m} Map ", j, 38, 42);
                        cout << line;
                    }
                    else
                    {
                        cout << "\033[41m";
                        cout << "  ";
                    }

                }
                else
                {
                    cout << "\033[40m";
                    cout << "  ";
                }
            }
            cout << "\033[0m";
            cout << endl;
        }
        cout << "\033[0m";
    }

    void travelTerminal(Player player)
    {
        string m = "Money: " + to_string(player.getMoney());
        string barr = "";

        for (int i = 0; i < player.getReputation(); i++)
        {
            barr += "~~";
        }
        string r = "Reputation: " + barr;
        string bare = "";

        for (int i = 0; i < player.getExhaustion(); i++)
        {
            bare += "~";
        }
        string e = "Exhaustion: " + bare;


        string d = "Day " + to_string(player.getDay());

        if (static_cast<int>(m.length()) % 2 != 0)
        {
            m += " ";
        }
        if (static_cast<int>(r.length()) % 2 != 0)
        {
            r += " ";
        }
        if (static_cast<int>(e.length()) % 2 != 0)
        {
            e += " ";
        }
        if (static_cast<int>(d.length()) % 2 != 0)
        {
            d += " ";
        }

        vector<Task> tasks = player.getLocation().getTasks();
        vector<string> travel_tasks;
        for (int k = 0; k < static_cast<int>(tasks.size()); k++)
        {
            if (tasks[k].getDescription().substr(0,6) == "Travel")
            {
                travel_tasks.push_back(tasks[k].getDescription().substr(10));
            }
        }

        string line, blank, space;
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 43; j++)
            {
                if ((i == 0) || (i == 41))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if ((j == 0) || (j == 42))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if (i > 41)
                {
                    // The goal is to print 'Hello world here'
                    // We can do this by disecting into 2 character strings
                    if (i == 42)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString(m, j, 2, 8);
                        cout << line;
                        line = getTwoString(r, j, 8, 25);
                        cout << line;
                        line = getTwoString(e, j, 25, 42);
                        cout << line;
                    }
                    else if (i == 43)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                
                        line = "Time left: " + to_string(player.getTime());
                        if (static_cast<int>(line.length()) % 2 != 0)
                        {
                            line += " ";
                        }
                        line = getTwoString(line, j, 2, 42);
                        cout << line;
                    }
                    else if (i == 44)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString("Day " + to_string(player.getDay()) + " ", j, 2, 42);
                        cout << line;
                    }
                    // Begin the options -- Only need 4 options max
                    else if (i == 46)
                    {

                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;
                        line = getTwoString("Travel to:", j, 12, 42);
                        cout << line;
                    }
                    else if (i == 47)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;

                        
                        
                        if (static_cast<int>(travel_tasks.size()) > 0)
                        {
                            if (static_cast<int>(travel_tasks[0].length()) % 2 != 0)
                            {
                                space = " ";
                            }
                            else
                            {
                                space = "";
                            }

                            cout << getTwoString("{1} " + travel_tasks[0] + space, j, 12, 42);
                        }
                        else
                        {
                            cout << getTwoString("  ", j, 12, 42);
                        }
                    }
                    else if (i == 48)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;

                        if (static_cast<int>(travel_tasks.size()) > 1)
                        {
                            if (static_cast<int>(travel_tasks[1].length()) % 2 != 0)
                            {
                                space = " ";
                            }
                            else
                            {
                                space = "";
                            }

                            cout << getTwoString("{2} " + travel_tasks[1] + space, j, 12, 42);
                        }
                        else
                        {
                            cout << getTwoString("  ", j, 12, 42);
                        }
                    }
                    else if (i == 49)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;

                        if (static_cast<int>(travel_tasks.size()) > 2)
                        {
                            if (static_cast<int>(travel_tasks[2].length()) % 2 != 0)
                            {
                                space = " ";
                            }
                            else
                            {
                                space = "";
                            }

                            cout << getTwoString("{3} " + travel_tasks[2] + space, j, 12, 42);
                        }
                        else
                        {
                            cout << getTwoString("  ", j, 12, 42);
                        }
                    }
                    else if (i == 50)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;

                        if (static_cast<int>(travel_tasks.size()) > 3)
                        {
                            if (static_cast<int>(travel_tasks[3].length()) % 2 != 0)
                            {
                                space = " ";
                            }
                            else
                            {
                                space = "";
                            }

                            cout << getTwoString("{4} " + travel_tasks[3] + space, j, 12, 42);
                        }
                        else
                        {
                            cout << getTwoString("  ", j, 12, 42);
                        }
                    }
                    else if (i == 54)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 31);
                        cout << line;
                        line = getTwoString("{i} Inventory ", j, 31, 38);
                        cout << line;
                        line = getTwoString("{m} Map ", j, 38, 42);
                        cout << line;
                    }
                    else
                    {
                        cout << "\033[41m";
                        cout << "  ";
                    }

                }
                else
                {
                    cout << "\033[40m";
                    cout << "  ";
                }
            }
            cout << "\033[0m";
            cout << endl;
        }
        cout << "\033[0m";
    }

    void npcInitialTerminal(Player player)
    {
        string m = "Money: " + to_string(player.getMoney());
        string barr = "";

        for (int i = 0; i < player.getReputation(); i++)
        {
            barr += "~~";
        }
        string r = "Reputation: " + barr;
        string bare = "";

        for (int i = 0; i < player.getExhaustion(); i++)
        {
            bare += "~";
        }
        string e = "Exhaustion: " + bare;


        string d = "Day " + to_string(player.getDay());

        if (static_cast<int>(m.length()) % 2 != 0)
        {
            m += " ";
        }
        if (static_cast<int>(r.length()) % 2 != 0)
        {
            r += " ";
        }
        if (static_cast<int>(e.length()) % 2 != 0)
        {
            e += " ";
        }
        if (static_cast<int>(d.length()) % 2 != 0)
        {
            d += " ";
        }

        vector<NPC> npcs = player.getLocation().getNPCs();

        string line, blank, space;
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 43; j++)
            {
                if ((i == 0) || (i == 41))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if ((j == 0) || (j == 42))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if (i > 41)
                {
                    // The goal is to print 'Hello world here'
                    // We can do this by disecting into 2 character strings
                    if (i == 42)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString(m, j, 2, 8);
                        cout << line;
                        line = getTwoString(r, j, 8, 25);
                        cout << line;
                        line = getTwoString(e, j, 25, 42);
                        cout << line;
                    }
                    else if (i == 43)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                
                        line = "Time left: " + to_string(player.getTime());
                        if (static_cast<int>(line.length()) % 2 != 0)
                        {
                            line += " ";
                        }
                        line = getTwoString(line, j, 2, 42);
                        cout << line;
                    }
                    else if (i == 44)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString("Day " + to_string(player.getDay()) + " ", j, 2, 42);
                        cout << line;
                    }
                    // Begin the options -- Only need 4 options max
                    else if (i == 46)
                    {

                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;
                        line = getTwoString("The morituri: ", j, 12, 42);
                        cout << line;
                    }
                    else if (i == 47)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;
                        
                        if (static_cast<int>(npcs.size()) > 0)
                        {
                            if (static_cast<int>(npcs[0].getName().length()) % 2 != 0)
                            {
                                space = ""; // Opposite due to funny 'Speak with'
                            }
                            else
                            {
                                space = " ";
                            }

                            cout << getTwoString("{1} Speak with " + npcs[0].getName() + space, j, 12, 42);
                        }
                        else
                        {
                            cout << getTwoString("  ", j, 12, 42);
                        }
                    }
                    else if (i == 48)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;
                        
                        if (static_cast<int>(npcs.size()) > 1)
                        {
                            if (static_cast<int>(npcs[1].getName().length()) % 2 != 0)
                            {
                                space = ""; // Opposite due to funny 'Speak with'
                            }
                            else
                            {
                                space = " ";
                            }

                            cout << getTwoString("{2} Speak with " + npcs[1].getName() + space, j, 12, 42);
                        }
                        else
                        {
                            cout << getTwoString("  ", j, 12, 42);
                        }
                    }
                    else if (i == 49)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;
                        
                        if (static_cast<int>(npcs.size()) > 2)
                        {
                            if (static_cast<int>(npcs[0].getName().length()) % 2 != 0)
                            {
                                space = ""; // Opposite due to funny 'Speak with'
                            }
                            else
                            {
                                space = " ";
                            }

                            cout << getTwoString("{3} Speak with " + npcs[2].getName() + space, j, 12, 42);
                        }
                        else
                        {
                            cout << getTwoString("  ", j, 12, 42);
                        }
                    }
                    else if (i == 50)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 12);
                        cout << line;
                        
                        if (static_cast<int>(npcs.size()) > 3)
                        {
                            if (static_cast<int>(npcs[3].getName().length()) % 2 != 0)
                            {
                                space = ""; // Opposite due to funny 'Speak with'
                            }
                            else
                            {
                                space = " ";
                            }

                            cout << getTwoString("{4} Speak with " + npcs[3].getName() + space, j, 12, 42);
                        }
                        else
                        {
                            cout << getTwoString("  ", j, 12, 42);
                        }
                    }
                    
                    else if (i == 54)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 31);
                        cout << line;
                        line = getTwoString("{i} Inventory ", j, 31, 38);
                        cout << line;
                        line = getTwoString("{m} Map ", j, 38, 42);
                        cout << line;
                    }
                    else
                    {
                        cout << "\033[41m";
                        cout << "  ";
                    }

                }
                else
                {
                    cout << "\033[40m";
                    cout << "  ";
                }
            }
            cout << "\033[0m";
            cout << endl;
        }
        cout << "\033[0m";
    }

    void openDialogueTerminal(Player player, NPC npc, vector<NPC> nR)
    {
        string m = "Money: " + to_string(player.getMoney());
        string barr = "";

        string character_name = player.getCharName();
        int character = player.getCharacter();
        int reputation = player.reputationStatus();
        int start;
        for (int i = 0; i < player.getReputation(); i++)
        {
            barr += "~~";
        }
        string r = "Reputation: " + barr;
        string bare = "";

        for (int i = 0; i < player.getExhaustion(); i++)
        {
            bare += "~";
        }
        string e = "Exhaustion: " + bare;


        string d = "Day " + to_string(player.getDay());

        if (static_cast<int>(m.length()) % 2 != 0)
        {
            m += " ";
        }
        if (static_cast<int>(r.length()) % 2 != 0)
        {
            r += " ";
        }
        if (static_cast<int>(e.length()) % 2 != 0)
        {
            e += " ";
        }
        if (static_cast<int>(d.length()) % 2 != 0)
        {
            d += " ";
        }

        int offset = 0;
        string npc_name = npc.getName();

        if (static_cast<int>(npc_name.length()) % 2 != 0)
        {
            offset = 1;
        }

        int char_offset = 0;

        if (static_cast<int>(character_name.length()) % 2 != 0)
        {
            char_offset = 1;
        }


        string line, blank, space;
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 43; j++)
            {
                if ((i == 0) || (i == 41))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if ((j == 0) || (j == 42))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if (i > 41)
                {
                    // The goal is to print 'Hello world here'
                    // We can do this by disecting into 2 character strings
                    if (i == 42)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString(m, j, 2, 8);
                        cout << line;
                        line = getTwoString(r, j, 8, 25);
                        cout << line;
                        line = getTwoString(e, j, 25, 42);
                        cout << line;
                    }
                    else if (i == 43)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                
                        line = "Time left: " + to_string(player.getTime());
                        if (static_cast<int>(line.length()) % 2 != 0)
                        {
                            line += " ";
                        }
                        line = getTwoString(line, j, 2, 42);
                        cout << line;
                    }
                    else if (i == 44)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString("Day " + to_string(player.getDay()) + " ", j, 2, 42);
                        cout << line;
                    }
                    // Begin the options -- Only need 4 options max
                    else if (i == 46)
                    {
                        start = 12 - ((static_cast<int>(npc_name.length()) + offset + 2) / 2);

                        cout << "\033[41m";
                        cout << getTwoString("  ", j, 1, start);
                        cout << getTwoString(npc_name + ": ", j, start, 12);
                        cout << getTwoString(npc.openningDialogue(character, reputation), j, 12, 42);
                    }
                    else if (i == 48)
                    {
                        start = 12 - ((static_cast<int>(character_name.length()) + char_offset + 2) / 2);

                        cout << "\033[41m";
                        cout << getTwoString("  ", j, 1, start);
                        cout << getTwoString(character_name + ": ", j, start, 12);
                        cout << getTwoString("{1} " + player.playerTaskDialogue(npc, nR), j, 12, 42);
                    }
                    else if (i == 49)
                    {
                        cout << "\033[41m";
                        cout << getTwoString("  ", j, 1, 12);
                    
                        cout << getTwoString("{2} " + player.playerDialogue(0, npc, nR), j, 12, 42);
                    }
                    else if (i == 50)
                    {
                        cout << "\033[41m";
                        cout << getTwoString("  ", j, 1, 12);
                    
                        cout << getTwoString("{3} " + player.playerDialogue(1, npc, nR), j, 12, 42);
                    }
                    else if (i == 51)
                    {
                        cout << "\033[41m";
                        cout << getTwoString("  ", j, 1, 12);
                    
                        cout << getTwoString("{4} " + player.playerDialogue(2, npc, nR), j, 12, 42);
                    }
                    
                    else if (i == 54)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 31);
                        cout << line;
                        line = getTwoString("{i} Inventory ", j, 31, 38);
                        cout << line;
                        line = getTwoString("{m} Map ", j, 38, 42);
                        cout << line;
                    }
                    else
                    {
                        cout << "\033[41m";
                        cout << "  ";
                    }

                }
                else
                {
                    cout << "\033[40m";
                    cout << "  ";
                }
            }
            cout << "\033[0m";
            cout << endl;
        }
        cout << "\033[0m";
    }

    void taskDialogueTerminal(Player player, NPC npc)
    {
        string m = "Money: " + to_string(player.getMoney());
        string barr = "";

        string character_name = player.getCharName();
        int start;
        for (int i = 0; i < player.getReputation(); i++)
        {
            barr += "~~";
        }
        string r = "Reputation: " + barr;
        string bare = "";

        for (int i = 0; i < player.getExhaustion(); i++)
        {
            bare += "~";
        }
        string e = "Exhaustion: " + bare;


        string d = "Day " + to_string(player.getDay());

        if (static_cast<int>(m.length()) % 2 != 0)
        {
            m += " ";
        }
        if (static_cast<int>(r.length()) % 2 != 0)
        {
            r += " ";
        }
        if (static_cast<int>(e.length()) % 2 != 0)
        {
            e += " ";
        }
        if (static_cast<int>(d.length()) % 2 != 0)
        {
            d += " ";
        }

        int offset = 0;
        string npc_name = npc.getName();

        if (static_cast<int>(npc_name.length()) % 2 != 0)
        {
            offset = 1;
        }


        string line, blank, space;
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 43; j++)
            {
                if ((i == 0) || (i == 41))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if ((j == 0) || (j == 42))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if (i > 41)
                {
                    // The goal is to print 'Hello world here'
                    // We can do this by disecting into 2 character strings
                    if (i == 42)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString(m, j, 2, 8);
                        cout << line;
                        line = getTwoString(r, j, 8, 25);
                        cout << line;
                        line = getTwoString(e, j, 25, 42);
                        cout << line;
                    }
                    else if (i == 43)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                
                        line = "Time left: " + to_string(player.getTime());
                        if (static_cast<int>(line.length()) % 2 != 0)
                        {
                            line += " ";
                        }
                        line = getTwoString(line, j, 2, 42);
                        cout << line;
                    }
                    else if (i == 44)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString("Day " + to_string(player.getDay()) + " ", j, 2, 42);
                        cout << line;
                    }
                    // Begin the options -- Only need 4 options max
                    else if (i == 46)
                    {
                        start = 12 - ((static_cast<int>(npc_name.length()) + offset + 2) / 2);

                        cout << "\033[41m";
                        cout << getTwoString("  ", j, 1, start);
                        cout << getTwoString(npc_name + ": ", j, start, 12);
                        cout << getTwoString(npcTaskDialogue(npc, player), j, 12, 42);
                    }
                
                    
                    else if (i == 54)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 31);
                        cout << line;
                        line = getTwoString("{i} Inventory ", j, 31, 38);
                        cout << line;
                        line = getTwoString("{m} Map ", j, 38, 42);
                        cout << line;
                    }
                    else
                    {
                        cout << "\033[41m";
                        cout << "  ";
                    }

                }
                else
                {
                    cout << "\033[40m";
                    cout << "  ";
                }
            }
            cout << "\033[0m";
            cout << endl;
        }
        cout << "\033[0m";
    }

    void speakingDialogueTerminal(int choice, NPC npc, Player player)
    {
        string m = "Money: " + to_string(player.getMoney());
        string barr = "";

        string character_name = player.getCharName();
        int start;
        for (int i = 0; i < player.getReputation(); i++)
        {
            barr += "~~";
        }
        string r = "Reputation: " + barr;
        string bare = "";

        for (int i = 0; i < player.getExhaustion(); i++)
        {
            bare += "~";
        }
        string e = "Exhaustion: " + bare;


        string d = "Day " + to_string(player.getDay());

        if (static_cast<int>(m.length()) % 2 != 0)
        {
            m += " ";
        }
        if (static_cast<int>(r.length()) % 2 != 0)
        {
            r += " ";
        }
        if (static_cast<int>(e.length()) % 2 != 0)
        {
            e += " ";
        }
        if (static_cast<int>(d.length()) % 2 != 0)
        {
            d += " ";
        }

        int offset = 0;
        string npc_name = npc.getName();

        if (static_cast<int>(npc_name.length()) % 2 != 0)
        {
            offset = 1;
        }

        int char_offset = 0;

        if (static_cast<int>(character_name.length()) % 2 != 0)
        {
            char_offset = 1;
        }

        string line, blank, space;
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 43; j++)
            {
                if ((i == 0) || (i == 41))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if ((j == 0) || (j == 42))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if (i > 41)
                {
                    // The goal is to print 'Hello world here'
                    // We can do this by disecting into 2 character strings
                    if (i == 42)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString(m, j, 2, 8);
                        cout << line;
                        line = getTwoString(r, j, 8, 25);
                        cout << line;
                        line = getTwoString(e, j, 25, 42);
                        cout << line;
                    }
                    else if (i == 43)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                
                        line = "Time left: " + to_string(player.getTime());
                        if (static_cast<int>(line.length()) % 2 != 0)
                        {
                            line += " ";
                        }
                        line = getTwoString(line, j, 2, 42);
                        cout << line;
                    }
                    else if (i == 44)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString("Day " + to_string(player.getDay()) + " ", j, 2, 42);
                        cout << line;
                    }
                    // Begin the options -- Only need 4 options max
                    else if (i == 46)
                    {
                        start = 12 - ((static_cast<int>(npc_name.length()) + offset + 2) / 2);

                        cout << "\033[41m";
                        cout << getTwoString("  ", j, 1, start);
                        cout << getTwoString(npc_name + ": ", j, start, 12);
                        cout << getTwoString(npcSpeakingDialogue(choice, npc, player), j, 12, 42);
                    }
                    else if (i == 48)
                    {
                        if (npc.getDialogueStatus() != 1)
                        {
                            start = 12 - ((static_cast<int>(character_name.length()) + char_offset + 2) / 2);

                            cout << "\033[41m";
                            cout << getTwoString("  ", j, 1, start);
                            cout << getTwoString(character_name + ": ", j, start, 12);
                            cout << getTwoString("{1} ... ", j, 12, 42);
                        }
                        else
                        {
                            cout << "\033[41m";
                            cout << "  ";
                        }
                        
                        
                    }
                    else if (i == 54)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 31);
                        cout << line;
                        line = getTwoString("{i} Inventory ", j, 31, 38);
                        cout << line;
                        line = getTwoString("{m} Map ", j, 38, 42);
                        cout << line;
                    }
                    else
                    {
                        cout << "\033[41m";
                        cout << "  ";
                    }

                }
                else
                {
                    cout << "\033[40m";
                    cout << "  ";
                }
            }
            cout << "\033[0m";
            cout << endl;
        }
        cout << "\033[0m";
    }

    void completeDialogueTerminal(NPC npc, Player player)
{
        string m = "Money: " + to_string(player.getMoney());
        string barr = "";

        string character_name = player.getCharName();

        int start;
        for (int i = 0; i < player.getReputation(); i++)
        {
            barr += "~~";
        }
        string r = "Reputation: " + barr;
        string bare = "";

        for (int i = 0; i < player.getExhaustion(); i++)
        {
            bare += "~";
        }
        string e = "Exhaustion: " + bare;


        string d = "Day " + to_string(player.getDay());

        if (static_cast<int>(m.length()) % 2 != 0)
        {
            m += " ";
        }
        if (static_cast<int>(r.length()) % 2 != 0)
        {
            r += " ";
        }
        if (static_cast<int>(e.length()) % 2 != 0)
        {
            e += " ";
        }
        if (static_cast<int>(d.length()) % 2 != 0)
        {
            d += " ";
        }

        int offset = 0;
        string npc_name = npc.getName();

        if (static_cast<int>(npc_name.length()) % 2 != 0)
        {
            offset = 1;
        }

        string line, blank, space;
        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 43; j++)
            {
                if ((i == 0) || (i == 41))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if ((j == 0) || (j == 42))
                {
                    cout << "\033[47m";
                    cout << "  ";
                }
                else if (i > 41)
                {
                    // The goal is to print 'Hello world here'
                    // We can do this by disecting into 2 character strings
                    if (i == 42)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString(m, j, 2, 8);
                        cout << line;
                        line = getTwoString(r, j, 8, 25);
                        cout << line;
                        line = getTwoString(e, j, 25, 42);
                        cout << line;
                    }
                    else if (i == 43)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                
                        line = "Time left: " + to_string(player.getTime());
                        if (static_cast<int>(line.length()) % 2 != 0)
                        {
                            line += " ";
                        }
                        line = getTwoString(line, j, 2, 42);
                        cout << line;
                    }
                    else if (i == 44)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 2);
                        cout << line;
                        line = getTwoString("Day " + to_string(player.getDay()) + " ", j, 2, 42);
                        cout << line;
                    }
                    // Begin the options -- Only need 4 options max
                    else if (i == 46)
                    {
                        start = 12 - ((static_cast<int>(npc_name.length()) + offset + 2) / 2);

                        cout << "\033[41m";
                        cout << getTwoString("  ", j, 1, start);
                        cout << getTwoString(npc_name + ": ", j, start, 12);
                        cout << getTwoString(npcCompleteDialogue(npc, player), j, 12, 42);
                    }

                    
                    else if (i == 54)
                    {
                        cout << "\033[41m";
                        line = getTwoString("  ", j, 1, 31);
                        cout << line;
                        line = getTwoString("{i} Inventory ", j, 31, 38);
                        cout << line;
                        line = getTwoString("{m} Map ", j, 38, 42);
                        cout << line;
                    }
                    else
                    {
                        cout << "\033[41m";
                        cout << "  ";
                    }

                }
                else
                {
                    cout << "\033[40m";
                    cout << "  ";
                }
            }
            cout << "\033[0m";
            cout << endl;
        }
        cout << "\033[0m";
    }




    string getTwoString(string m, int current_j, int starting_j, int ending_j)
    {
        int index = (current_j - starting_j) * 2;
        int length = static_cast<int>(m.length()) / 2;

        if (current_j < starting_j)
        {
            return "";
        }
        else if ((current_j >= starting_j) && (current_j < starting_j + length))
        {
            return m.substr(index, 2);
        }
        else if (current_j < ending_j)
        {
            return "  ";
        }
        else
        {
            return "";
        }
    }





