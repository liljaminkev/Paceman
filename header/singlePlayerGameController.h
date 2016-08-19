#ifndef SINGLEPLAYERGAMECONTROLLER_H
#define SINGLEPLAYERGAMECONTROLLER_H
#include "monster.h"
#include "pacman.h"
#include "fruit.h"
#include "gameBoard.h"
#include <ncurses.h>

extern int max_y;
extern int max_x;
typedef struct threadData {
	    PacMan *pacPointer;
	    GameBoard *gbPointer;
	    Monster *monPointer;
} threadData;


int singlePlayerGameEngine(PacMan *, char *);
char startGame(PacMan *, Monster [], GameBoard*, Fruit [][26], WINDOW *, WINDOW *);
int singlePlayerGameController();
int quit(char);
void fileNameCreater(char *, int);

#endif
