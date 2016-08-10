#include "../header/singlePlayerGameController.h"
#include "../header/pacman.h"
#include "../header/menu.h"
#include <ncurses.h>
#include <unistd.h>

#define DELAY1 50000
#define DELAY2 50000
int max_y = 20;
int max_x = 26;

int fruit1 = '.';
int fruit2 = 'O';
int fruit3 = '&';
int fruit4 = '@';

int player2_up = 'o';
int player2_down = 'l';
int player2_left = 'k';
int player2_right = ';';

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

    endwin();*/

    getName();

    do{
    choice = mainMenu();

    switch(choice)
    {
        case 1:
        singlePlayerGameController();
        break;

        case 2:
        //options();
        break;

        case 3:
        //aboutTheGame();
        break;

        case 4: //set screen back to defualt and exit game
        choice = 0;
        break;

        default:
        break;
    }

    }while(choice != 0);


    return 0;
}
