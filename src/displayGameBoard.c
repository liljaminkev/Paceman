#include "stdio.h"         
#include "stdlib.h" 


int main (int argc, char *argv[])
{
    FILE* fp = NULL;   
    char c;                   
    int i,j;
    int numF1=0;
    int numF2=0;
    int numF3=0;
    int numF4=0;          
    char grid[20][27];
    int pxstart,pystart=0;
    int mxstart,mystart=0;

    fp = fopen("stage1.txt", "r"); 

    if (!fp)                       
        exit(1);   

    for ( i = 0; i < 20; i++ )
    { for (j=0; j<27; j++) 
	{
        c = getc(fp); 
	grid[i][j]=c;
		if(c=='-')
		     numF1++;

		if(c=='&')
		     numF2++;

		if(c=='$')
		     numF3++;

		if(c=='*')
		     numF4++;
     	
		if(c=='<')
		{ pxstart=i;
		  pystart=j;}

		if(c=='M')
		{ mxstart=i;
		  mystart=j; }
 
        printf("%c", grid[i][j]);          
    }}

    printf("\nFruit1:%d\n",numF1);
    printf("Fruit2:%d\n",numF2);
    printf("Fruit3:%d\n",numF3);
    printf("Fruit4:%d\n",numF4);
    printf("Pacman x pos: %d\n",pxstart);
    printf("Pacman y pos: %d\n",pystart);
    printf("Monster x pos: %d\n",mxstart);
    printf("Monster y pos: %d\n",mystart);

    fclose(fp);
     
    return 0;
}
