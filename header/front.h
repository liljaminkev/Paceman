#ifndef FRONT_H
#define FRONT_H
#include "back.h"
#include <ncurses.h>

void displayMonsters(Monster, int, WINDOW *);
void displayPacman(PacMan *, WINDOW *);
void draw_borders(WINDOW *);
void displayBoard(GameBoard *, WINDOW *);
void displayFruit(Fruit [][26], WINDOW *);

#endif
