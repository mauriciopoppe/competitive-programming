#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define I 9999999
using namespace std;

int dp[10010];
int coin[1000000];
int main()
{
    int t,total,n;
    for(scanf("%d",&t);t--;)
    {
         scanf("%d%d",&total,&n);                   
         for(int i=0;i<n;i++)
           scanf("%d",&coin[i]);
         
         fill(dp,dp+10010,I);
         dp[0]=0;
         for(int i=0;i<n;i++)
         {
              for(int j=10010;j>=coin[i];j--)
                 dp[j]=min(dp[j],dp[j-coin[i]]+1);           
         }
         
         for(int i=total;i<10010;i++)
            if(dp[i]!=I){printf("%d %d\n",i,dp[i]);break;}
                                                   
    }
    //system("pause");

    return 0;
}
