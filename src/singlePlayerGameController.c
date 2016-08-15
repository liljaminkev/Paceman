#include "../header/pacman.h"
#include "../header/singlePlayerGameController.h"
#include "../header/gameBoard.h"
#include "../header/fruit.h"
#include "../header/monster.h"
#include <string.h>
#include <ncurses.h>
#define DELAY2 50000

int max_y = 20;
int max_x = 26;
const int test = 0;

int quit(char input)
{
    if (input == 'q')
    return 0;
    else
    return 1;
}

void fileNameCreater(char *file, int level)
{
    char alevel[20];
    const char partialPath[] = "../single_player_maps/Level_";

    sprintf(alevel, "%d", level);
    strcpy(file, partialPath);
    strcat(file, alevel);
    strcat(file, ".txt");
}

int singlePlayerGameController()
{

    int exitCondition;
    PacMan player1;
    char fullPath[100];
    int level = 1;

    pacmanInitialize(&player1); //set pacman initial state;

    do {
        fileNameCreater(fullPath, level);

        //ensure filename is printed
        if (test == 1)
        {
            clear();
            mvprintw(0, 0, "%s", fullPath);
            refresh();
            getch();
        }


        player1 = singlePlayerGameEngine(player1, fullPath);
    } while(player1.quit);


    return 0;
}

char startGame(int x, int y, char sprite)
{
    char k;
    clear();
    //displayPacman
    refresh();
    k = getch();
    return k;
}

PacMan singlePlayerGameEngine(PacMan p1, char *fileName)
{
    //ensure filename gets to function
    if (test == 2)
    {
        clear();
        mvprintw(0, 0, "%s", fileName);
        refresh();
        getch();
    }

    char keypress;              //userinput from keyboard
    WINDOW *gameArea = newwin(20, 28, 0, 0);
    WINDOW *score = newwin(20,15, 0, 28);
    GameBoard gb;
    gameBoardInitialize(&gb);

    keypress = startGame(p1.x_position, p1.y_position, p1.sprite); //display gameboard and wait for input
    nodelay(stdscr, TRUE);        //once input recived turn off delay from keyboard

    do{
        movePacman(&p1, gb.wall, gb.map);
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
