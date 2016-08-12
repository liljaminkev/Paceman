//#include "..header/gameBoard.h"
//#include "..header/pacman.h"
#include "stdio.h"
#include "stdlib.h"

//#########################
typedef struct GameBoard
{
    char wall;
    char monster;
    char fruit1;
    char map[20][26];
    int numFruit1;
    int pacman;
    int pause_state;
    int run_state;
} GameBoard;

typedef struct PacMan
{
    int x_start;
    int y_start;
    char sprite;
} PacMan;


void pacmanInitialize(PacMan *a);
void gameBoardInitialize(GameBoard *a);
void displayBoard(struct GameBoard gameboard);

void pacmanInitialize(PacMan *a)
{
    a->y_start = 0;
    a->x_start = 0;
    a->sprite = '<';
}
//##################################

void gameBoardInitialize(GameBoard *a)
{
	a->wall='3';
	a->monster='M';
	a->fruit1='-';
	a->numFruit1=10;
	a->pacman=1;
	a->pause_state=0;
	a->run_state=0;
}

void displayBoard(struct GameBoard gameboard)
{
    int i,j;
    for ( i = 0; i <20; i++ ){
        for (j=0; j<26; j++)
	{
        printf("%c", gameboard.map[i][j]);
    }}
}

int main ()
{
    FILE* fp = NULL;
    char c;
    int i,j;

    struct GameBoard gameboard;
    struct PacMan pacman;


    fp = fopen("stage1.txt", "r");

    if (!fp)
        exit(1);

    for ( i = 0; i < 20; i++ )
    { for (j=0; j<26; j++)
	{
        c = getc(fp);
	    gameboard.map[i][j]=c;
		if(c=='-')
		     gameboard.numFruit1++;

		if(c=='<')
		{ pacman.x_start=i;
		  pacman.y_start=j;}


    }}

    printf("\nFruit1:%d\n",gameboard.numFruit1);
    printf("Pacman x pos: %d\n",pacman.x_start);
    printf("Pacman y pos: %d\n",pacman.y_start);

    displayBoard(gameboard);
    fclose(fp);

    return 0;
}
