#include "../header/monster.h"
#include "../header/gameBoard.h"
#include <ncurses.h>
#include "../header/pacman.h"
#include "../header/singlePlayerGameController.h"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define MAGIC 5
#define OUTERWALL 'X'
#define M_SPEED 200000 //Lower this value, the faster the monsters will move
void randomDirection(int *, int *);

void *moveMonster(void *t)
{
	threadData* t1 = (threadData *)t;
	PacMan *p1 = t1->pacPointer;
	Monster *mon = t1->monPointer;
	GameBoard *gb = t1->gbPointer;

	srand(time(NULL));
	int x_next, y_next;
	int magicNum = MAGIC;
	for(int i = 0; i < gb->numMonster; ++i)
	{
		randomDirection(&(mon[i].x_direction), &(mon[i].y_direction));
		mon[i].x_position = mon[i].start_positionX;
		mon[i].y_position = mon[i].start_positionY;
	}
	while(0 != p1->quit)
	{
		for(int i = 0; i < gb->numMonster; ++i)
		{
			y_next = mon[i].y_position + mon[i].y_direction;
			x_next = mon[i].x_position + mon[i].x_direction;
			if((gb->map[y_next][x_next] == gb->wall) || (y_next == -1) || (y_next == 18) || (x_next == -1) || (x_next == 26))
			{
				randomDirection(&(mon[i].x_direction), &(mon[i].y_direction));
				continue;
			}
			if(magicNum == 0)
			{
				randomDirection(&(mon[i].x_direction), &(mon[i].y_direction));
				magicNum = MAGIC;
				continue;
			}
			--magicNum;
			mon[i].y_position = y_next;
			mon[i].x_position = x_next;
		}
		usleep(M_SPEED);
	}
}

void displayMonsters(Monster *mon, int numMonsters, WINDOW *gameArea)
{
	for(int i = 0; i < numMonsters; ++i){
		mvwprintw(gameArea, mon[i].y_position+1, mon[i].x_position+1, "%c", mon[i].sprite);
	}
}

void monsterRespawn(Monster *mon, int numMonsters)
{   int i;
    for(i = 0; i < numMonsters; i++)
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
void randomDirection(int *x, int *y)
{
	int r;
	r = (rand()%4) + 1;
	switch(r)
	{
		case 1:
			*x = 0;
			*y = -1;
			break;
		case 2:
			*x = 0;
			*y = 1;
			break;
		case 3:
			*x = -1;
			*y = 0;
			break;
		case 4:
			*x = 1;
			*y = 0;
			break;
	}
}
void initializeMonsters(Monster mon[], char a[][26], int numMonsters)
{
	int i;
	int j;
	int k;
	for(i = 0; i < numMonsters; ++i)
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
					a[j][k] = ' ';
					break;
				}
			}
			if(mon[i].start_positionX > 0)
				break;
		}
	}
}
