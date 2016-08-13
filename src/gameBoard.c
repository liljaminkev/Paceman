#include "../header/gameBoard.h"
#include "../header/pacman.h"
#include "../header/monster.h"
#include "../header/fruit.h"
#include "stdio.h"
#include <stdlib.h>
#include <ncurses.h>


//function to draw boarder around windows
void draw_borders(WINDOW *screen) {
  int x, y, i;
  getmaxyx(screen, y, x);

  // 4 corners
  mvwprintw(screen, 0, 0, "X");
  mvwprintw(screen, y - 1, 0, "X");
  mvwprintw(screen, 0, x - 1, "X");
  mvwprintw(screen, y - 1, x - 1, "X");

  // sides
  for (i = 1; i < (y - 1); i++) {
    mvwprintw(screen, i, 0, "X");
    mvwprintw(screen, i, x - 1, "X");
  }

  // top and bottom
  for (i = 1; i < (x - 1); i++) {
    mvwprintw(screen, 0, i, "X");
    mvwprintw(screen, y - 1, i, "X");
  }
}

void gameBoardInitialize(GameBoard *a)
{
    //used to zero out a game board instance
     a->wall = '3';
     a->fruit[0] = '-';
     a->fruit[1] = '*';
     a->fruit[2] = '&';
     a->fruit[3] = '$';
     a->numFruit1 = 0; //number of first fruit on level
     a->numFruit2 = 0; //number of second
     a->numFruit3 = 0; //number of thrid
     a->numFruit4 = 0; //number of fourth
     a->numPacman = 0;    //number of pacman
     a->numMonster = 0;    //number of monsters
     a->pause_state = 0;
     a->run_state = 1;

}

void displayBoard(GameBoard *gameboard, WINDOW *levelBuffer)
{
  int i,j;
  char character;

  for ( i = 0; i < 20; i++)
  {
      for (j = 0; j< 26; j++)
      {
          if(gameboard->map[i][j] > 0 )
          {
              character = gameboard->map[i][j];
              mvwprintw(levelBuffer, i+1, j+1, "%c", character);
          }

    }
  }
}

int gameBoardLoad(GameBoard *gameboard, PacMan *pacman, Fruit fruitArr[][26], char fileName[])
{   FILE* fp = NULL;
    char charInput;
    char str[27];
    int i,j;
    int numRead;
    int currentPos;

    fp = fopen(fileName, "r");
    if (!fp)
        return -1;

    //get wall
    fgets(str, 27, fp);

    if(fp)
    {
        gameboard->wall = str[0];
    }

    //get fruit
    fgets(str, 27, fp);
    if(fp)
    {
        numRead = numBytesRead(fp);
        for(i = 0; i < numRead; i++)
        {
            if (str[i] > 32 && str[i] < 127 )
            {
                gameboard->fruit[i] = str[i];
                setFruit(str[i], i);
            }
        }
    }

    for ( i = 0; i < 18; i++ )
    {
        fgets(str, 100, fp);
        for (j = 0; j<26; j++)
	       {
               charInput = str[j];

               if(charInput == gameboard->wall || charInput == ' ')
               gameboard->map[i][j] = charInput;

               else if(charInput == gameboard->fruit[0] ||
                   charInput == gameboard->fruit[1] ||
                   charInput == gameboard->fruit[2] ||
                   charInput == gameboard->fruit[3])
               {
                   fruitArr[i][j] = charInput;

                   gameboard->map[i][j] = ' ';

                   if(charInput == gameboard->fruit[0])
                   gameboard->numFruit1++;

                   else if(charInput == gameboard->fruit[1])
                   gameboard->numFruit2++;

                   else if(charInput == gameboard->fruit[2])
                   gameboard->numFruit3++;

                   else
                   gameboard->numFruit4++;

               }

               else if(charInput == 'M')
               {
                   gameboard->numMonster++;
                   gameboard->map[i][j] = charInput;
               }

               else if(charInput == '<')
               {
                   pacman->x_start=i;
                   pacman->y_start=j;
                   pacman->x_position = i;
                   pacman->y_position = j;
                   gameboard->numPacman++;
                   gameboard->map[i][j] = ' ';
               }
           }
       }
    fclose(fp);

    if (gameboard->numPacman == 1)
    return 1;
    else
    return -1;
}

int numBytesRead(FILE *ptr)
{
    static int lastPos = 0;
    int currentPos = ftell(ptr);
    int diffrence = currentPos - lastPos;
    lastPos = currentPos;

    return diffrence;
}
void monsterInitialize(int numMons, Monster *mon, GameBoard *board)
{
    int i, j, k;
    //for(i = 0; i < board.numMonster; i++)
    //{
        mon->start_positionX = -1;
        mon->x_direction = 0;
        mon->y_direction = 0;
        mon->state = 0;
        mon->alive = 0;
        mon->sprite = 'M';

        //find monster's X Y
        for(j = 0; j < 18; j++)
        {
            for(k = 0; k < 26; k++)
            {
                if (board->map[j][k] == 'M')
                {
                    mon->start_positionX = k;
                    mon->start_positionY = j;
                    board->map[j][k] = ' ';
                    mon->x_position = k;
                    mon->y_position = j;
                    break;
                }
            }
            if(mon->start_positionX != -1)
            break;
        }
    //}

}
