#include<stdio.h>

int main()

FILE *SaveGame;
char file[] = "Save.txt";
Save= fopen(file,"wb")
if (SaveGame == NULL)
{
 printf("\n Nothing to be Saved");

}

const char Work ="SD";
fwrite (Work, sizeof(Work),SaveGame);

const int PacMen =1;
const int monsters= 4;

typedef struct PacMan // save function for the players/pacmens

{
    int lives;
    int x_position;
    int y_position;
    int x_direction;
    int y_direction;
    int x_start;
    int y_start;
    int score;
    char sprite;
    int quit;

    } sPlayer;


    typedef struct Monsters// for the monsters save function
    {
    int mon;
    int start_positionX;
    int start_positionY;
    int x_position;
    int y_position;
    int x_direction;
    int y_direction;
    int state;
    int alive;
    int speed;
    char sprite;

    } sFighter;
 typedef struct  gameBoardInitialize(GameBoard *a)
{
    //used to zero out a game board instance
     a->wall = '3';
     a->fruit[0] = '-';
     a->fruit[1] = '*';
     a->fruit[2] = '&';
     a->fruit[3] = '$';
     a->numFruit1 = 0; //number of first fruit on level
     a->numFruit2 = 0; //number of second
     a->numFruit3 = 0; //number of thrid
     a->numFruit4 = 0; //number of fourth
     a->numPacman = 0;    //number of pacman
     a->numMonster = 0;    //number of monsters
     a->pause_state = 0;
     a->run_state = 1;
}
 typedef struct draw_borders(WINDOW *screen) {
  int x;
  int y;
  int i;
  getmaxyx(screen, y, x);

  // 4 corners
  mvwprintw(screen, 0, 0, "X");
  mvwprintw(screen, y - 1, 0, "X");
  mvwprintw(screen, 0, x - 1, "X");
  mvwprintw(screen, y - 1, x - 1, "X");

 sFighter Monsters [monsters];
 sPlayer PacMen [pacmen];

 fwrite (&PacMen, sizeof(int), 1, SaveGame);
 fwrite (&Monsters, sizeof(int), 1, SaveGame);
 fwrite (PacMen, sizeof (sPlayer), pacmen, SaveGame);
fwrite (Monsters, sizeof (sFighter), monsters, SaveGame);

fclose(SaveGame);
return 0;
}
