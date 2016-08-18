#ifndef FRUIT_H
#define FRUIT_H
#include <ncurses.h>
#include "gameBoard.h"
#include "pacman.h"

//array of characters
typedef char Fruit;

//functions to manipulate characters
void setFruit(char[]);
void initFruit(Fruit [][26], char [][26]);
void eatFruit(int, int, PacMan *, GameBoard *, Fruit [][26]);
void displayFruit(Fruit [][26], WINDOW *);
#endif
