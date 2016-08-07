#include "singlePlayerGameController.h"
#include <ncurses.h>
#include <unistd.h>
#define DELAY1 50000

int max_y = 20;
int max_x = 26;

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
