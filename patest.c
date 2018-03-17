#include "patest.h"
#include <stdio.h>

static int c=0;
int scale(int n){
    if(c>1000)
        return -1;
    if(n==1)
        return c;
    ++c;

    if((n%2)==0)
        n=n/2;
    else
        n=(3*n+1)/2;
    return scale(n);

}

void scale_input()
{
    int n=0;
    scanf("%d",&n);
    printf("%d\n",scale(n));
}

/*
int main(int argc, char *argv[])
{
    scale_input();
    return 0;
}
*/
