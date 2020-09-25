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