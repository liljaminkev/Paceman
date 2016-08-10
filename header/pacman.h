#ifndef PACMAN_H
#define PACMAN_H
//#include "singlePlayerGameController.h"

//player informaiton
typedef struct PacMans
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

void pacmanInitialize(PacMan*);
void pacmanNextMove(PacMan*);
void movePacman(PacMan*);
void getPacmanDirection1(int*, int*, int, char*);
void getPacmanDirection2(int*, int*, int, char*);

#endif
