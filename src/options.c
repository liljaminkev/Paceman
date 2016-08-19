#include <conio.h>
//#include <iostream> not needed
#include<stdio.h>
#include <fcntl.h>

void ClearHighScore( )//should work now/
{
FILE *fd; // pointer
fd = fopen("highscore.txt", "w+");
fprintf(fd,"0");
fclose(fd);

}
