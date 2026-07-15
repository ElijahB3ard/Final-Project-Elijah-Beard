#ifndef NPC_H
#define NPC_H
#include <vector>
#include "NpcTask.h"

// Every npc initially has 2 dialogue options, either a hint or just general story
// Depending on your reputation and character, you can get 3 responses, and 3 characters gives you 9 possible options per character, then those dialogues will continue for one more string,
// This means that each npc will have a total of 2 initial, each with 3 total possibilities, then each possibility has an extra bit of dialogue at the end, and these are different for each character
// Total dialogue per NPC = 14 * 3 = 42

/*
Task Status:
0 - Not started
1 - Started, no item
2 - Started, has item
3 - Completed
*/

class NPC
{
    private:
        string name;
        NPCTask task;
        vector<vector<string>> openning_dialogue; // 3 x 3
        vector<vector<vector<vector<string>>>> speaking_dialogue; // 3 x 3 x 3 x 2
        vector<vector<vector<string>>> task_dialogue; // 3 x 3 x 3
        vector<vector<string>> completed_task_dialogue; // 3 x 3
        int dialogue_status; // 0, 1
    
    public:
        // Constructors
        NPC();
        NPC(string n, NPCTask t, vector<vector<string>> oD, vector<vector<vector<vector<string>>>> sD, vector<vector<vector<string>>> tD, vector<vector<string>> cTD, int dS);
        // Methods
        string openningDialogue(int c, int r);
        string speakingDialogue(int c, int r, int ch);
        string taskDialogue(int c, int r);
        string completedTaskDialogue(int c, int r);
        // Getters
        string getName();
        NPCTask getTask();
};

#endif