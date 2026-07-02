# Final-Project-Elijah-Beard

The objective of the game is to fill the Bundle before time runs out. The player has x days to add x specific items to the bundle, where the game ends when the bundle is complete, or the player runs out of time. In order to obtain the items for the bundle, as well as items for the rest of the game, the player can ...

-- The Player --

/Stats/

    - Name - Your players unique name will be displayed throughout the game, showing up in dialogue and exposition
    
    - Day - There are only a certain number of days in the game. Either the bundle is completed by the day limit, or the player loses the game.
            There is a single item in the game that can extend the day limit by one, however, there only exists one of these items and it can only
            be gifted to the player by an NPC. 
    
    - Energy - Every action from the player costs an amount of energy. Energy is regained partially during sleep, or by consuming a food item 
               or an energy potion. If the player runs out of energy for the day, they pass out, the day ends, and they wake up at the farm with
               half the energy they get from sleeping.
    
    - Money - In order to purchase certian items, or to unlock certain areas, you need to spend gold with NPCs or at stores. You can sell items to 
              get more gold, or you can recieve gold from NPCs for completing quests. 
   
    - Time - Every action in the game will cost a certain amount of time to complete. Each day only has a specific amount of time in it. Once the time runs to zero, a new day will begin, and the player will remain where they are with what they are doing. 
    
    - Friendship Points - Every NPC in the game will have three versions of dialogue. Each version of dialogue will allow for different actions such
                          as receiving gifts or quests or different endings. The version of dialogue that is displayed will depend entirely on the 
                          number of friendship points the player has. The player can increase this by completing tasks for the NPCs, or for being nice
                          to them. You can also increase your friendship points with a consumable item.
    
    - Joja Influence - The Jojamart is trying to create a monopoly on items in the village. The items there are tempting to buy, however, with every
                       item you buy, your influence will increase by x depending on the money you spend on the item. Your Joja influence will directly
                       effect your friendship points negatively, and if you give enough money to Jojamart (an amount the player will not be told),
                       you can unlock two unique endings. You can decrease your joja influence by speaking with certain NPCs, or by consuming an item.
    
    - Location - The actions that a player can take are entirely dependant on the location of the player. It will cost x amount of energy to travel
                 between locations of the game.
    
    - Inventory - The player can hold up to x items at a time. Some of these items are resources for building the bundle, some are food items to
                  regain energy, some are equipment items that allow the player to mine or fish or chop wood ect, some are things like seeds that
                  the player will need to complete the game. Managing your inventory will be key to success.
   
    - Bundle Progress - The items you need for the bundle can be observed and displayed at any time during the game, however, you cannot contribute
                        to the bundle at every location in the game. Completed items, as well as items that are not yet complete will be listed
                        in this statistic.
    
    - Score - All of the above attributes will contribute to your score. Things you do around the village will also contribute to your score. The
              secondary goal of the game is to get the highest score possible. Your final score at the end of the game will give you a unique 
              ending dialogue, and will contribute to your award at the end of the game. Certain consumables will contribute to your score.

-- Location --

    - Name - Each location has a unique name that will be displayed on the map and mentioned in NPC dialogue
    
    - Tasks - Every location has a set of unique tasks that are parrallel to the purpose of the location. The mine will have an option to go mining,
              the community center will have an option to contribute to the bundle. Some locations have multiple tasks. The Farm is the main location.
              Here, you can sleep, grow crops and store items. Some locations will have the option to pick up trash. Doing this will increase your
              score and friendship points. Doing tasks will give you items or change attributes for your character.
    
    - NPCs - Most locations will have NPCs that you can talk to. The NPCs can either: just talk, give a quest, give an item, sell an item, buy an
             item or give a hint. Interracting with an NPC will cost energy, and if you attempt to speak with one where the cost in energy is greater
             than your current energy, you will pass out, and not be able to speak with the NPC. 
   
    - Trash Amount - each location will have a certain amount of trash. A task for you to complete is to collect trash in a location. Doing this will
                     give you benefits in the form of items or attributes from an NPC nearby.  

--- Tasks ---

    - Description - Each task, rather than a name, has a designation. This could be in the form of "Collect Wood" or "Contribute to Bundle".
   
    - Required Items - Each task has one or multiple required items in order to participate in the task. If the player does not have one of these Items
                       in their inventory, then the task will not be complete and energy will NOT be spent. However, doing a task successfully will 
                       cost energy and time. 
    
    - Time - Every task takes an amount of time to complete. 
    
--- Items ---

/Stats
    
    - Name - Every item has a unique name which will be displayed to the player for identification.
    
    - Type - Every item will be one of three types: materials, food, equipment. Each item type will have a different purpose and can be used in
             different locations. Materials can only be deposited or sold. Food can only be consumed or sold. Equipment can only be used or sold.
    
    - Rarity - Items are sometimes collected at random. This randomness is defined by the rarity of the item. These rarities are common, rare, 
               precious. Each will have some physical representation for the character to know the rarity of the item. The more rare and item, the
               better the stats will be for it. Materials can only be common, while food and equipment can be common, rare, and precious. 
    - Attributes - Every item will have some form of attribute. However, since only the food will meaningfully contribute to the players stats, 
                   all attributes for materials and equipment will be set to zero. The food type can increase (or decrease) energy, increase 
                   (or decrease) the days remaining, increase (or decrease) your freindship points, increase (or decrease) your joja influence, 
                   and/or increase (or decrease) your score. 
    - Equipment Type - For the materials and food types, this will be set to a distinguisher. You can only use certain equipment in certain locations.
                       The equipment types are: fishing pole, pickaxe, axe, hoe and trashbag. 

--- The Bundle ---
- Food Reserve
    - [3] Crop (Wheat, Melon, Corn)
    - [3] Fish (Trout, Salmon, Oarfish, Trumpetfish, Marlin)
    - [3] Animal Product (egg, milk, honey)
- Mineral Reserve
    - [5] Ore (Copper, Silver, Gold)
    - [3] Crystal (Amethyst, Opal, Ruby, Saphire)
- Material Reserve
    - [5] Wood
    - [5] Stone
