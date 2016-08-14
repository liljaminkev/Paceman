#include "../header/back.h"
#include <ncurses.h>


//---------------------------------
//             Monsters
//---------------------------------

void moveMonster(Monster *mon)
{
    mon[0].y_position = mon[0].y_position-1;
    mon[0].x_position = mon[0].x_position;
}

void displayMonsters(Monster mon, int numMonsters, WINDOW *gameArea)
{
    mvwprintw(gameArea, mon.y_position+1, mon.x_position+1, "%c", mon.sprite);
}

void monsterRespawn(Monster *mon, int numMonsters)
{
    for(int i = 0; i < numMonsters; i++)
    {
        if (mon[i].alive == 0)
        {
            mon[i].x_position = mon[i].start_positionX;
            mon[i].y_position = mon[i].start_positionY;
            mon[i].sprite = 'M';
            mon[i].alive = 1;
        }
    }
}


//---------------------------------
//             fruit
//----------------------------------
//fruit characters
char fruit[] = {'.', '-', 'o', 'O' } ;

//for customizing fruit types
void setFruit(char input, int index)
{
    fruit[index] = input;
}

void initFruit(Fruit arr[][26])
{
    int ii, jj;

    for ( ii = 0; ii <20; ii++ )
    {
        for (jj = 0; jj<26; jj++)
        {
            arr[ii][jj] = 0;
      }
    }
}

//assign pt value to fruit being eaten and add to score
void eatFruit(PacMan *p1, Fruit f1[][26])
{
    if(f1[p1->y_position][p1->x_position] > 0)
    {
        if(f1[p1->y_position][p1->x_position] == fruit[0])
        {
            p1->score += 1;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit[1])
        {
            p1->score += 10;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit[2])
        {
            p1->score += 100;
            f1[p1->y_position][p1->x_position] = 0;
        }
        else if(f1[p1->y_position][p1->x_position] == fruit[3])
        {
            p1->score += 100;
            f1[p1->y_position][p1->x_position] = 0;
        }

    }
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

//----------------------------
//          Pacman
//----------------------------

//--------------Globals-------------------
const int MAX_Y = 17;
const int MAX_X = 26;
const int MIN_Y = 0;
const int MIN_X = 0;


//player 1 controls
int player1_up = 'w';
int player1_down = 's';
int player1_left = 'a';
int player1_right = 'd';

//player 2 controls
char player2_up = 'o';
char player2_down = 'l';
char player2_left = 'k';
char player2_right = ';';

void displayPacman(PacMan *player, WINDOW *levelBuffer)
{
    mvwprintw(levelBuffer, player->y_position+1, player->x_position+1, "%c", player->sprite);
}

void pacmanInitialize(PacMan *a)
{
    a->lives = 1;
    a->x_position = 0;
    a->y_position = 0;
    a->x_direction = 1;
    a->y_direction = 0;
    a->y_start = 0;
    a->x_start = 0;
    a->sprite = '<';
    a->score = 0;
    a->quit = 1;
}

void movePacman(PacMan *player, GameBoard *gb)
{
  int next_x, next_y;

  next_x = player->x_position + player->x_direction;
  next_y = player->y_position + player->y_direction;

  if (next_x > MAX_X)
  player->x_position = MIN_X;
  else if (next_x < MIN_X)
  player->x_position = MAX_X;
  else if (next_x == gb->wall)
  player->x_direction = 0;

  player->x_position += player->x_direction;


  if (next_y > MAX_Y)
  player->y_position = MIN_Y;
  else if (next_y < MIN_Y)
  player->y_position = MAX_Y;
  else if (next_y == gb->wall)
  player->y_position = 0;

  player->y_position += player->y_direction;
}

void getPacmanDirection1(int *x_dir, int *y_dir, int input, char *sprite)
{
  if (input == player1_left)
  {
    *x_dir = -1;
    *y_dir = 0;
    *sprite = '>';
  }

  else if (input == player1_right)
  {
    *x_dir = 1;
    *y_dir = 0;
    *sprite = '<';
  }

  else if (input == player1_down)
  {
    *x_dir = 0;
    *y_dir = 1;
    *sprite = '^';
  }

  else if (input == player1_up)
  {
    *x_dir = 0;
    *y_dir = -1;
    *sprite = 'V';
  }

}

void getPacmanDirection2(int *x_dir, int *y_dir, int keyInput, char *sprite)
{
  if (keyInput == player2_left)
  {
    *x_dir = -1;
    *y_dir = 0;
    *sprite = '>';
  }

  else if (keyInput == player2_right)
  {
    *x_dir = 1;
    *y_dir = 0;
    *sprite = '<';
  }

  else if (keyInput == player2_down)
  {
    *x_dir = 0;
    *y_dir = 1;
    *sprite = '^';
  }

  else if (keyInput == player2_up)
  {
    *x_dir = 0;
    *y_dir = -1;
    *sprite = 'V';
  }

}
