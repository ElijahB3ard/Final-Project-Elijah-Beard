#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Location.h"

// The question is whether I want time and day to be a game function or a player function - It will be a game function
/*
Attribute: 
0 - void
1 - money
2 - exhaustion
3 - score
4 - reputation
5 - influence
*/

class Player
{
    private:
        string name;
        string char_name;
        int character;
        int money;
        int exhaustion;
        int score;
        int reputation;
        int influence;
        Location locations;
        vector<vector<vector<string>>> dialogue;
        vector<string> task_dialogue;
        vector<string> inventory;
        vector<Location> location_repository;
        int time;
        int day;
        vector<string> vaccine;
        int vaccine_progress;
    
    public:
        // Constructors
        Player();
        Player(string n, string cN, int c, int m, int e, int s, int r, int i, Location l, vector<vector<vector<string>>> d, vector<string> tD, vector<string> inv, vector<Location> lR, vector<string> v);
        // Methods
        int reputationStatus();
        // bool changeStats(int r, int a);
        bool changeLocation(Location l);
        string playerDialogue(int c, NPC n, vector<NPC> nR);
        string playerTaskDialogue(NPC n, vector<NPC> nR);
        // Getters
        vector<Location> getLocationRepository();
        Location getLocation();
        string getCharName();
        int getCharacter();
        int getReputation();
        int getInfluence();
        int getMoney();
        int getExhaustion();
        vector<string> getInventory();

        void updateLocation(Location l);

        void addItemToInventory(string i);
        void addEquipmentToInventory(string e);
        vector<string> removeFromInventory(int i);
        void setInventory(vector<string> i);

        void setExhaustion(int e);
        int getTime();
        int getDay();
        int getVaccineProgress();
        vector<string> getVaccine();

        void setTime(int t);
        void setDay(int d);
        void setVaccineProgress(int p);
        void setReputation(int r);
        void setMoney(int m);
};

#endif