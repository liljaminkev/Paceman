#include <ncurses.h>
#include <unistd.h>

#define DELAY 50000

void getDirection(int *x, int *y)
{
  int c;
  c = getch();
  switch(c)
  {
    case 'a':
     *x = -1;
     *y = 0;
     break;

    case 'd':
    *x = 1;
    *y = 0;
    break;

    case 's':
    *x = 0;
    *y = 1;
    break;

    case 'w':
    *x = 0;
    *y = -1;
    break;

    default:
    break;
    }
}

char pacManOrientation(int dirX, int dirY)
{
  char orientation = '@';

  if (dirX == 1)
  orientation = '<';
  if (dirX==-1)
  orientation = '>';
  if (dirY==-1)
  orientation = 'V';
  if (dirY==1)
  orientation = '^';
  return orientation;
}

int main(int argc, char *argv[]) {
  //---------------------
  // Variables
  //--------------------
 int x = 0, y = 0;
 int max_y = 20, max_x = 26;
 int next_x = 0;
 int next_y = 0;
 int direction_x = 1;
 int direction_y = 0;
 char PacManSprite = '<';

//initilize screen
 initscr();
 noecho();
 curs_set(FALSE);

 //getmaxyx(stdscr, max_y, max_x);

 nodelay(stdscr, TRUE);

//main body of game
 while(1) {
 clear();

 PacManSprite = pacManOrientation(direction_x, direction_y);

 mvprintw(y, x, "%c", PacManSprite);

 refresh();

 usleep(DELAY);

 if (direction_y == -1 || direction_y == 1)
 usleep(DELAY);

 next_x = x + direction_x;

 next_y = y + direction_y;

 getDirection(&direction_x, &direction_y);


 if (next_x >= max_x || next_x < 0) {
 direction_x *= -1;
 } else {
 x+= direction_x;
 }

 if (next_y >= max_y || next_y < 0) {
 direction_y *= -1;
 } else {
 y+= direction_y;
 }
 }

 endwin();
}
