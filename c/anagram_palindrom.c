#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

int compare(char p[], char t[])
{
    int i;
    
    for(i=0; i<MAX; i++)
    {
        if(p[i] != t[i])
        {
            return 0;
        }
    }
    return 1;
}

void search(char p[], char t[])
{
    int pl, tl, i;
    char plc[MAX] ={0}, tlc[MAX]={0};

    pl = strlen(p);
    tl = strlen(t);
    printf("%s\n", p);
    printf("%s\n", t);
    printf("%d, %d\n", pl, tl);
    for(i=0; i<pl;i++)
    {
        plc[p[i]]++;
        tlc[t[i]]++;
    }
    for(i=pl; i<tl ; i++)
    {
        if(compare(plc, tlc))
        {
            printf("%d\n", i-pl);
        }
        tlc[t[i]]++;
        tlc[t[i-pl]]--;
    }
    if(compare(plc, tlc))
    {
        printf("%d\n", tl-pl);
    }
}


void main()
{
    char p[] = "ABC", t[]="AABBCABCBAAAACCBA";
    search(p,t);

}


