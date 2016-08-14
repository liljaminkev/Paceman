#ifndef PACMAN_H
#define PACMAN_H
//#include "singlePlayerGameController.h"
//#include "fruit.h"
//#include "gameboard.h"
#include <ncurses.h>

//player informaiton
typedef struct
{
    int lives;
    int x_position;
    int y_position;
    int x_direction;
    int y_direction;
    int x_start;
    int y_start;
    int score;
    char sprite;
    int quit;
} PacMan;

extern int MAX_Y;
extern int MAX_X;
extern int MIN_Y;
extern int MIN_X;

void pacmanInitialize(PacMan *);
void pacmanNextMove(PacMan *);
//void movePacman(PacMan*, GameBoard*);
void getPacmanDirection1(int *, int *, int, char *);
void getPacmanDirection2(int *, int *, int, char *);
void displayPacman(PacMan *, WINDOW *);

#endif
