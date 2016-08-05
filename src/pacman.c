#include "../header/pacman.h"

void pacmanInitialize(PacMan a)
{
  a.lives = 1;
  a.x_pos = 0;
  a.y_pos = 0;
  a.x_direction = 1;
  a.y_direction = 0;
  a.y_start = 0;
}

void MovePacman(PacMan *a)
{
  int next_x, next_y;

  next_x = player1.x_position + player1.x_direction;
  next_y = player1.y_position + player1.y_direction;


  if (next_x > max_x || next_x < 0)
      player1.x_direction = 0;

  player1.x_position += player1.x_direction;


  if (next_y > max_y || next_y < 0)
      player1.y_direction = 0;

  player1.y_position += player1.y_direction;
}

char pacManOrientation(int *dirX, int *dirY)
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


int getPacmanDirection1(int *x, int *y, int a)
{
  if (a == left)
  {
    *x = -1;
    *y = 0;
    return 1;
  }

  else if (a == right)
  {
    *x = 1;
    *y = 0;
    return 2;
  }

  else if (a == down)
  {
    *x = 0;
    *y = 1;
    return 3;
  }

  else if (a == up)
  {
    *x = 0;
    *y = -1;
    return 4;
  }

  else
  return a;
}

int getPacmanDirection2(int *x, int *y, int d)
{
  if (d == 'k')
  {
    *x = -1;
    *y = 0;
    return 1;
  }

  else if (d == ';')
  {
    *x = 1;
    *y = 0;
    return 2;
  }

  else if (d == 'l')
  {
    *x = 0;
    *y = 1;
    return 3;
  }

  else if (d == 'o')
  {
    *x = 0;
    *y = -1;
    return 4;
  }

  else
  return d;
}
