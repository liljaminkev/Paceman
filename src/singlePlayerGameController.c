#include "../header/pacman.h"
#include "../header/singlePlayerGameController.h"
#include "../header/gameBoard.h"
#include "../header/fruit.h"
#include "../header/monster.h"
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
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
        exitCondition = singlePlayerGameEngine(&player1, fullPath);

        nodelay(stdscr, FALSE);
        if (exitCondition == -1 && (player1.score == 0))
        {
            clear();
            mvprintw(0, 0, "no level found");
            refresh();
            getch();
        }
        else if (exitCondition == -1 && (player1.lives > 0))
        {
            clear();
            //mvprintw(0, 0, "winner");
            mvprintw(3,5,"              ___                                         _");
            mvprintw(4,5,"             / _ \\                                       | |");
            mvprintw(5,5,"            / /_\\ \\_      _____  ___  ___  _ __ ___   ___| |");
            mvprintw(6,5,"            |  _  \\ \\ /\\ / / _ \\/ __|/ _ \\| '_ ` _ \\ / _ \\ |");
            mvprintw(7,5,"            | | | |\\ V  V /  __/\\__ \\ (_) | | | | | |  __/_|");
            mvprintw(8,5,"            \\_| |_/ \\_/\\_/ \\___||___/\\___/|_| |_| |_|\\___(_)");


            mvprintw(11,5,"                              OOOOOOOOOOOO");
            mvprintw(12,5,"                           OOOOOOOOOOOOOOOOOOO");
            mvprintw(13,5,"                        OOOOOO  OOOOOOOOO  OOOOOO");
            mvprintw(14,5,"                      OOOOOO      OOOOO      OOOOOO");
            mvprintw(15,5,"                    OOOOOOOO  #   OOOOO  #   OOOOOOOO");
            mvprintw(16,5,"                   OOOOOOOOOO    OOOOOOO    OOOOOOOOOO");
            mvprintw(17,5,"                  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
            mvprintw(18,5,"                  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
            mvprintw(19,5,"                  OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO");
            mvprintw(20,5,"                   OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO");
            mvprintw(21,5,"                    OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO");
            mvprintw(22,5,"                      OOOOO   OOOOOOOOOOOOOOO   OOOO");
            mvprintw(23,5,"                        OOOOOO   OOOOOOOOO   OOOOOO");
            mvprintw(24,5,"                           OOOOOO         OOOOOO");
            mvprintw(25,5,"                               OOOOOOOOOOOO");

            mvprintw(30,1,"Press any key to return to main menu ");
            refresh();
            getch();
        }
        else if (exitCondition == -2)
        {
            clear();
            mvprintw(0, 0, "no pacman found on map");
            refresh();
            getch();
        }
        else if (player1.lives == 0)
        {
            clear();
            //mvprintw(0, 0, "lose");
            mvprintw(2,5,"                                        _ ");
            mvprintw(3,5,"                            ___ _ __ __| |");
            mvprintw(4,5,"                           / _ \\ '_ (_-<_|");
            mvprintw(5,5,"                           \\___/ .__/__(_)");
            mvprintw(6,5,"                               |_|        ");
            mvprintw(7,5,"  ___      _   _             _         _                  _     _   _           _ ");
            mvprintw(8,5," | _ ) ___| |_| |_ ___ _ _  | |_  _ __| |__  _ _  _____ _| |_  | |_(_)_ __  ___| |");
            mvprintw(9,5," | _ \\/ -_)  _|  _/ -_) '_| | | || / _| / / | ' \\/ -_) \\ /  _| |  _| | '  \\/ -_)_|");
            mvprintw(10,5," |___/\\___|\\__|\\__\\___|_|   |_|\\_,_\\__|_\\_\\ |_||_\\___/_\\_\\__|  \\__|_|_|_|_\\___(_)");


            mvprintw(14,5,"                               OOOOOOOOOOOOO");
            mvprintw(15,5,"                            OOOOOOOOOOOOOOOOOOO");
            mvprintw(16,5,"                         OOOOOO  OOOOOOOOO  OOOOOO");
            mvprintw(17,5,"                       OOOOOO      OOOOO      OOOOOO");
            mvprintw(18,5,"                     OOOOOOOO  #   OOOOO  #   OOOOOOOO");
            mvprintw(19,5,"                    OOOOOOOOOO    OOOOOOO    OOOOOOOOOO");
            mvprintw(20,5,"                   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
            mvprintw(21,5,"                   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
            mvprintw(22,5,"                   OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
            mvprintw(23,5,"                   OOOOOOOOOOOOOO           OOOOOOOOOOOO");
            mvprintw(24,5,"                    OOOOOOOOOOO   OOOOOOOOO   OOOOOOOOO");
            mvprintw(25,5,"                      OOOOOOOO  OOOOOOOOOOOOO  OOOOOOO");
            mvprintw(26,5,"                        OOOOOO OOOOOOOOOOOOOOO OOOOOO");
            mvprintw(27,5,"                         OOOOOOOOOOOOOOOOOOOOOOOOOO");
            mvprintw(28,5,"                            OOOOOOOOOOOOOOOOOOOO");

            mvprintw(32,1,"Press any key to return to main menu");
            refresh();
            getch();
        }
        else if(player1.quit == 0)
        {
            clear();
            mvprintw(0, 0, "have a nice day");
            mvprintw(1, 0, "%d", player1.score);
            refresh();
            getch();
        }

        level++;
    } while(player1.quit && player1.lives && (exitCondition > 0));



    return 0;
}

char startGame(PacMan *p1, Monster mon[], GameBoard *gb, Fruit f[][26], WINDOW *game, WINDOW *score)
{
    char k = 0;
            nodelay(game, FALSE);
            curs_set(FALSE);
            draw_borders(game);
            draw_borders(score);
            displayBoard(gb, game);
            displayFruit(f, game);
            displayPacman(p1, game);
            //display number of lives
            displayLives(p1, score);
            //display score
            displayScore(p1, score);
	        displayMonsters(mon, gb->numMonster, game);
            wrefresh(game);
            wrefresh(score);
            k = wgetch(game);
    return k;
}

int singlePlayerGameEngine(PacMan *p1, char *fileName)
{
    //ensure filename gets to function
    if (test == 2)
    {
        clear();
        mvprintw(0, 0, "%s", fileName);
        refresh();
        getch();
    }

    clear();
    GameBoard gb;
    gameBoardInitialize(&gb);
    int result = gameBoardLoad(&gb, fileName);

    if(result < 0)
    return result;

    char keypress;              //userinput from keyboard
    int winx, winy;
    Fruit f[20][26];

    pthread_t monsterThread;
    int monsterThreadRet;
    threadData threadData;

    //window stuff
    WINDOW *gameArea = newwin(20, 28, 0, 0);
    WINDOW *score = newwin(20,15, 0, 28);

    curs_set(FALSE);



    //init vars
    setFruit(gb.fruit);
    initFruit(f, gb.map);
    pacmanSetInitialPoint(p1, gb.map);

    Monster mon[gb.numMonster];
    initializeMonsters(mon, gb.map, gb.numMonster);

    threadData.pacPointer = p1;
    threadData.gbPointer = &gb;
    threadData.monPointer = mon;

   //diplay level
   displayLevel(&gb, score);

do{
    keypress = startGame(p1, mon, &gb, f, gameArea, score); //display gameboard and wait for input


    nodelay(gameArea, TRUE);        //once input recived turn off delay from keyboard
    monsterThreadRet = pthread_create(&monsterThread, NULL, moveMonster, (void*) &threadData);
    do{
	int i=0;

        movePacman(p1, gb.wall, gb.map);

	i=eatFruit(p1->x_position,p1->y_position,&p1->score, f);

		if(i==1)
		{
			eatFruit1(&gb.numFruit1);
		}

		if(i==2)
		{
			eatFruit2(&gb.numFruit2);
		}

		if(i==3)
		{
			eatFruit3(&gb.numFruit3);
		}

		if(i==4)
		{
			eatFruit4(&gb.numFruit4);
		}

        draw_borders(gameArea);
        draw_borders(score);
        displayBoard(&gb, gameArea);
        displayFruit(f, gameArea);
        displayPacman(p1, gameArea);
	    displayScore(p1, score);
	    displayMonsters(mon, gb.numMonster, gameArea);
        wnoutrefresh(gameArea);
        wnoutrefresh(score);
        doupdate();

        usleep(DELAY2);

        if(p1->y_direction != 0)
        usleep(DELAY2+DELAY2);

        keypress = wgetch(gameArea);
        getPacmanDirection1(&p1->x_direction, &p1->y_direction, keypress, &p1->sprite);

        p1->quit = quit(keypress);
        gb.pause_state = setPauseState(keypress);

        if(gb.pause_state == 1)
        pauseGame(&gb.pause_state);

	if(pacmanOnMonster(p1, mon, gb.numMonster) ==  0)
		break;

    }while(0 != p1->quit && gb.numFruit1 > 0);
    --(p1->lives);
    pthread_cancel(monsterThread);

    p1->x_position = p1->x_start;
    p1->y_position = p1->y_start;

}while((0 != p1->quit) && (gb.numFruit1 > 0) && (p1->lives > 0));

    delwin(gameArea);
    delwin(score);
    return 1;
}

int pacmanOnMonster(PacMan *p1, Monster *mon, int n_monsters)
{
	if((p1 == NULL) || (mon == NULL))
		return 2;
	for(int i = 0; i < n_monsters; ++i)
	{
		if((p1->x_position == mon[i].x_position) && (p1->y_position == mon[i].y_position))
			return 0;
	}
	return 1;
}

int setPauseState(char keypress)
{
    if (keypress != 'p')
    return 0;
    else
    {
        return 1;
    }
}

void pauseGame(int *pauseState)
{
    char k = 0;
    curs_set(FALSE);
    WINDOW *pauseWindow = newwin(10, 10, 0, 0);
    nodelay(pauseWindow, FALSE);

    while(k != 'p')
    {
        mvwprintw(pauseWindow, 5,2, "Paused");
        k = wgetch(pauseWindow);
    }
    *pauseState = 0;
}
