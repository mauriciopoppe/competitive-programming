#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define INF 999999999
#define M 51
using namespace std;

int dp[M][M],cuts[M];

int main()
{
    int l,n,i,j,k,x;
    while(scanf("%d",&l) && l)
    {
         scanf("%d",&n);                        
         for(i=1;i<=n;i++)
            scanf("%d",&cuts[i]);                        
         
         cuts[++n]=l;
         
         for(x=2;x<=n;x++)
         {
              for(i=0,j=i+x; i<n-x+2 ;i++,j++)
              {
                   dp[i][j]=INF;
                   for(k=i+1;k<j;k++)
                      dp[i][j]<?= (dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);                                   
              }            
         }
         printf("The minimum cutting is %d.\n",dp[0][n]);
         
    }
    return 0;
}
