#ifndef FRUIT_H
#define FRUIT_H
#include "pacman.h"
#include <ncurses.h>

//array of characters
typedef char Fruit;

//functions to manipulate characters
void setFruit(char, int);
void initFruit(Fruit [][26]);
void eatFruit(PacMan*, Fruit [][26]);
void displayFruit(Fruit [][26], WINDOW *);
#endif
