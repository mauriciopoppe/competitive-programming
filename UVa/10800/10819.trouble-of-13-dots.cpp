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
#define M 101
#define S 10500
int w[M],v[M];
int dp[S];
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
         int k=m;
         m+=200;                          
         F(i,n)
            scanf("%d%d",&w[i],&v[i]);
         memset(dp,0,sizeof dp);
         //dp[0]=1;
         F(i,n)
         {
              for(int j=m;j>=w[i];--j)
                 if(j-w[i]==0 || (j-w[i]>0 && dp[j-w[i]]!=0))
                    dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
         }
         int mx=0;
         F(i,m+1)
         {
               if(i<=k)mx=max(mx,dp[i]);
               if(i>2000 && k+200>=i)mx=max(mx,dp[i]);
         }
         printf("%d\n",mx);
    }
    return 0;
}
