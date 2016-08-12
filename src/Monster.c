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
