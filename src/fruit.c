#include "../header/gameBoard.h"
#include "../header/fruit.h"
#include <ncurses.h>


//fruit characters
static char fruit[4];

//for customizing fruit types
void setFruit(char input[])
{
    int i;
    for (i = 0; i < 4; i++)
    fruit[i] = input[i];
}

void initFruit(Fruit arr[][26], char map[][26])
{
    int i, j;

    for ( i = 0; i <20; i++ )
    {
        for (j = 0; j<26; j++)
        {
            if(map[i][j] == fruit[0] || map[i][j] == fruit[1] || map[i][j] == fruit[2] || map[i][j] == fruit[3] )
            {
                arr[i][j] = map[i][j];
                map[i][j] = ' ';
            }
            else
            arr[i][j] = 0;
      }
    }
}

//assign pt value to fruit being eaten and add to score
int eatFruit(int x, int y, int *score, Fruit f1[][26])
{
    if(f1[y][x] > 0)
    {
        if(f1[y][x] == fruit[0])
        {
           *score += 1;
            f1[y][x] = 0;
            return 1;
        }
        else if(f1[y][x] == fruit[1])
        {
            *score += 10;
            f1[y][x] = 0;
	   return 2;
        }
        else if(f1[y][x] == fruit[2])
        {
           *score += 100;
            f1[y][x] = 0;
	   return 3;
        }
        else if(f1[y][x] == fruit[3])
        {
           *score += 100;
            f1[y][x] = 0;
	   return 4;
        }
    }

	return 0;
}

//decrement fruits 1,2,3,4
void eatFruit1(int *numFruit1)
{
	*numFruit1 += -1;
}

void eatFruit2(int *numFruit2)
{
	*numFruit2--;
}

void eatFruit3(int *numFruit3)
{
	*numFruit3--;
}

void eatFruit4(int *numFruit4)
{
	*numFruit4--;
}

//display fruit array to user
void displayFruit(Fruit fruit[][26], WINDOW *levelBuffer)
{
    int i,j;
    char character;

    for ( i = 0; i <18; i++ )
    {
        for (j = 0; j<26; j++)
        {
            if (fruit[i][j] != 0)
            {
                character = fruit[i][j];
                mvwprintw(levelBuffer, i+1, j+1, "%c", character);
            }
      }
    }

}
