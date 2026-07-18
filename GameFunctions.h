#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include "Player.h"

vector<Item> initializeItems();
vector<Equipment> initializeEquipment();
vector<Task> initializeTasks(vector<Item> iR, vector<Equipment> eR);
vector<NPCTask> initializeNpcTasks(vector<Item> iR, vector<Equipment> eR);
vector<NPC> initializeNPCs(vector<NPCTask> tR);
vector<Location> intiializeLocations(vector<Task> tR, vector<NPC> nR);
Player initializePlayer(vector<Location> lR);

void newPage();
vector<vector<string>> displayMenu(Player player);
void displayPlayerStats(Player p);
Player npcInterface(NPC npc, Player player, vector<NPC> nR);

string npcSpeakingDialogue(int choice, NPC npc, Player player);
string npcCompleteDialogue(NPC npc, Player player);
string npcTaskDialogue(NPC npc, Player player);
Player executeCommand(int c, Player player, vector<vector<string>> mR, vector<NPC> nR);

void testTerminal();
void blankTerminal();
void statsTerminal(Player player);
void menuTerminal(Player player);
void travelTerminal(Player player);
void npcInitialTerminal(Player player);
void openDialogueTerminal(Player player, NPC npc, vector<NPC> nR);
void taskDialogueTerminal(Player player, NPC npc);
void speakingDialogueTerminal(int choice, NPC npc, Player player);
void completeDialogueTerminal(NPC npc, Player player);
string getTwoString(string m, int current_j, int starting_j, int ending_j);

#endif