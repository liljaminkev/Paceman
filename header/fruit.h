#ifndef FRUIT_H
#define FRUIT_H
#include "pacman.h"

//array of characters
typedef char fruit;

//functions to manipulate characters
void intFruit(int, int, char, fruit[][26]);
void eatFruit(PacMan*, fruit[][26]);
#endif
