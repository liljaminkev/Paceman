#ifndef MONSTER_H
#define MONSTER_H
#include <ncurses.h>
#include "pacman.h"
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


void monsterRespawn(Monster *, int);
void displayMonsters(Monster *, int, WINDOW *);
void *moveMonster(void *);
void initializeMonsters(Monster [], char [][26], int);
#endif
