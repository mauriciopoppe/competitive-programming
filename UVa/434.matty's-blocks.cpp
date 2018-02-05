#include<stdio.h>
#define min(a, b)  ((a) < (b) ? a : b)
#define M 10000
int u[M], v[M];
int ut[M], vt[M];
int main()
{
    int cas, i, j;
    int n;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
              scanf("%d", &u[i]);
        for(i = 0; i < n; ++i)
              scanf("%d", &v[i]),
              ut[i] = vt[i] = 0;
                
        int mn = 0;
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
               if(u[i] == v[j] && !ut[i] && !vt[j])
                   ut[i] = vt[j] = 1, 
                   mn += u[i];
        for(i = 0; i < n; ++i)
        {
           if(!ut[i]) mn += u[i];
           if(!vt[i]) mn += v[i];           
        }
        
        int mx = 0;
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                mx += min(v[j], u[i]);

        printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", mn, mx - mn);
    }
    return 0;
}
