//#include "../header/singlePlayerGameController.h"
#include "../header/pacman.h"
#include "../header/menu.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY1 50000

int fruit1 = '.';
int fruit2 = 'O';
int fruit3 = '&';
int fruit4 = '@';

int main()
{
    //local variables
    int choice;

    /* old code
    //turn off echo and initilize ncurses screen
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);


    exitCode = singlePlayerGameController();

    endwin();
    */

    getName();

    do{
    choice = mainMenu();

    switch(choice)
    {
        case 1:
        //singlePlayerGameController();
        startGame();
        break;

        case 2:
        options();
        break;

        case 3:
        //aboutTheGame();
        break;

        case 4: //set screen back to defualt and exit game
        //choice = 0;
        //quit();
        break;

        default:
        break;
    }

    }while(choice != 0);


    return 0;
}
