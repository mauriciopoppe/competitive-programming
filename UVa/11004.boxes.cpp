#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define MB 1001
#define ML 3001
using namespace std;
int dp[MB][ML];
int main()
{
    int n,w,l;
    while(scanf("%d",&n) && n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
             scanf("%d%d",&w,&l);
             for(int j=0;j<ML;j++)
             {
                  if(j<=l)dp[i][j]=1;
                  if(i)dp[i][j]=max(dp[i][j],dp[i-1][j]);
                  if(i && j+w<ML && j<=l)dp[i][j]=max(dp[i][j],dp[i-1][j+w]+1);   
             }           
        }
        printf("%d\n",dp[n-1][0]);
    }
    return 0;
}
