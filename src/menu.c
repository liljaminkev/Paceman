#include "../header/menu.h"
#include "../header/singlePlayerGameController.h"
int startx = 0;
int starty = 0;

char *choices[] = {
			"Start Game",
			"Options",
			"About The Game",
			"Quit",
		};

int n_choices = sizeof(choices) / sizeof(char *);

void getName()
{
char mesg[]="Enter name:     ";
char str[80];
int row,col;
getmaxyx(stdscr,row,col);
mvprintw(1,2, "%s", mesg);
getstr(str);
mvprintw(3, 2, "Hey %s! Lets play PACKMAN", str);
mvprintw(6, 2, "Press any key to continue     ");
getch();
clear();

}

int mainMenu()
{
WINDOW *menu_win;
int highlight = 1;
int choice = 0;
int input,d;

clear();
cbreak();
startx = (85 - WIDTH) / 2;
starty = (57 - HEIGHT) / 2;

menu_win = newwin(HEIGHT, WIDTH, starty, startx);
keypad(menu_win, TRUE);

//print banner
mvprintw(2, 10,"8888888b.      d8888  .d8888b.  888b     d888        d8888 888b    888 ");
mvprintw(3, 10,"888   Y88b    d88888 d88P  Y88b 8888b   d8888       d88888 8888b   888 ");
mvprintw(4, 10,"888    888   d88P888 888    888 88888b.d88888      d88P888 88888b  888 ");
mvprintw(5, 10,"888   d88P  d88P 888 888        888Y88888P888     d88P 888 888Y88b 888 ");
mvprintw(6, 10,"8888888P8  d88P  888 888        888 Y888P 888    d88P  888 888 Y88b888 ");
mvprintw(7, 10,"888       d88P   888 888    888 888  Y8P  888   d88P   888 888  Y88888 ");
mvprintw(8, 10,"888      d8888888888 Y88b  d88P 888   8   888  d8888888888 888   Y8888 ");
mvprintw(9, 10,"888     d88P     888   Y8888P   888       888 d88P     888 888    Y888 ");
mvprintw(13,20," .-.   .-.    .-.   .--..                       | ");
mvprintw(14,20,"| OO| | OO|  | OO| | _.-' .-.  .-.  .-.   .''.  | ");
mvprintw(15,20,"|   | |   |  |   | |  '-. '-'  '-'  '-'   '..'  | ");
mvprintw(16,20,"'^^^' '^^^'  '^^^' '.__.'                       | ");


mvprintw(35, 15, "Use arrow keys to go up and down, Press enter to select a choice");
mvprintw(20, 25, "|`.'| '' ||`. |  |`.'||--|`. ||  |");
mvprintw(21, 25, "|   ||--|||  `|  |   ||--|  `||__|");
refresh();
//end banner

print_menu(menu_win, highlight);
do
{	input = wgetch(menu_win);
    switch(input)
    {	case KEY_UP:					//key move selector up or back to bottom
            if(highlight == 1)
                highlight = n_choices;
            else
                --highlight;
            break;
        case KEY_DOWN:					//move selector down or back to top
            if(highlight == n_choices)
                highlight = 1;
            else
                ++highlight;
            break;
        case 10: 						//enter button hit
            choice = highlight;
            break;
        default:
            refresh();
            break;
    }
    print_menu(menu_win, highlight);

}while(input != 10);

clrtoeol();
refresh();
delwin(menu_win);
return choice;
}

void print_menu(WINDOW *menu_win, int highlight)
{
    int x, y, i;

    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for(i = 0; i < n_choices; ++i)
    {
    if(highlight == i + 1) 			// High light the present choice
        {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        }
    else
        mvwprintw(menu_win, y, x, "%s", choices[i]);
        ++y;
    }
    wrefresh(menu_win);
}

