#ifndef _BACK_H
#define _BACK_H
#include <ncurses.h>

//---------------TypeDefs------------------
typedef char Fruit;

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

typedef struct
{
    int start_positionX;
    int start_positionY;
    int x_position;
    int y_position;
    int x_direction;
    int y_direction;
    int state;
    int alive;
    int speed;
    char sprite;
} Monster;


//-----------------monsters Functions-------------------

void monsterRespawn(Monster *, int);
void moveMonster(Monster *);
//-------------------pacman-----------------------------

void pacmanInitialize(PacMan *);
void pacmanNextMove(PacMan *);
void movePacman(PacMan*, GameBoard*);
void getPacmanDirection1(int *, int *, int, char *);
void getPacmanDirection2(int *, int *, int, char *);

//------------------SinglePlayer Functions------------------------
PacMan singlePlayerGameEngine(PacMan, char *);
char startGame(int, int, char);
int singlePlayerGameController();
int quit(char);
void fileNameCreater(char *, int);

//--------------fruit Functions---------------------
//functions to manipulate characters
void setFruit(char, int);
void initFruit(Fruit [][26]);
void eatFruit(PacMan *, Fruit [][26]);
void displayFruit(Fruit [][26], WINDOW *);

//---------------gameboard Functions-----------------

void gameBoardInitialize(GameBoard *);
int gameBoardLoad(GameBoard *, PacMan *, Fruit [][26], char []);
int numBytesRead(FILE *);
void monsterInitialize(int, Monster *, GameBoard *);

//---------------

#endif
