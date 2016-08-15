#ifndef MONSTER_H
#define MONSTER_H
#include <ncurses.h>
#include "pacman.h"
#include "fruit.h"
#include "singlePlayerGameController.h"
#include "gameBoard.h"


typedef struct
{
    int start_positionX;
    int start_positionY;
    int x_position;
    int y_position;
    int x_direction;
    int y_direction;
    int state;
    int alive;
    int speed;
    char sprite;
} Monster;


void monsterRespawn(Monster *, int);
void displayMonsters(Monster, int, WINDOW *);
void moveMonster(Monster *);
void initilizeMonsters(Monster [], char [][26], int);
//void monsterInitialize(int, Monster *, char [][]);
#endif
