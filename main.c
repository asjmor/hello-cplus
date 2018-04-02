//#include "patest.h"
#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[10];
    char no[10];
    double score;
}Student;
void input_1004()
{
    char tmp[30];

    int n=1;
    int i=0;
    char input_n[10];
    gets(input_n);
    n= atoi(input_n);
    if(n>10)
        n=10;

    Student stMax;
    stMax.score=0;
    Student stMin;
    stMin.score=100;
    Student stTmp;

    while(1)
    {
        if(i>=n)
            break;
        gets(tmp);
        char*p=strtok(tmp," ");
        int j=0;
        while (p!=NULL) {
            if(j==0)
                strncpy(stTmp.name,p,10);
            if(j==1)
                strncpy(stTmp.no,p,10);
            if(j==2)
                stTmp.score = atoi(p);

            p=strtok(NULL," ");
            ++j;
        }
        if(stMax.no=="")
            stMax = stTmp;
        if(stMin.no=="")
            stMin = stTmp;
        if(stTmp.score>stMax.score)
            stMax=stTmp;
        if(stTmp.score<stMin.score)
            stMin = stTmp;

        ++i;
    }
    printf("%s %s\n",stMax.name,stMax.no);
    printf("%s %s\n",stMin.name,stMin.no);
}

int main(int argc, char *argv[])
{
    input_1004();
    return 0;
}

