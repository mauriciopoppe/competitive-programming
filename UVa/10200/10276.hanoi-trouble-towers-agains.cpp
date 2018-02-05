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
int best,n;
int a[51],dp[51];
void bt(int x)
{     
     for(int i=0;i<n;i++)
     {
         if(a[i]==0 || sqrt(x+a[i])==(int)sqrt(x+a[i]))
         {
               a[i]=x;
               bt(x+1);
               best=max(best,x);
               return;
         }
     }
}
int main()
{
    int cas;
    memset(dp,0,sizeof dp);
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d",&n);
         if(!dp[n])
         {
             best=0;
             memset(a,0,sizeof a);
             bt(1);     
             dp[n]=best;
         }
         printf("%d\n",dp[n]);
    }
    return 0;
}