void startGameMenu()
    {
        clear();
		echo();
		initscr();
        mvprintw(2,3, "START GAME");
        mvprintw(4,3, "1. Single player");
        mvprintw(5,3, "2. Two player");
        mvprintw(6,3, "3. Multi player");
        mvprintw(7,3, "4. Return to main menu");
        char mesg[]="Enter your choice: ";
        char choice;
        mvprintw(10,3, "%s", mesg);
        mvprintw(10,4, "%c",choice);

        choice = getch();
		noecho();
		endwin();

        switch(choice)
        {
            case '1':
            singlePlayerGameController();
            break;

            case '2':
            twoPlayer();
            break;

            case '3':
            multiPlayer();
            break;

            case '4':
            mainMenu();
            break;

            default:
            break;
        }

    }


    void twoPlayer()
    {
        clear();
        //mvprintw(1,3,"Two player");
        // Include code to implement twoPlayer game controller
        mvprintw(3,3, "Press any key to return to Start Game     ");  //Move this statement accordingly
        char str[80];
        getstr(str);
        startGameMenu();

    }

    void multiPlayer()
    {

        clear();
        //mvprintw(1,3," Multiplayer");
        // Include code to implement multiPlayer game controller
        mvprintw(3,3, "Press any key to return to Start Game     ");  //Move this statement accordingly
        char str[80];
        getstr(str);
        startGameMenu();

    }

    void options()
    {
        clear();
        mvprintw(1,3,"OPTIONS:");
        mvprintw(3,3,"1. Load Custom Maps");
        mvprintw(4,3,"2. Difficulty Mode");
        mvprintw(5,3,"3. Clear High Score");
        mvprintw(6,3,"4. Change Controls");
        mvprintw(7,3,"5. Return to main menu");
        char mesg[]="Enter your choice: ";
        char str[80];
        mvprintw(10,3, "%s", mesg);
        getstr(str);
        int numbr = atoi(str);

        switch(numbr)
        {
            case 1:
            loadCustomMap();
            break;

            case 2:
            changeDifficulty();
            break;

            case 3:
            clearHighScore();
            break;

            case 4:
            changeControls();
            break;

            case 5:
            mainMenu();
            break;

            default:
            break;
        }

    }

    void loadCustomMap()
    {
        clear();
        //mvprintw(4,3, "This function will load Custom maps");
        // Include code to implement Load Custom Maps

        mvprintw(8,3, "Press any key to return to Options     ");  //Move this statement accordingly
        char str[80];
        getstr(str);
        options();

    }

    void changeDifficulty()
    {
        clear();
        mvprintw(1,3,"OPTIONS:");
        //mvprintw(3,3,"1. Easy");
        //mvprintw(4,3,"2. Medium");
        //mvprintw(5,3,"3. Hard");
        mvprintw(6,3,"4. Return to Options");    //Include functions for above 3 options
        char mesg[]="Enter your choice: ";
        char str[80];
        mvprintw(9,3, "%s", mesg);
        getstr(str);
        int numbr = atoi(str);

        switch(numbr)
        {
            case 1:
            //easyGameController();
            break;

            case 2:
            //mediumGameController();
            break;

            case 3:
            //hardGameController();
            break;

            case 4:
            options();
            break;

            default:
            break;
        }

    }

    void clearHighScore()
    {
        ;
        clear();
        //mvprintw(4,3, "This function will allow the user to clear highscore");
        // Include code to implement Clear Highscore

        mvprintw(8,3, "Press any key to return to Options     ");  // Move this statement accordingly
        char str[80];
        getstr(str);
        options();

    }

    void changeControls()
    {
        ;
        clear();
        //mvprintw(4,3, "This function will allow the user to change controls");
        // Include code to implement Change Controls

        mvprintw(8,3, "Press any key to return to Options     ");   // Move this statement accordingly
        char str[80];
        getstr(str);
        options();

    }

    void aboutTheGame()
    {
        ;
        clear();
        mvprintw(1,3,"ABOUT THE GAME:");
        mvprintw(3,3,"1. How To Play");
        mvprintw(4,3,"2. Demo Game");
        mvprintw(5,3,"3. High Score");
        mvprintw(6,3,"4. Return to Main Menu");
        char mesg[]="Enter your choice:     ";
        char str[80];
        mvprintw(8,3, "%s", mesg);
        getstr(str);
        int numbr = atoi(str);

        switch(numbr)
        {
            case 1:
            howToPlay();
            break;

            case 2:
            demoGame();
            break;

            case 3:
            highScore();
            break;

            case 4:
            mainMenu();
            break;

            defaut:
            break;
        }

    }

    void demoGame()
    {
        ;
        clear();
        //mvprintw(4,3, "Demo Game");
        // Include code to implement Demo Game

        mvprintw(8,3, "Press any key to return to About The Game     ");        // Move this statement accordingly
        char str[80];
        getstr(str);
        aboutTheGame();

    }

    void howToPlay()
    {
        ;
        clear();
        mvprintw(3,2, "ABOUT THE GAME:");
        mvprintw(6,2, "W - Move up     S - Move down");
        mvprintw(7,2, "A - Move left   D - Move right");        // Single player keys
        //mvprintw(9,2, "  - Move up       - Move down");
        //mvprintw(10,2, "  - Move left      - Move right");    //Two player keys
        mvprintw(9,2, "--> Eat the default fruits '-' by using four keys.");
        mvprintw(11,2, "--> Eat the special fruits '&' to gain 10 points as well as weaken the monters.");
        mvprintw(13,2, "--> Weakened monsters can be eaten. Eating one monster will fetch you 100 points.");
        mvprintw(15,2, "--> When the monsters come closer, try to move away from them.");
        mvprintw(16,2, "--> If unweakened monsters eat you, then you will lose the game.");
        mvprintw(18,2, "--> Eat all the dots to get to next level.");
        mvprintw(21,2, "Have fun playing!");

        mvprintw(24,2, "Press any key to return to About The Game     ");
        char str[80];
        getstr(str);
        aboutTheGame();

    }

    void highScore()
    {
        clear();
        //mvprintw(4,3, "High Score");
        // Include code to implement view highscore

        mvprintw(8,3, "Press any key to return to About The Game     ");    // Move this statement accordingly
        char str[80];
        getstr(str);
        aboutTheGame();

    }

    void quitPrompt()
    {
        clear();
        mvprintw(4, 3, "Are you sure you want to quit?");
        mvprintw(8, 3, "Press 1 to quit   ");
        mvprintw(9, 3, "Press 2 to go back to main menu   ");

        //char str[80];
        //getstr(str);
         int numbr;
        //noecho();
        numbr = getch();
        do
        {
            if (numbr == 49)
            {
            //system("pause");
            exit(0);
            break;
            }
            else if (numbr == 50)
            {
            mainMenu();
            break;
            }
            else
            {
            mvprintw(11, 3, "Press enter a valid input   ");
            numbr = getch();
            }
        }
        while(1);
        clear();
        endwin();

    }
