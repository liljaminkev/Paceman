#include <conio.h>
//#include <iostream>
#include<stdio.h>


int main( int argc, char *argv[])
{   int num;
 num=0;
    FILE *High;
    //open file
    High= fopen("highscore.txt","r");
    fscanf (High,"%d", &num);
    printf("%d",num);
     return ;
}
