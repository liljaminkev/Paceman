#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "../header/menu.h"

int main ()
{
    int choice = 0;
	getName();

do{
	choice = mainMenu();

	switch(choice)
	{
		case 1:
		//gameController();
		break;

		case 2:
		//options();
		break;

		case 3:
		//aboutTheGame();
		break;

		case 4: //set screen back to defualt and exit game
		choice = 0;
		break;

		default:
		break;
	}

}while(choice != 0);

    return 0;
}
