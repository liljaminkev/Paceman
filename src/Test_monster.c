#include "../header/monster.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int numMonsters = 2;
    Monster mon[2];

    mon[0].alive = 1;
    mon[0].x_position = 0;
    mon[0].y_position = 2;
    mon[0].start_positionX = 0;
    mon[0].start_positionY = 0;

    mon[1].alive = 0;
    mon[1].x_position = 0;
    mon[1].y_position = 3;
    mon[1].start_positionX = 1;
    mon[1].start_positionY = 1;


    printf("monster 1 is at %d, %d.\n", mon[0].x_position, mon[0].y_position);
    printf("monster 2 is at %d, %d.\n", mon[1].x_position, mon[1].y_position);
    monsterRespawn(mon, numMonsters);
    printf("monster 1 is at %d, %d.\n", mon[0].x_position, mon[0].y_position);
    printf("monster 2 is at %d, %d.\n", mon[1].x_position, mon[1].y_position);

    return 0;
}
