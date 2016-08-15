#include "../header/front.h"


//function to draw boarder around windows
void draw_borders(WINDOW *screen) {
  int x, y, i;
  getmaxyx(screen, y, x);

  // 4 corners
  mvwprintw(screen, 0, 0, "X");
  mvwprintw(screen, y - 1, 0, "X");
  mvwprintw(screen, 0, x - 1, "X");
  mvwprintw(screen, y - 1, x - 1, "X");

  // sides
  for (i = 1; i < (y - 1); i++) {
    mvwprintw(screen, i, 0, "X");
    mvwprintw(screen, i, x - 1, "X");
  }

  // top and bottom
  for (i = 1; i < (x - 1); i++) {
    mvwprintw(screen, 0, i, "X");
    mvwprintw(screen, y - 1, i, "X");
  }
}

void displayBoard(GameBoard *gameboard, WINDOW *levelBuffer)
{
  int i,j;
  char character;

  for ( i = 0; i < 20; i++)
  {
      for (j = 0; j< 26; j++)
      {
          if(gameboard->map[i][j] > 0 )
          {
              character = gameboard->map[i][j];
              mvwprintw(levelBuffer, i+1, j+1, "%c", character);
          }

    }
  }
}

void displayMonsters(Monster mon, int numMonsters, WINDOW *gameArea)
{
    mvwprintw(gameArea, mon.y_position+1, mon.x_position+1, "%c", mon.sprite);
}


//display fruit array to user
void displayFruit(Fruit fruit[][26], WINDOW *levelBuffer)
{
    int i,j;
    char character;

    for ( i = 0; i <20; i++ )
    {
        for (j = 0; j<26; j++)
        {
            if (fruit[i][j] != 0)
            {
                character = fruit[i][j];
                mvwprintw(levelBuffer, i+1, j+1, "%c", character);
            }
      }
    }

}


void displayPacman(PacMan *player, WINDOW *levelBuffer)
{
    mvwprintw(levelBuffer, player->y_position+1, player->x_position+1, "%c", player->sprite);
}
