#include "../header/twoPlayerGameController.h"
#include <ncurses.h>
#include <unistd.h>

PacMan twoPlayerGameInstance(PacMan p1, PacMan p2)
{
    //int max_y = 20, max_x = 26; //game board size
    char keypress;              //userinput from keyboard
    keypress = startGame(p1.x_position, p1.y_position, p1.sprite); //display gameboard and wait for input
    nodelay(stdscr, TRUE);        //once input recived turn off delay from keyboard

    do{
        movePacman(&p1);
        movePacman(&p2)

        getPacmanDirection1(&p1.x_direction, &p1.y_direction, keypress, &p1.sprite);
        getPacmanDirection2(&p2.x_direction, &p2.y_direction, keypress, &p2.sprite);
        clear();

        mvprintw(p1.y_position, p1.x_position, "%c", p1.sprite); //print p
        mvpringw(p2.y_position, p2.x_position, "%c", p2.sprite);
        refresh();

        usleep(DELAY2);

        keypress = getch();

        p1.quit = quit(keypress);

    }while(0 != p1.quit);
    nodelay(stdscr, FALSE);
    return p1;
}
int twoPlayerGameController()
{
    int exitCondition;
    PacMan player1;
    PacMan player2;
    pacmanInitialize(&player1); //set pacman initial state;
    pacmanInitialize(&player2);

    player1 = singlePlayerGameInstance(player1, player2);

    mvprintw(0, 0, "%c", player1.sprite);
    getch();

    return 0;
}
