#ifndef PACMAN_H
#define PACMAN_H

extern int player1_up;
extern int player1_down;
extern int player1_left;
extern int player1_right

extern int player2_up;
extern int player2_down;
extern int player2_left;
extern int player2_right;

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
} PacMan;

void pacmanInitialize(PacMan*);
void pacmanNextMove(PacMan*);
void movePacman(PacMan*);
void getPacmanDirection1(int, int, int);
void getPacmanDirection2(int, int, int);

#endif
