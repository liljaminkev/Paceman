#include "../header/monster.h"
#include "../header/gameBoard.h"
#include <ncurses.h>

void displayMonsters(Monster *mon, int numMonsters, WINDOW *gameArea)
{
    int i;
    for(i = 0; i < numMonsters; i++)
    mvwprintw(gameArea, mon[i].y_position, mon[i].x_position, "%c", mon[i].sprite);
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
/*
void monsterInitialize(Monster *mon, int numMons, GameBoard *board)
{
    int i, j, k;
    for(i = 0; i < board->numMonster; i++)
    {
        mon[i].start_positionX = -1;
        mon[i].x_direction = 0;
        mon[i].y_direction = 0;
        mon[i].state = 0;
        mon[i].alive = 0;
        mon[i].sprite = 'M';

        //find monster's X Y
        for(j = 0; j < 18; j++)
        {
            for(k = 0; k < 26; k++)
            {
                if (board->map[j][k] == 'M')
                {
                    mon[i].start_positionX = k;
                    mon[i].start_positionY = j;
                    board->map[j][k] = ' ';
                    mon[i].x_position = k;
                    mon[i].y_position = j;
                    break;
                }
            }
            if(mon[i].start_positionX != -1)
            break;
        }
    }

}
*/
