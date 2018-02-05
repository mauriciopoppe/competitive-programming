#include<stdio.h>
#include<string.h>
#define min(a, b) ((a) < (b) ? a : b)
#define M 105
#define MM 100005
int green[M], blue[M];
int green_alive, blue_alive;
int g[MM], b[MM];

int solve(int k)
{
    int s = -1, i;    
    for(i = 101; i > 0 && s < k - 1; --i)
       while(green[i] && s < k - 1)
          g[++s] = i, --green[i];
    
    s = -1;    
    for(i = 101; i > 0 && s < k - 1; --i)
       while(blue[i] && s < k - 1)
          b[++s] = i, --blue[i];
        
    green_alive -= k;
    blue_alive -= k;
    for(i = 0; i < k; ++i)
    {
        if(g[i] > b[i])
            ++green[g[i] - b[i]], ++green_alive;
        else if(g[i] < b[i])
            ++blue[b[i] - g[i]], ++blue_alive;
    }
}

int main()
{
    int bf;
    int cas, k, n_bf, i;
    scanf("%d", &cas);
    while(cas--)
    {
        for(i = 0; i < M; ++i)
           green[i] = blue[i] = 0;
        
        scanf("%d%d%d", &bf, &green_alive, &blue_alive);
        for(i = 0; i < green_alive; ++i)
           scanf("%d", &k), ++green[k];
        for(i = 0; i < blue_alive; ++i)
           scanf("%d", &k), ++blue[k];
        
        while(green_alive && blue_alive)
        {
           n_bf = min(bf, min(green_alive, blue_alive));        
           solve(n_bf);
        }
        if(green_alive)
        {
           puts("green wins");
           for(i = 101; i > 0; --i)
              while(--green[i] > -1)
                 printf("%d\n", i);
        }
        else if(blue_alive)
        {
           puts("blue wins");
           for(i = 101; i > 0; --i)
              while(--blue[i] > -1)
                 printf("%d\n", i);
        }
        else
           puts("green and blue died");
        if(cas)putchar(10);
    }
    return 0;
}
