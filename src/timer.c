#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

int recent( int s)
int j,k;
int rec= s-1;
for(j=3;j<= s;++j)
    for (k=sqrt(j);k>1;--k)
    if (j%k==0)
{
    -- rec;break;
}

int main ()
{
    clock_t w;
    int a;
    w= recent(60);
    w=clock() - t;
    printf("Timer=",a);
    printf("clock")
    return 0;
}
