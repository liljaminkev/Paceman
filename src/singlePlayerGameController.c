#include "singlePlayerGameController.h"
#include "pacman.h"
#include <ncurses.h>
#include <unistd.h>
#define DELAY2 50000

int startGame(PacMan *a)
{
    char k;
    mvprintw(a->y_position, a->x_position, "%c", a->sprite);
    k = getch();
    k = getDirection1(a, k);
    return k;
}

int singlePlayerGameController()
{
    int exitCondition;
    PacMan player1;
    pacmanInitialize(&player1); //set pacman initial state;

    exitCondition = singlePlayerGameInstance(&player1);

    return exitCondition;
}

int singlePlayerGameInstance(PacMan *p1)
{
    int max_y = 20, max_x = 26; //game board size
    char keypress;              //userinput from keyboard
    keypress = startGame(p1); //display gameboard and wait for input
    nodelay(stdscr, TRUE);        //once input recived turn off delay from keyboard

    do{
        clear();

        mvprintw(p1->y_position, p1->x_position, "%c", p1->sprite); //print p
        refresh();

        usleep(DELAY2);

        keypress = getch();

        p1->sprite = getDirection1(&p1, keypress);

        movePacman(p1);


    }while(keypress != 'q');

    return 0;
}
