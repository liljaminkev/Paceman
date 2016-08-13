#include "../header/monster.h"
#include "../header/gameBoard.h"
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
