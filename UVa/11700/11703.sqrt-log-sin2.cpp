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
int main()
{
    
    dp[0]=1;
    int n,last=1,x;    
    while(scanf("%d",&x))
    {
         if(x==-1)break;
         if(!dp[x])
         {
             for(n=last;n<=x;++n)
                 dp[n]=(dp[(int)((double)n-sqrt(n))]+dp[(int)log(n)]+dp[(int)((double)n*sin(n)*sin(n))])%1000000;
             last=x+1;
         }
         printf("%d\n",dp[x]);
    }
    return 0;
}
