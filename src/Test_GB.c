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
    //declare vars
    GameBoard gb;
    PacMan p1;
    Fruit f[20][26];
    int result;
    char fileName[50];
    int winx, winy;

    //init vars

    initFruit(f);
    pacmanInitialize(&p1);
    gameBoardInitialize(&gb);

    //set up windows
    initscr();
    noecho();
    curs_set(FALSE);

    getmaxyx(stdscr, winy, winx);

    WINDOW *gameArea = newwin(20, 28, 0, 0);
    WINDOW *score = newwin(20,15, 0, 28);


    //load gameboard data
    fileNameCreater(fileName, 1);
    result = gameBoardLoad(&gb, &p1, f, fileName);

    //declare monsters from gameboard and init
    Monster mon[gb.numMonster];

    //monsterInitialize(mon, gb.numMonster, &gb);

    //display gameboards
    draw_borders(gameArea);
    displayBoard(&gb, gameArea);
    displayFruit(f, gameArea);
    displayPacman(&p1, gameArea);
    displayMonsters(mon, gb.numMonster, gameArea);

    draw_borders(score);

    wrefresh(gameArea);
    wrefresh(score);
    sleep(10);
    endwin();


    return 0;
}
