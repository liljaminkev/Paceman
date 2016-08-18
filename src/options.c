#include <conio.h>
//#include <iostream>
#include<stdio.h>
#include <fcntl.h>

void ClearHighScore( )
{
FILE *fd;
fd = fopen("highscore.txt", "w+");
fprintf(fd,"0");
fclose(fd);

}
