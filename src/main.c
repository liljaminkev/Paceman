#include "../header/singlePlayerGameController.h"
#include "../header/pacman.h"
#include <ncurses.h>
#include <unistd.h>
#define DELAY1 50000

int player1_up = 'w';
int player1_down = 's';
int player1_left = 'a';
int player1_right = 'd';

int main()
{
    //local variables
    int exitCode;

    //turn off echo and initilize ncurses screen
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    exitCode = singlePlayerGameController();

    endwin();
    return exitCode;
}
