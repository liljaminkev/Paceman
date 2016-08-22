#include<stdio.h>
#include <conio.h>

void main()
{
    int s;
    clrscr();
    printf("Sound - PacMen");
    for (i=o; i<120; i++)
    {
        sound(250 * i);
        delay(250);
        nosound();
    }
    getch();
}
