#ifndef FRUIT_H
#define FRUIT_H
#include "pacman.h"

//fruit characters
extern char fruit1;
extern char fruit2;
extern char fruit3;
extern char fruit4;

//array of characters
typedef char Fruit;

//functions to manipulate characters
void intFruit(int, int, char, Fruit[][26]);
void eatFruit(PacMan*, Fruit[][26]);
#endif
