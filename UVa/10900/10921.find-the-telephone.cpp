#include<stdio.h>
#include<ctype.h>
int main()
{
    char c;
    int v[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    
    while((c=getchar())!=EOF)
    {
        if(isupper(c))putchar(v[c-'A']+'0');
        else putchar(c);                     
    }
    return 0;
}
