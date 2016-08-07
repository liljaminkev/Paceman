#ifndef FRUIT_H
#define FRUIT_H
#include "pacman.h"

typedef char Fruit;

void intFruit(int, int, char, Fruit[][26]);
void eatFruit(PacMan*, Fruit[][26]);
#endif
