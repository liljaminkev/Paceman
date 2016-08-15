#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <ncurses.h>

typedef struct
{
    int x;
    int y;
} Direction;

typedef struct
{
    char wall;          //char to hold wall
    char fruit[4];      //char array to hold fruit
    char map[20][26];   //map generated by text file
    int numFruit1;      //number of first fruit on level
    int numFruit2;      //number of second
    int numFruit3;      //number of thrid
    int numFruit4;      //number of fourth
    int numPacman;      //number of pacman
    int numMonster;     //number of monsters
    int pause_state;    //for pause loop
    int run_state;      //for run loop
} GameBoard;

void draw_borders(WINDOW *);                //draw boarders
void gameBoardInitialize(GameBoard *);      //set to to run state
void displayBoard(GameBoard *, WINDOW *);   //display map
int gameBoardLoad(GameBoard *, char []);    //load map from fileName
int numBytesRead(FILE *);

#endif
