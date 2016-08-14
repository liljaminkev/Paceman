#include "../header/fruit.h"


//fruit characters
char fruit[] = {'.', '-', 'o', 'O' } ;

//for customizing fruit types
void setFruit(char input, int index)
{
    fruit[index] = input;
}

void initFruit(Fruit arr[][26])
{
    int ii, jj;

    for ( ii = 0; ii <20; ii++ )
    {
        for (jj = 0; jj<26; jj++)
        {
            arr[ii][jj] = 0;
      }
    }
}

//assign pt value to fruit being eaten and add to score
void eatFruit(PacMan *p1, Fruit f1[][26])
{
    if(f1[p1->y_position][p1->x_position] > 0)
    {
        if(f1[p1->y_position][p1->x_position] == fruit[0])
        {
            p1->score += 1;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit[1])
        {
            p1->score += 10;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit[2])
        {
            p1->score += 100;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit[3])
        {
            p1->score += 100;
            f1[p1->y_position][p1->x_position] = 0;
        }

    }
}

//display fruit array to user
void displayFruit(Fruit fruit[][26], WINDOW *levelBuffer)
{
    int i,j;
    char character;

    for ( i = 0; i <20; i++ )
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
