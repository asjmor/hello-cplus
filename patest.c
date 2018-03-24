#include "patest.h"
#include <string.h>
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
//---------------------
void sumN_input()
{
    char s[110];
    memset(s,0x00,sizeof(s));
    scanf("%s",&s);
    pinyin_output(sumN(s));
}

int sumN(char *s)
{
    int len=strlen(s);
    int i=0;
    int sum=0;
    while(i<len)
    {
        sum+=s[i]-'0';
        ++i;
    }
    return sum;
}

void pinyin_output(int sum)
{
    char strsum[10];
    memset(strsum,0x00,sizeof(strsum));
    sprintf(strsum,"%d",sum);
    int len=strlen(strsum);
    int i=0;
    while(i<len)
    {
        switch(strsum[i]-'0')
        {
        case 1:
            printf("yi");
            break;
        case 2:
            printf("er");
            break;
        case 3:
            printf("san");
            break;
        case 4:
            printf("si");
            break;
        case 5:
            printf("wu");
            break;
        case 6:
            printf("liu");
            break;
        case 7:
            printf("qi");
            break;
        case 8:
            printf("ba");
            break;
        case 9:
            printf("jiu");
            break;
        case 0:
            printf("ling");
            break;
        default:
            break;
        }
        if(i!=len-1)
            printf(" ");

        ++i;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    sumN_input();
    return 0;
}
