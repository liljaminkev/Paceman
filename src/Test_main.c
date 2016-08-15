#include "../header/gameboard.h"
#include "../header/pacman.h"
#include "../header/monster.h"
#include "../header/fruit.h"
#include "../header/singlePlayerGameController.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    initscr();
    clear();
    noecho();
    singlePlayerGameController();
    endwin();
    return 0;
}
