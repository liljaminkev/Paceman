#include "pacman.h"

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
}

void movePacman(PacMan *player)
{
  int next_x, next_y;

  next_x = player->x_position + player->x_direction;
  next_y = player->y_position + player->y_direction;


  if (next_x > max_x || next_x < 0)
      player->x_direction = 0;

  player->x_position += player->x_direction;


  if (next_y > max_y || next_y < 0)
      player->y_direction = 0;

  player->y_position += player->y_direction;
}

char getPacmanDirection1(PacMan *a, int keyInput)
{
  if (keyInput == player1_left)
  {
    a->x_position = -1;
    a->y_position = 0;
    return '>';
  }

  else if (keyInput == player1_right)
  {
    a->x_position = 1;
    a->y_position = 0;
    return '<';
  }

  else if (keyInput == player1_down)
  {
    a->x_position = 0;
    a->y_position = 1;
    return '^';
  }

  else if (keyInput == player1_up)
  {
    a->x_position = 0;
    a->y_position = -1;
    return 'V';
  }

  else
  return a->sprite;
}

char getPacmanDirection2(PacMan *a,int keyInput)
{
  if (keyInput == player2_left)
  {
    a->x_position = -1;
    a->y_position = 0;
    return '>';
  }

  else if (keyInput == player2_right)
  {
    a->x_position = 1;
    a->y_position = 0;
    return '<';
  }

  else if (keyInput == player2_down)
  {
    a->x_position = 0;
    a->y_position = 1;
    return '^';
  }

  else if (keyInput == player2_up)
  {
    a->x_position = 0;
    a->y_position = -1;
    return 'V';
  }

  else
  return a->sprite;
}
