#include<stdio.h>
#include<stdlib.h>
#define MAX 256

int checkPerm(int t[], int p[]){
    int i,s=0;

    for(i=0; i<MAX; i++){
        if(t[i] != p[i]){
            return 0;
        }
    }    
    return 1;
}

int checkSum(char txt[], char ptn[], int tl, int pl)
{
    int st=0, sp=0, k=0;
    for(k=0; k<pl;k++)
    {
        st+= txt[tl+k] * k;
        sp+=ptn[k] * k;
    }
    return sp==st;
}

int findAllPerm(char txt[], char ptn[], int tl, int pl){
    //printf("----------------------\n");
    //printf("%s\n", txt);
    //printf("%s\n", ptn);
    //printf("----------------------\n");
    int TL[MAX] = {0}, PL[MAX]= {0}, i=0, j=0, k=0, ttt=0;
    for(i=0; i<pl; i++){
        TL[txt[i]] += 1;
        PL[ptn[i]] += 1;
    }
    int s=0;
    printf("INDEXES: ");

    for(j=i; j<tl; j++){
        if(checkPerm(TL, PL)){
            ttt = checkSum(txt,ptn, j-i,pl);
            if(ttt)
            {
                printf("%d  ", j-i);
                s+=1;
            }
        }
        TL[txt[j]] += 1;
        TL[txt[j-i]] -= 1;
    }
    printf("\n");
    
    if(checkPerm(TL, PL)){
        ttt = checkSum(txt,ptn, j-i,pl);
        if(ttt)
        {
            printf("%d  ", j-i);
            s+=1;
        }
    }
    return s;
}

int getSize(char A[])
{
    int i=0;
    while(A[i])
        i++;
    return i;
}

void main(){
    char txt[] = {'B', 'A', 'C', 'D', 'G','A','B','C','D','A'}, txt1[500];
    char ptn[] = {'A','B','C','D'};
    char inp[5][100];
    int tl, pl, s=0;
    
    /*printf("%s\n", txt);
    printf("%s\n", ptn);
    tl = getSize(txt);
    pl = getSize(ptn);

    printf("TL: %d  PL: %d\n", tl, pl);
    s = findAllPerm(txt, ptn, tl, pl);
    printf("\nTotal: %d\n\n\n", s);
    printf("Will enter no. of patterns: \n");*/

    int c=0,i,j=0, k=0, l=0;
    
    scanf(" %d", &c);
    //printf("%d\n", c);
    
    scanf(" %[^\n]", txt1);

    for(i=0;i<c;i++)   
        scanf(" %[^\n]", inp[i]);
        
    printf("+++++++++++++++\n");

    for(i=0;i<c;i++)
    {
        j=0;
        k=0;

        char C[100]={0};
        while(inp[i][j])
        {

            switch(inp[i][j])
            {
                
                case '.':
                    C[k] = C[k-1];
                    k++;
                    j++;
                    break;
                case '+':
                    for(l=0; l<3;l++)
                    {
                        C[k] = C[k-1];
                        k++;
                    }
                    j++;
                    break;
                case '*':
                    for(l=0; l<4;l++)
                    {
                        C[k] = C[k-1];
                        k++;
                    }
                    j++;
                    break;
                default: 
                    C[k] = inp[i][j];
                    j++;
                    k++;
            }
        
        }
        tl = getSize(txt1);
        pl = getSize(C);
        printf("----------------------\n");
        printf("TL: %d  PL: %d\n", tl, pl);
        s = findAllPerm(txt1, C, tl, pl);
        printf("TOTAL: %d\n", s);

    }
}
