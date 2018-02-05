#include<stdio.h>
#include<stdlib.h>

int main()
{
    int cas;
    int n, t, i;
    int x1, y1, x2, y2;
    scanf("%d", &cas);
    
    while(cas--)
    {
        scanf("%d%d", &t, &n);
        for(i = 0; i < t; ++i)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if(x1 == x2 && y1 == y2)
            {
                puts("0");
                continue;
            }

            int a = abs(x1 - x2);
            int b = abs(y1 - y2);
            if(a == b)
               puts("1");
            else
            {
                if((a & 1) == (b & 1)) 
                   puts("2");
                else
                   puts("no move");
            }
        }
    }
    return 0;
}
