#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
    int c,f=1;
    while((c=getchar())!=EOF)
    {
        if(c=='\"')
        {                     
           if(!f){printf("\'\'");f=1;}
           else {printf("``");f=0;}
        }
        else putchar(c);
    }
    return 0;
}
