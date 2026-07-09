# CSCI 1300 Final Project

## Theme
My game will be based on an old indie game called Pathologic! My entire idea is just to make very interesting an unsettling interractions, with weird item and location names. Its kind of built in a world that doesn't quite make sense, and im in love with the unsettling nature of it.

## Goal
The goal of the game is to gather the resources to synthesize a vaccine for a pandemic that is sweeping over the town. You do this by comlpeting tasks and such.

## How to compile and run
g++ -Wall -Werror -Wpedantic -std=c++17 -g main.cpp -o play 
./play

## How to play
You start at a set location, and you can only go to specific locations from the start. As you do tasks and activities, your time and energy will slowly run out. If your time runs out, you automatically move on to the next day. You have a set amount of days to complete your goal of synthesizing the vaccine. If you run out of energy, you will pass out, and wake up the next day with only half the energy you get from resting. You can rest at a specific location, and doing so will move on to the next day automatically and give you a set amount of energy. You comlpete location tasks using equipment, and you are rewarded with an item of some sort. You can complete NPC tasks in the same manner, however, you comleting the task will change your friendship points. Certain aspects in the game will determine your interractions with people, such as how much market influence you have. You can use items to change your attributes, like eating to increase energy, or consumibng a potion to change friendship points and such. The game ends when you run out of time, or when you synthesize the vaccine.

## Classes
### Item
This class holds the information about a specific item in the game. An item can have a name, a cost (for if you buy it at a store), a reward you get for consuming or using the item, and the attribute that gets affected when you do use the item. To make task setting easier, each item also has a type. The type of item affects which activities and tasks you can do.
### Equipment
Inherited from the Item class, however, each bit of equipment needs a designator like 'pickaxe' or 'axe' to further restrict which tasks can be completed
### Task
Each task in the game has a description, telling you what you need to do, and a reward that you recieve for when you complete the task. The task has a required item that must be aquired in order for the reward to be given, and the task has to be started before a reward can be given or an item accepted.
### NPCTask
Inherited from the Task class, however with an extra friendship change variable. Depending on the task i.e. its contents or who you do it with, your friendship points can go down or up. I will be changing friendship points to reputation later on, and thinking of that variable as a reputation is much easier then as a freindship point.

## Extra credit
I will try my best to make the game look pretty!!!!