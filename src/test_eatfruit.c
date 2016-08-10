#include "../header/singlePlayerGameController.h"
#include "../header/pacman.h"
#include "../header/fruit.h"
#include <ncurses.h>
#include <unistd.h>

int main()
{
    PacMan player;
    Fruit fruits[20][26];

    pacmanInitialize(&player);

    fruits[0][1] = 2;
    fruits[0][2] = 3;

    for(int i = 0; i < 4; i ++)
    {
        printf("Pacman score is: %d\n", player.score);
        printf("point value of tile %d %d is: %d\n", 0, i, fruits[0][i]);
        eatFruit(&player, fruits);
        printf("Pacman Score is now: %d\n", player.score);
        printf("point value of tile %d %d is now: %d\n", 0, i, fruits[0][i]);
        player.x_position +=1;

    }
    return 0;
}
