#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 100
#define INF 999999999
using namespace std;

int dp[M][M];

int main()
{
    int m[M][2],n,i,j,k,q;
    while(scanf("%d",&n) && n)
    {
         for(i=1;i<=n;i++)
            scanf("%d%d",&m[i][0],&m[i][1]);
         
         for(i=1;i<=n;i++)
            dp[i][i]=0;
         
         for(q=2;q<=n;q++)
         {           
              for(i=1;i<=n-q+1;i++)
              {
                    j=i+q-1;              
                    dp[i][j]=INF;              
                    for(k=i;k<j;k++)
                       dp[i][j]=min(dp[i][j], dp[i][k] + dp[k+1][j] + m[i][0]*m[k][1]*m[j][1] );
              }           
              
              for(int x=1;x<=n;x++)
              {
                 for(int y=1;y<=n;y++)printf("%7d ",dp[x][y]);
                 printf("\n");     
              }
              printf("\n");
              
         }               
         
         printf("%d\n",dp[1][n]);
                         
    }
    return 0;
}
