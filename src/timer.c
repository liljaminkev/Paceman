#include <stdio.h>

void timer()

{
    int count;
    count=10;

    while(count != 0)
    {
        printf("\n\t%d", count);
        count--;
        sleep(1);
    }
    //printf(" \n Time is UP \n");
}