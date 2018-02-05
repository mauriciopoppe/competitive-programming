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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

LL dp[50000];

LL pow3(LL n)
{
   return n*n*n;        
}

int main()
{
    FOR(i,1,50001)
       dp[i]=dp[i-1]+pow3(i);
    LL n;
    while(cin>>n)
    {
         //LL t=pow2((n*(n+1)/2));
         printf("%lld\n",dp[n]);
    }
    return 0;
}
