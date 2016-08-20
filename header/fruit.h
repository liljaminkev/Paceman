#ifndef FRUIT_H
#define FRUIT_H
#include <ncurses.h>

//array of characters
typedef char Fruit;

//functions to manipulate characters
void setFruit(char[]);
void initFruit(Fruit [][26], char [][26]);
int eatFruit(int, int,int *, Fruit [][26]);
void displayFruit(Fruit [][26], WINDOW *);
void eatFruit1(int *);
void eatFruit2(int *);
void eatFruit3(int *);
void eatFruit4(int *);
#endif
