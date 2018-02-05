#include<stdio.h>
long long v[3][2];
char w[100];
int main()
{
    int cas, i;
    scanf("%d", &cas);
    gets(w);
    while(cas--)
    {
         v[0][0] = v[2][1] = 0, v[0][1] = v[2][0] = v[1][0] = v[1][1] = 1;
         gets(w);
         for(i = 0; w[i]; ++i)
         {
             if(w[i] == 'R')             
                 v[0][0] = v[1][0], v[0][1] = v[1][1];
             else
                 v[2][0] = v[1][0], v[2][1] = v[1][1];
             v[1][0] = v[0][0] + v[2][0];
             v[1][1] = v[0][1] + v[2][1];
         }
         printf("%lld/%lld\n", v[1][0], v[1][1]);
    }
    return 0;
}
