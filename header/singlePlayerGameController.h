#ifndef SINGLEPLAYERGAMECONTROLLER_H
#define SINGLEPLAYERGAMECONTROLLER_H
#include "pacman.h"

extern int max_y;
extern int max_x;

PacMan singlePlayerGameEngine(PacMan, char *);
char startGame(int, int, char);
int singlePlayerGameController();
int quit(char);
void fileNameCreater(char *, int);

#endif
