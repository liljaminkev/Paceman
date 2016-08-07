#include "../header/singlePlayerGameController.h"
#include "../header/pacman.h"
#include <ncurses.h>
#include <unistd.h>
#define DELAY1 50000
#define DELAY2 50000
int max_y = 20;
int max_x = 26;

int player1_up = 'w';
int player1_down = 's';
int player1_left = 'a';
int player1_right = 'd';

int player2_up = 'o';
int player2_down = 'l';
int player2_left = 'k';
int player2_right = ';';

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
