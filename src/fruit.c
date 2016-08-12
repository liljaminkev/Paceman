#include "../header/fruit.h"
#include "../header/pacman.h"

//fruit characters
char fruit1 = '-';
char fruit2 = 'O';
char fruit3 = '&';
char fruit4 = '@';

//for customizing fruit types
void setFruit1(char input)
{
    fruit1 = input
}

void setFruit2(char input)
{
    fruit2 = input;
}

void setFruit3(char input)
{
    fruit3 = input;
}

void setFruit4(char input)
{
    fruit4 = input;
}

void eatFruit(PacMan *p1, Fruit f1[][26])
{
    if(f1[p1->y_position][p1->x_position] > 0)
    {
        if(f1[p1->y_position][p1->x_position] == fruit1)
        {
            p1->score += 1;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit2)
        {
            p1->score += 10;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit3)
        {
            p1->score += 100;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit4)
        {
            p1->score += 100;
            f1[p1->y_position][p1->x_position] = 0;
        }

    }
}
