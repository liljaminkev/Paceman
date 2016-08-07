#ifndef SINGLEPLAYERGAMECONTROLLER_H
#define SINGLEPLAYERGAMECONTROLLER_H
#include "pacman.h"

extern int max_y;
extern int max_x;

PacMan singlePlayerGameInstance(PacMan);
char startGame(int, int, char);
int singlePlayerGameController();
int quit(char);

#endif
