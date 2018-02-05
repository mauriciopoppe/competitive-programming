#include<stdio.h>
#include<string.h>
int main()
{
    char w[500];
    int cas = 1;
    while(gets(w) && w[0] != '#')
    {
        printf("Case %d: ", cas++);
        if(!strcmp(w, "HELLO"))
           puts("ENGLISH");
        else if(!strcmp(w, "HOLA"))
           puts("SPANISH");
        else if(!strcmp(w, "HALLO"))
           puts("GERMAN");
        else if(!strcmp(w, "BONJOUR"))
           puts("FRENCH");
        else if(!strcmp(w, "CIAO"))
           puts("ITALIAN");
        else if(!strcmp(w, "ZDRAVSTVUJTE"))
           puts("RUSSIAN");
        else 
           puts("UNKNOWN");
    }
    return 0;
}
