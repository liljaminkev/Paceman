#ifndef FRUIT_H
#define FRUIT_H
#include "pacman.h"

//array of characters
typedef char Fruit;

//functions to manipulate characters
void intFruit(int, int, char, Fruit[][26]);
void eatFruit(PacMan*, Fruit[][26]);
#endif
