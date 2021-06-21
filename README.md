# Greedy_Snake
This is the Repo of project Greedy_Snake

## Introduction
This project starts at 10-Jun-21. This is C++ learning project. Greedy Snake is a classic game. In this project, this game is divided into four main parts and nine functions. 
``` flow
st=>start : Initilization
cond1=>condition: Wait for input
cond2=>condition: Check
cond3=>condition: Grow or not
op1=>operation: Grow and move
op2=>operation: Move
op3=>operation: Print
ed=>end: Game Over
st->cond1
cond1(no input)->cond1
cond1(time up/input)->cond2
cond2(game over)->e
cond2(not over)->cond3
cond3(yes)->op1->op3->cond1
cond3(no)->op2->op3
```
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

In the moving part, the objective is snake including snake head and body. There are two cases: moving and grow_and_move. Moving case indicated head moves towards _head.dir_ which is a variable (direction) in head class and body follows head. The grow_and_move case is triggered by eating a food. In this case, head moves and the gap between head and body is a new node of body. 

The control part is write the direction of the snake by the key board input. The rule of the game is the snake will move itself if there is no input. There is a time period which is related to difficulty. There is also a setting which is input of reverse of heading direction is invaild. 

The Check part is most complex one. The next step of snake when the input is wrote is essential to next game loop. Thus, there is a function _nextstep_ to calculated the x and y (pair<int, int>) for head after this input. Then, whether game is over and whether snake grows this loop is judged by this x, y combination. The game over criteria is head could not touch the wall or the body. In this case, to saving time, the is_over flag is checked when the map is combined. In combination process, the body of snake is traversed so that the flag could be checked with the help of next step.

The last part is presenting part. The content is the combined game map from last section. 














