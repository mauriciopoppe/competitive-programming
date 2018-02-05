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
#define M 100001
int a[M],dp[M];
int main()
{
    for(int i=1;i*i<M;i++)
       a[i*i]++;
    dp[0]=1;
    F(i,M)
    {
       dp[i]=dp[i-1];   
       if(a[i])++dp[i];
    }
    
    int a,b;
    while(scanf("%d%d",&a,&b) && a && b)
       printf("%d\n",dp[b]-dp[a-1]);
    return 0;
}
