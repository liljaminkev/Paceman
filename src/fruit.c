#include "../header/fruit.h"
#include "../header/pacman.h"

void eatFruit(PacMan *p1, Fruit f1[][26])
{
    if(f1[p1->y_position][p1->x_position] > 0)
    {
        p1->score += f1[p1->y_position][p1->x_position];
        f1[p1->y_position][p1->x_position] = 0;
    }
}
