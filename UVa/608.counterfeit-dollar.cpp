#include<stdio.h>
#include<string.h>
#define M 15
int even[M], up[M], down[M];
int i;
int make_even(char w[])
{
    for(i = 0; w[i]; ++i)
       even[w[i] - 'A'] = 1;
}

int make_up(char w[])
{
    for(i = 0; w[i]; ++i)
       ++up[w[i] - 'A'];
}

int make_down(char w[])
{
    for(i = 0; w[i]; ++i)
       ++down[w[i] - 'A'];
}

void solve()
{
    int best = -1, cost = -1, type = 0;
    for(i = 0; i < 12; ++i)      
    {
       if(even[i]) continue;
       if(up[i] && down[i]) continue;
       if(up[i])
       {
           if(up[i] > cost)
              cost = up[i], best = i, type = 1;         
       }
       else if(down[i])
       {
           if(down[i] > cost)
              cost = down[i], best = i, type = -1;                    
       }
    }
    printf("%c is the counterfeit coin and it is ", best + 'A');
    if(type == 1) puts("light.");
    else puts("heavy.");
}

int main()
{
    char l[M], r[M], t[50], w[50], j;
    int cas;
    scanf("%d", &cas);
    gets(w);
    while(cas--)
    {
        memset(even, 0, sizeof even);
        memset(up, 0, sizeof up);
        memset(down, 0, sizeof down);
        for(j = 0; j < 3; ++j)
        {
            gets(w);
            char *ptr = strtok(w, " ");
            
            strcpy(l, ptr);
            ptr = strtok(NULL, " ");
            
            strcpy(r, ptr);
            ptr = strtok(NULL, " ");
            
            strcpy(t, ptr);
            
            if(t[0] == 'e')
               make_even(l), make_even(r);
            else if(t[0] == 'u')
               make_up(r), make_down(l);
            else
               make_up(l), make_down(r);           
        }
        solve();
    }
    return 0;
}
