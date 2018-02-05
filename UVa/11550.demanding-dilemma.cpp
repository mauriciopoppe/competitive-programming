#include<stdio.h>

int inc[100][100];

int main()
{
    int n, m, cas, i, j;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d", &n, &m);
        int f = 1;
        for(i = 0; i < n; ++i)
           for(j = 0; j < m; ++j)
              scanf("%d", &inc[i][j]);
        
        int loc[m][n];
        for(j = 0; j < m; ++j)
        {
           int k = 0;
           for(i = 0; i < n; ++i)
               if(inc[i][j])
                  loc[j][k++] = i;    
           if(k != 2)
              f = 0, j = m;
        }
        
        if(!f)
        {
            puts("No");
            continue;
        }
        
        for(i = 0; i < m; ++i)
            for(j = i + 1; j < m; ++j)
               if(loc[i][0] == loc[j][0] &&
                  loc[i][1] == loc[j][1])
                  f = 0, j = i = m;
        if(!f)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}
