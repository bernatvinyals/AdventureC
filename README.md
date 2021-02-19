# Adventure in C++ with parser
This project is not meant to be used as a guide to make a parser and it is not meant to release as a game at the momment. 
It's original goal is for educational porpuses.

# How to play

### IMPORTANT NOTES:
This Parser is **grammar sensitive.**
The Parser isn't case sensitve **BOTH LOWERCASE AND UPPERCASE ARE ALLOWED**

### SYNTACK:
```
Input: $Verb + $Name/Item/Adverb/Adjective
```

EXAMPLE: $Verb = "punch" $Name/Item/Adverb/Adjective/Direction = "boss"
```
Input: punch boss
```

### USING THE INVENTORY AND OBJECTS
GRAB:
```
Input: grab + $Object
```

DROP:
```
Input: drop + $Object
```

### THINGS THAT WON'T AFFECT THE OUTCOME
Phrases like "talk to the secretary" will be read as "talk secretary". This is done so it can generate the appropiate id and do the right action on actions.cpp

# WALKTHROUGH
Main Storyline:
- You appear on your bosses office and you have to procced to the next and only room by saying ``` go east``` or ``` go out ```.
- You are now on the secretary office and the game asks you to grab the "bosses mug" and go to a room that's called "Storage 2" to pick the Coffee grains in order to make coffee
- Once youre on the "Free time office" and try to enter the game won't allow it and will ask you to go grab the "Storage Key" at the secretary office by talking to the secretary
- Now go back to storage to enter "Storage 2" and find no "Coffee grains".
- **(Not implemented)** The game will ask you to go and talk to the receptionist in order to get "5$" and go to the market and buy "Coffe Grains"
- **(Not implemented)** Now with the "Bosses mug" and "Coffee grains" in your inventory you have to go to the "Free time office" and ``` combine bosses mug ``` 
- **(Not implemented)** Now the game will ask you what do you want to combine that with and in order to progress you have to say ``` coffee grains``` works in reversal
- **(Not implemented)** And it's almost over! Now you have to go to your bosses office and you will beat the game.

# MAP AND ANVIGATION:
```
+-------------+------------------+----------------+------------------+-----------+
|             |                  |                |                  |           |
| Boss Office   Secretary Office   Meeting office | Storage            Storage 2 |
|             |                  |                |                  |           |
+-------------+-------  ---------+----------------+-------  ---------+-----------+
|             |                  |                |                  |           |
| Market        Reception          Open Office      Free time office   Balcony   |
|             |                  |                |                  |           |
+-------------+------------------+----------------+------------------+-----------+
```
```
Input: go + north,south,west,east
```
# DICTIONARY:

### VERBS:
 - Grab (Used)
 - Use
 - Play
 - Throw
 - Get (Used)
 - Talk (Used)
 - Drink
 - Buy
 - Combine
 - Acces
 - Ask
 - Sleep
 - Go (Used)
 - Punch (Used)
 - Drop (Used)
 
### NAMES, ITEMS AND OTHERS :
 - Out (Adverb)
 - North (Direction)
 - East (Direction)
 - West (Direction)
 - South (Direction)

 - Boss (NPC)
 - Receptionist (NPC)
 - Colleagues (NPC)
 - Secretary (NPC)
 
 - Pen (Object) !No function yet
 - Coffee grains (Object)
 - Soda can (Object)
 - Storage key (Object)
 - Ps1 controller (Object)
 - Secretary mug  (Object)
 - 5$ (Object)
 - Bosses mug (Object)
 

# TODO:
1. Finish story
2. Add double name parser
3. Add an Inventory command or shortcut
4. You can talk with the secretary and she will ask you to put soda on her mug, buying soda will remove the 5$ bill but once given to the secretary she’ll convince your boss to not bring his coffee and the game will be over;
