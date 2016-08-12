#ifndef MONSTER_H
#define MONSTER_H
typedef struct Monster
{
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
} Monster;

void monsterInitialize(Monster*);
void monsterRespawn(Monster [], int);
#endif
