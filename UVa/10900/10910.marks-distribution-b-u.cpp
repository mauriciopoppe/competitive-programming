#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 75
int dp[M][M],n,t,p,mn,mx;

int fill()
{
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
      for(int j=mn;j<=t;j++)
        for(int k=mn;k<=mx;k++)
          if(j-k>=0)
            dp[i][j]+=dp[i-1][j-k];
    return dp[n][t];
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d%d%d",&n,&t,&p);
         mn=p, mx=t-p*(n-1);       
         printf("%d\n",fill());
    }
    return 0;
}
