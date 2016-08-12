#include "..header/gameBoard.h"
#include "..header/fruit.h"
#include "stdio.h"
#include "stdlib.h"

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
