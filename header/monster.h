#ifndef MONSTER_H
#define MONSTER_H
#include <ncurses.h>
#include "gameBoard.h"

typedef struct Monster
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

//void monsterInitialize(Monster *, int, GameBoard *);
void monsterRespawn(Monster *, int);
void displayMonsters(Monster *, int, WINDOW *);
#endif
