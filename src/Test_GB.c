#include "../header/gameBoard.h"
#include "../header/pacman.h"
#include "../header/monster.h"
#include "../header/fruit.h"
#include "../header/singlePlayerGameController.h"
#include "stdio.h"
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

int main()
{
    //load and init gameboard
    GameBoard gb;
    PacMan p1;
    Fruit f[20][26];
    int result;
    char fileName[50];
    int winx, winy;
    int ii, jj;

    for ( ii = 0; ii <20; ii++ )
    {
        for (jj = 0; jj<26; jj++)
        {
            f[ii][jj] = 0;
      }
    }



    initscr();
    noecho();
    curs_set(FALSE);

    getmaxyx(stdscr, winy, winx);

    WINDOW *win1 = newwin(20, 28, 0, 0);


    pacmanInitialize(&p1);

    fileNameCreater(fileName, 1);

    gameBoardInitialize(&gb);

    result = gameBoardLoad(&gb, &p1, f, fileName);

    Monster mon[gb.numMonster];

    int i;
    for(i = 0; i < gb.numMonster; i++)
    {
        monsterInitialize(&mon[i]);
    }

    draw_borders(win1);
    displayBoard(&gb, win1);
    //displayFruit(f, win1);

    wrefresh(win1);
    sleep(10);
    endwin();


    return 0;
}
