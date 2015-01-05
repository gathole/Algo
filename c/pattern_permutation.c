#include<stdio.h>
#define MAX 256

int checkPerm(int t[], int p[]){
    int i;
    for(i=0; i<MAX; i++){
        if(t[i] != p[i]){
            return 0;
        }
    }
    return 1;
}

int findAllPerm(char txt[], char ptn[], int tl, int pl){
    int TL[MAX] = {0}, PL[MAX]= {0}, i=0, j=0;
    for(i=0; i<pl; i++){
        TL[txt[i]] += 1;
        PL[ptn[i]] += 1;
    }
    int s=0;
    printf("INDEXES: ");

    for(j=i; j<tl; j++){
        if(checkPerm(TL, PL)){
            printf("%d  ", j-i);
        }
        s+=checkPerm(TL, PL);
        TL[txt[j]] += 1;
        TL[txt[j-i]] -= 1;
    }
    if(checkPerm(TL, PL)){
        printf("%d  ", j-i);
    }
    s+=checkPerm(TL, PL);
    return s;
}



void main(){
    char txt[] = {'B', 'A', 'C', 'D', 'G','A','B','C','D','A'};
    char ptn[] = {'A','B','C','D'};
    int tl, pl, s=0;
    printf("%s\n", txt);
    printf("%s\n", ptn);
    tl = (int)sizeof(txt)/sizeof(txt[0]);
    pl = (int)sizeof(ptn)/sizeof(ptn[0]);

    printf("TL: %d  PL: %d\n", tl, pl);
    s = findAllPerm(txt, ptn, tl, pl);
    printf("\nTotal: %d\n", s);

}
