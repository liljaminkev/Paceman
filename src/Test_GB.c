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

    int i;
    for(i = 0; i < gb.numMonster; i++)
    {
        monsterInitialize(gb.numMonster, &mon[i], &gb);
    }



    //display gameboards
    draw_borders(gameArea);
    displayBoard(&gb, gameArea);
    displayFruit(f, gameArea);
    displayPacman(&p1, gameArea);

    displayMonsters(mon[0], gb.numMonster, gameArea);

    draw_borders(score);

    wrefresh(gameArea);
    wrefresh(score);
    sleep(2);

for (i=0; i < 3; i++)
{
    moveMonster(mon);

    clear();
    draw_borders(gameArea);
    displayBoard(&gb, gameArea);
    displayFruit(f, gameArea);
    displayPacman(&p1, gameArea);
    displayMonsters(mon[0], gb.numMonster, gameArea);

    draw_borders(score);

    wrefresh(gameArea);
    wrefresh(score);
    sleep(2);
}

//test pacman movement
char keypress;              //userinput from keyboard

//ensure filename gets to function
/*if (test == 2)
{
    clear();
    mvprintw(0, 0, "%s", fileName);
    refresh();
    getch();
}
*/
//keypress = startGame(p1.x_position, p1.y_position, p1.sprite); //display gameboard and wait for input
nodelay(stdscr, TRUE);        //once input recived turn off delay from keyboard

do{
    clear();
    movePacman(&p1);
    draw_borders(gameArea);
    draw_borders(score);
    displayBoard(&gb, gameArea);
    displayFruit(f, gameArea);
    displayPacman(&p1, gameArea);
    wrefresh(gameArea);
    wrefresh(score);

    sleep(1);

    keypress = getch();
    getPacmanDirection1(&p1.x_direction, &p1.y_direction, keypress, &p1.sprite);
    p1.quit = quit(keypress);

}while(0 != p1.quit);

nodelay(stdscr, FALSE);
//return p1;


    endwin();


    return 0;
}
