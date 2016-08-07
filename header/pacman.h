#ifndef PACMAN_H
#define PACMAN_H
//player 1 controls
extern int player1_up;
extern int player1_down;
extern int player1_left;
extern int player1_right;

//player 2 controls
extern int player2_up;
extern int player2_down;
extern int player2_left;
extern int player2_right;

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
} PacMan;

void pacmanInitialize(PacMan *);
void pacmanNextMove(PacMan *);
void movePacman(PacMan *);
char getPacmanDirection1(PacMan *, int);
char getPacmanDirection2(PacMan *, int);

#endif
