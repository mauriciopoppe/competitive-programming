#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#define M 500
using namespace std;
typedef long long LL;
LL dp[M][M];

int pl(int &a, int &b){return a+b;}

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int k=1;k<=300;k++)
        for(int i=1;i<=300;i++)        
            for(int j=k;j<=300;j++)
               dp[i][j]+=dp[i-1][j-k];
    
    char w[100];
    int n,l,r;
    LL ans=0;
    while(gets(w))
    {
        int t=sscanf(w,"%d %d %d",&n,&l,&r);
        ans=0;
        switch(t)
        {
            case 1:
                for(int i=0;i<=300;i++)ans+=dp[i][n];
                   printf("%lld\n",ans);
                break;
            case 2:
                for(int i=0;i<=300 && i<=l;i++)ans+=dp[i][n];
                printf("%lld\n",ans);
                break;
            case 3:
                for(int i=l;i<=300 && i<=r;i++)ans+=dp[i][n]; 
                printf("%lld\n",ans);  
                break; 
        }               
    }
    return 0;
}
