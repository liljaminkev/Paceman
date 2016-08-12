#include "../header/monster.h"
void monsterRespawn(Monster mon[], int numMonsters)
{
    for(int i = 0; i < numMonsters; i++)
    {
        if (mon[i].alive == 0)
        {
            mon[i].x_position = mon[i].start_positionX;
            mon[i].y_position = mon[i].start_positionY;
            mon[i].sprite = 'M';
            mon[i].alive = 1;
        }
    }
}

void monsterInitialize(Monster *a)
{
    a->start_positionX=0;
    a->start_positionY=0;
    a->x_position=0;
    a->y_position=0;
    a->x_direction=0;
    a->y_direction=0;
    a->state=0;
    a->alive=0;
    a->sprite='M';

}
