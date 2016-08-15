#ifndef SINGLEPLAYERGAMECONTROLLER_H
#define SINGLEPLAYERGAMECONTROLLER_H
#include "monster.h"
#include "pacman.h"
#include "fruit.h"
#include "gameBoard.h"

extern int max_y;
extern int max_x;

PacMan singlePlayerGameEngine(PacMan, char *);
char startGame(int, int, char);
int singlePlayerGameController();
int quit(char);
void fileNameCreater(char *, int);

#endif
