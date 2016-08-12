#include "..header/gameBoard.h"
#include "stdio.h"
#include "stdlib.h"

void displayBoard(struct GameBoard gameboard)
{
    int i,j;
    for ( i = 0; i <20; i++ ){
        for (j=0; j<26; j++)
	{
        printf("%c", gameboard.map[i][j]);
    }}
}
