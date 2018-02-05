#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char s[20];
    scanf("%d",&t);
    while(t--)
    {
       int r;
       scanf("%d",&r);    
       r=315*r+36962;
       sprintf(s,"%d",r);
       printf("%c\n",s[strlen(s)-2]);
    }
    return 0;
}
