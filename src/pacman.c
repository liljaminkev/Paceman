#include "../header/singlePlayerGameController.h"
#include "../header/pacman.h"
#include <ncurses.h>
#include <unistd.h>

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


void pacmanInitialize(PacMan *a)
{
    a->lives = 1;
    a->x_position = 0;
    a->y_position = 0;
    a->x_direction = 0;
    a->y_direction = 0;
    a->y_start = 0;
    a->x_start = 0;
    a->sprite = '<';
    a->score = 0;
    a->quit = 1;
}

void movePacman(PacMan *player)
{
  int next_x, next_y;

  next_x = player->x_position + player->x_direction;
  next_y = player->y_position + player->y_direction;

  if (next_x > max_x)
  player->x_position = 0;

  else if ( next_x < 0)
  player->x_position = max_x;

  player->x_position += player->x_direction;


  if (next_y > max_y)
  player->y_position = 0;
  else if (next_y < 0)
  player->y_position = max_y;

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