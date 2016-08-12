//#include "..header/gameBoard.h"
//#include "..header/pacman.h"
#include "stdio.h"
#include "stdlib.h"

char fruit[20][26];

typedef struct GameBoard
{
    char wall;
    char fruit1;
    char map[20][26];
} GameBoard;

void displayBoard(struct GameBoard gameboard);

void gameBoardInitialize(GameBoard *a)
{
	a->wall='3';
	a->fruit1='-';
}


void displayBoard(struct GameBoard gameboard)
{
    int i,j;

    for ( i = 0; i <20; i++ ){
        for (j=0; j<26; j++)
	{
	    int a=0;
	    if(gameboard.map[i][j]>0)

        { printf("%c", gameboard.map[i][j]);
          a=1; }

        if(fruit[i][j]>0)
        printf("%c", fruit[i][j]);

        if(fruit[i][j]=='\0' && a==0)
        printf(" ");

    }
    }
}



int main ()
{
    struct GameBoard gameboard;

//all this code below should be in a function

    FILE* fp = NULL;
    char c;
    int i,j;

    fp = fopen("stage1.txt", "r");
    if (!fp)
        exit(1);

    for ( i = 0; i < 20; i++ )
    { for (j=0; j<26; j++)
	{
        c = getc(fp);
        if(c=='3' || c=='\n' || c==' ' || c=='M' || c=='<')
            gameboard.map[i][j]=c;
        else
            gameboard.map[i][j]=0;

       if(c=='-' || c=='*' || c=='&' || c=='$')
        fruit[i][j]=c;

        //add if clause for monsters.
        //add new if clause for pacman

    }
    }

    fruit[0][0]=0;
    fruit[0][1]=0;
    fclose(fp);

//end of function

    displayBoard(gameboard);

    return 0;
}
