#include<stdio.h>
int main()
{
    int cas;
    int k, i, j;
    int pos;
    while(scanf("%d",&cas) && cas)
    {
        for(j = 0; j < cas; ++j)
        {                   
            int black = 0, white = 0;
            for(i = 0; i < 5; ++i)
            {
                scanf("%d",&k);
                if(k > 127)
                   white++;
                else
                   black++, pos = i;              
            }              
            if(black == 1 && white == 4)
               printf("%c\n", pos + 'A');
            else 
               printf("*\n");     
        }
    }
    return 0;
}
