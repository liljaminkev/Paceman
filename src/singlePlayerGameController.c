#include "../header/singlePlayerGameController.h"
#include <ncurses.h>
#include <unistd.h>
#define DELAY2 50000

int max_y = 20;
int max_x = 26;

int quit(char a)
{
    if (a == 'q')
    return 0;
    else
    return 1;
}

int singlePlayerGameController()
{

    int exitCondition;
    PacMan player1;
    pacmanInitialize(&player1); //set pacman initial state;

    player1 = singlePlayerGameInstance(player1);

    return 0;
}

char startGame(int x, int y, char sprite)
{
    char k;
    clear();
    mvprintw(y, x, "%c", sprite);
    refresh();
    k = getch();
    return k;
}

PacMan singlePlayerGameInstance(PacMan p1)
{
    //int max_y = 20, max_x = 26; //game board size
    char keypress;              //userinput from keyboard
    keypress = startGame(p1.x_position, p1.y_position, p1.sprite); //display gameboard and wait for input
    nodelay(stdscr, TRUE);        //once input recived turn off delay from keyboard

    do{
        movePacman(&p1);
        getPacmanDirection1(&p1.x_direction, &p1.y_direction, keypress, &p1.sprite);
        clear();
        mvprintw(p1.y_position, p1.x_position, "%c", p1.sprite); //print p
        refresh();

        usleep(DELAY2);

        keypress = getch();

        p1.quit = quit(keypress);

    }while(0 != p1.quit);
    nodelay(stdscr, FALSE);
    return p1;
}
