#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define S 301
#define INF 999999999
using namespace std;

int dp[S][S],m,con[S],inf[S];

int solve(int x, int y)
{
    if(dp[x][y]!=-1)return dp[x][y];
    int mn=INF,bt;
    
    //test with each coin
    for(int i=0;i<m;i++)
    {
        if(x-con[i]>=0 && y-inf[i]>=0)
        {    
             bt=solve(x-con[i], y-inf[i]);
             dp[x-con[i]][y-inf[i]]=bt;
             if(bt+1<mn)mn=bt+1;            
        }
    }
    return dp[x][y]=mn;
}

int main()
{
    int t,s;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d %d",&m,&s);
         for(int i=0;i<m;i++)
            scanf("%d %d",&con[i],&inf[i]);
         
         memset(dp,-1,sizeof(dp));
         dp[0][0]=0;
         int p2=s*s,t;
         int mn=INF;
         for(int i=0;i<=s;i++)
            for(int j=0;j<=s;j++)
            {
                 if(i*i+j*j==p2)               //try to find a solution for s*s
                 {
                    t=solve(i,j);            
                    if(t<mn)mn=t;                        
                 }
            }
        
        if(mn==INF)printf("not possible\n");
        else printf("%d\n",mn);
    }
    return 0;
}
