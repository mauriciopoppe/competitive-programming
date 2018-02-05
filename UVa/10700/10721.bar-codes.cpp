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
#define S 60
LL dp[S][S];

LL bc(int N,int K,int M)
{
     for(int i=0;i<=N;i++)
        for(int j=0;j<=K;j++)
           dp[i][j]=0;
     int s=min(N,M);
     for(int i=1;i<=s;i++)dp[i][1]=1;
     for(int i=2;i<=N;i++)
        for(int j=1;j<=K;j++) 
        {
           for(int k=1;k<=M;k++)
             if(i-k>=0)
               dp[i][j]+=dp[i-k][j-1];
           F(x,N+1)
           {F(y,K+1)printf("%d ",dp[x][y]);NL;}
           SP;  
        }
     return dp[N][K];
}

int main()
{
    int n,k,m;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
       printf("%lld\n",bc(n,k,m));
    return 0;
}
