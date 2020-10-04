# First-rpg
First game I created
a game based in cmd

# 8/24/2020 update
created basic layout and win condition

# Basic goals/features for this game
1) A walkable map with arrow keys
2) enemies to attack
3) loot
4) weapons/armour
5) stats
6) Final boss
7) experience
8) saves
9) different classes?

# short game design
We have a walkable map with enemies who we can attack to gain experience and level up our stats. Our combat
system will be turned based which will be 1 attack/move per turn. enemies can turn and attack as well. We have 
an end boss to fight in which we win? Our stats/weapons/armour will affect how combat goes. 

# 9/24/2020 update
I've been working on the project for the past few days. So far I've managed to create a somewhat traversable grid.
I am able to traverse it with wasd, but not arrow keys. After doing some research I found that I might have to 
use SDL. The win condition I created requires you to reach a certain point on the map. I wanted to have a seperate
playable map and player movement classes, but I'm not too sure on the implementation. I might look into at a 
later date. I want to try and create an object/person class with hero and enemy derived classes that hold the 
stats.

I finished today with creatng an object/person class. I need to integrate the player location to the person.

# 9/25/2020 update
I'm thinking of changing my playing_field from a vector of strings to a vector of "tiles". This would create a
new class called tiles. After reading some discussions about similar problems on stackexchange
https://gamedev.stackexchange.com/questions/19693/in-a-2d-tile-based-game-how-should-npcs-and-tiles-reference-each-other
https://gamedev.stackexchange.com/questions/131010/how-do-i-efficiently-manage-a-tile-based-map-with-items-and-characters
this seems like a better design than I have right now.

# 9/29/2020 update
I ran into a problem in which I created a vector of custom class objects similar to one found in a homework. 
Like the homework I changed it to a vector of custom class pointers. Now I am running into use of undefined
types/incomplete type error that has to do with one of my classes not being defined before some of its functions
being used in a different class (Specifically the constructor is being used). 
https://stackoverflow.com/questions/33964994/error-c2027-use-of-undefined-type-how-to-declare-class
https://stackoverflow.com/questions/2297567/where-should-include-be-put-in-c#:~:text=As%20a%20rule%2C%20put%20your,issue%20as%20your%20project%20grows.
I sort of fixed the problem. Now I am having a problem that the constuctor creates pointers to the same memory.
location. 
I modified the constructor to create the game_tiles vector so that the pointers point to different memory 
locations.
Everything is working just as it did before I decided to create my map_tiles class. Now I just need to implement
the map_object classes.
I added a couple of variables to map_object and function to map_tiles.

# 10/3/2020 update
So I mostly finished creating a walkable map. Now I want to implement map objects onto the map itself. Guess
I forgot how derived classes worked and ran into an error.
https://stackoverflow.com/questions/5844584/error-function-is-inaccessible
It was easily fixed and I changed some string allocations to const &.
So I managed to integrate map objects with map tiles. I need to figure out how to update the map correctly
because right now I only update one location at a time. I also need to abstract the character movement from
the map itself to its own class that the characters can use.




