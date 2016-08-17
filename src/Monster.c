#include "../header/monster.h"
#include <ncurses.h>

void moveMonster(Monster *mon)
{
    mon[0].y_position = mon[0].y_position-1;
    mon[0].x_position = mon[0].x_position;
}

void displayMonsters(Monster mon, int numMonsters, WINDOW *gameArea)
{
    mvwprintw(gameArea, mon.y_position+1, mon.x_position+1, "%c", mon.sprite);
}

/*
void monsterRespawn(Monster *mon, int numMonsters)
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
*/

void initilizeMonsters(Monster mon[], char a[][26], int numMonsters)
{
    int i;
    int j;
    int k;
    for(i=0; i < numMonsters; i++)
    {
        mon[i].start_positionX = -1;
        mon[i].x_direction = 0;
        mon[i].y_direction = 0;
        mon[i].state = 0;
        mon[i].alive = 1;
        mon[i].sprite = 'M';
        for (j= 0; j < 20; j ++)
        {
            for(k = 0; k < 26; k++)
            {
                if(a[j][k] == 'M')
                {
                    mon[i].start_positionX = k;
                    mon[i].start_positionY = j;
                    mon[i].x_position = mon[i].start_positionX;
                    mon[i].y_position = mon[i].start_positionY;
                    a[j][k] = 0;
                    break;
                }
            }
            if(mon[i].start_positionX > 0)
            break;
        }
    }
}
