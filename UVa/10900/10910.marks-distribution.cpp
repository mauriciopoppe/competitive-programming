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
#define M 100
int dp[M][M],n,t,p,mn,mx;

int bt(int sum, int ind)
{
    if(ind==n)
    {
        if(sum==t)return 1;
        return 0;      
    }
    if(dp[sum][ind]!=-1)
        return dp[sum][ind];
    int s=0;
    //dp[sum][ind]=0;
    for(int i=mn;i<=mx;++i)
    {
         sum+=i;
         if(sum<=t)s+=bt(sum,ind+1);
         sum-=i;
    }
    return dp[sum][ind]=s;
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d%d%d",&n,&t,&p);
         mn=p, mx=t-p*(n-1);       
         memset(dp,-1,sizeof dp);
         printf("%d\n",bt(0,0));
    }
    return 0;
}
