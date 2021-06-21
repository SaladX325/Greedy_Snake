# Greedy_Snake
This is the Repo of project Greedy_Snake

This project starts at 10-Jun-21. This is C++ learning project. Greedy Snake is a classic game. In this project, this game is divided into four main parts and nine functions. 
## Class
These four classes are listed below:
1. Snake Head
2. Snake Body
3. Food
4. Game Map

For each part, it has a specific class. In snake head part, the class _snakehead_ is control how the snake moves. It has three variables - direction, x, y. Each time key board
input, the direction is rewrite. 

The second class is snake body. The body is followed by head. The lenghth of body is inceasing and the value of each section is varying as the snake moves. Here, the structure
for storage is double linked-list. This type of structure could add a node in front of the whole list so that the value of mid-nodes could remained the same (unless it is 
deleted). Comparing with the linked-list, double linked-list has one more pointer in its structure. This allows the list delete the last node using the _pre_ pointer. In this 
case, when it comes to deleting, it is not necessary to traverse the linked-list which saving time. 

The food class only has its corrdinates. The food generated function is in the source for the seed of _rand()_ function could not be set once the objective is created. 

The last one is Game Map Class. This class has the shape of the base map and the combined map including the snake, food, and game borders. The combined map is printed in the _cmd_
window to present how the snake moves.

## Functions
In total, there are nine functions. There is three major parts:
1. Moving 
2. Control 
3. Check
4. Present


