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
#define M 1000000
int dp[M];
int bt(int n)
{
     if(dp[n])return dp[n];
     return dp[n]=(bt((int)((double)n-sqrt(n)))+
            bt((int)log(n))+
            bt((int)((double)n*sin(n)*sin(n))))%1000000;
}

int main()
{
    memset(dp,0,sizeof dp);
    dp[0]=1;
    int n;
    while(scanf("%d",&n))
    {
         if(n==-1)break;
         printf("%d\n",bt(n));                
    }
    return 0;
}
