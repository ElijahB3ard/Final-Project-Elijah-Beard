#include "NPC.h"

// Constructors
    // Default constructors
    NPC::NPC()
    {
        // Set name and task to default values
        name = "Unknown";
        task = NPCTask();

        // Define population variables
        vector<string> line;
        vector<string> ray;
        vector<vector<string>> plane;
        vector<vector<vector<string>>> volume;

        // Populate openning and completed dialogue with 'void'
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
            {
                line.push_back("void");
            }
            openning_dialogue.push_back(line);
            completed_task_dialogue.push_back(line);
        }
        // Populate speaking dialogue with 'void'
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 2; l++)
                    {
                        ray.push_back("void");
                    }
                    plane.push_back(ray);
                }
                volume.push_back(plane);
            }
            speaking_dialogue.push_back(volume);
        }
        // Populate task dialogue with 'void'
        for (int i = 0; i < 3; i++)
        {
            task_dialogue.push_back(openning_dialogue);
        }

        // Initialize dialogue to zero
        dialogue_status = 0;
    }
    // Parameterized constructors
    NPC::NPC(string n, NPCTask t, vector<vector<string>> oD, vector<vector<vector<vector<string>>>> sD, vector<vector<vector<string>>> tD, vector<vector<string>> cTD, int dS)
    {
        // Set name:
        if (n == "")
        {
            // Invalid name
            name = "Unknown";
        }
        else
        {
            // valid name
            name = n;
        }

        // Unvalidatable variables
        task = t;
        openning_dialogue = oD;
        speaking_dialogue = sD;
        task_dialogue = tD;
        completed_task_dialogue = cTD;

        // Set status - will always initialize to zero
        dialogue_status = 0;
    }

// Methods
    // Return dialogue string - openning_dialogue
    string NPC::openningDialogue(int c, int r)
    {
        return openning_dialogue[c][r];
    }
    // Return dialogue string - speaking_dialogue
    string NPC::speakingDialogue(int c, int r, int ch)
    {
        return speaking_dialogue[c][r][ch][dialogue_status];
    }
    // Return dialogue string - task_dialogue
    string NPC::taskDialogue(int c, int r)
    {
        return task_dialogue[c][r][task.getStatus()];
    }
    // Return dialogue string - completed_dialogue
    string NPC::completedTaskDialogue(int c, int r)
    {
        return completed_task_dialogue[c][r];
    }

// Getters
    // Return name of NPC
    string NPC::getName()
    {
        return name;
    }
    // Return NPCs task
    NPCTask NPC::getTask()
    {
        return task;
    }

    void NPC::setTask(NPCTask t)
    {
        task = t;
    }



    void NPC::setDialogueStatus(int i)
    {
        dialogue_status = i;
    }

    int NPC::getDialogueStatus()
    {
        return dialogue_status;
    }