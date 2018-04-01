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


void pat_input()
{
    char tmp[100];

    int n=1;
    int i=0;
    scanf("%d",&n);
    if(n>10)
        n=10;
    char result[1000];

    while(1)
    {
        if(i>=n)
            break;
        scanf("%s",&tmp);
        char res[3];
        pat(tmp,res);
        if(memcmp(res,"NO",2)==0)
        {
            char ttmp[100];
            patChange(tmp,ttmp);
            pat(ttmp,res);
        }

        strcat(result,res);
        strcat(result,"\n");
        i++;
    }
    printf(result);
}

void pat(char *content,char*res)
{
    int len= strlen((content));
    int numOfP=0;
    int numOfT=0;
    for(int i=0;i<len;++i)
    {
        if(content[i]!='A'&&content[i]!='P'&&content[i]!='T')
        {
            strcpy(res,"NO");
            return;
        }
        if(content[i]=='P')
        {
            numOfP++;
            if(i>len-3)
            {
                strcpy(res,"NO");
                return;
            }
            if(content[i+1]!='A')
            {
                strcpy(res,"NO");
                return;
            }
            if(content[i+2]!='T')
            {
                strcpy(res,"NO");
                return;
            }
        }
        if(content[i]=='T')
        {
            numOfT++;
        }
    }
    if(numOfP>1)
    {
        strcpy(res,"NO");
        return;
    }
    if(numOfT>1)
    {
        strcpy(res,"NO");
        return;
    }
    strcpy(res,"YES");
    return;
}

void patChange(char *old, char *change)
{
    int len =strlen(old);
    int index_p = 0;
    int index_t = 0;
    int j=0;
    for(int i=0;i<len;++i)
    {
        if(old[i]=='P')
        {
            index_p = i;
        }
        if(old[i]=='T')
            index_t = i;
        if(i<(len-1)&&old[i+1]=='T'&&old[i]=='A')
        {
            continue;
        }
        if(i>(len-index_p-1))
            continue;
        change[j]=old[i];
        ++j;
    }
}

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
    gets_s(input_n,sizeof(input_n));
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
        gets_s(tmp,30);
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
