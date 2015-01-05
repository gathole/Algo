#include<stdio.h>
#include<string.h>

int isPalindrome(char *s){
    int slen=strlen(s), i=0;
    printf("%d\n", slen);
    while(i<slen){
        if(s[i]!=s[slen-1]){
            return 0;
        }
        i++;
        slen--;
    }
    return 1;
}

int rotPalindrome(char *s){
    int slen=strlen(s), i=0;
    char new[] = strcat();
    for(i=0; i< slen; i++)

void main(){
    char s[] = "cabcbac";
    int res=0;
    res = isPalindrome(s);
    printf("%s\n", s);
    printf("RESULT: %d\n", res);
}
