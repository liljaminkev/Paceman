#include "../header/menu.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY1 50000

int main()
{
    //local variables
    int choice;

    //turn off echo and initilize ncurses screen
    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    getName();

    do{
    choice = mainMenu();

    switch(choice)
    {
        case 1:
        startGameMenu();
        break;

        case 2:
        options();
        break;

        case 3:
        aboutTheGame();
        break;

        case 4: //set screen back to defualt and exit game
        //choice = 0;
        choice = quitPrompt();
        break;

        default:
        break;
    }

    }while(choice != 0);

    endwin();
    return 0;
}
