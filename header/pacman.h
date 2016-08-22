#ifndef PACMAN_H
#define PACMAN_H
#include <ncurses.h>

//player informaiton
typedef struct PacMan
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
void pacmanSetInitialPoint(PacMan *, char[][26]);
void pacmanNextMove(PacMan *);
void movePacman(PacMan*, char, char[][26]);
void getPacmanDirection1(int *, int *, int, char *);
void getPacmanDirection2(int *, int *, int, char *);
void displayPacman(PacMan *, WINDOW *);
void displayScore(PacMan *, WINDOW *);
void displayLives(PacMan *, WINDOW *);

#endif
