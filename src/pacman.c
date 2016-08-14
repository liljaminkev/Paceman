#include "../header/pacman.h"
int MAX_Y = 17;
int MAX_X = 26;
int MIN_Y = 0;
int MIN_X = 0;


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
