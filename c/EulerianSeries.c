#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, A[26];
    A[0] = 1;
    char C[10];
    for(i=1;i<26;i++)
    {
        A[i]=A[i-1]*2+i+1;
    }
    for(i=0;i<26;i++)
    {
        printf("%d -> %d\n", i, A[i]);
    }
    scanf("%[^\n]%*c", C);
    printf("%s\n", C);
    int s=0, m;
    i=0;
    while(C[i])
    {
        m = C[i] >= 97? C[i]-97:C[i]-65;
        printf("%c -> %d\n", C[i], A[m]);
        i++;
        s+=A[m];
    }
    printf("SUM:%d\n",s);

    return 0;
}
