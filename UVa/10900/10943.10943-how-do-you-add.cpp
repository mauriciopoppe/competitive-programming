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
LL dp[M + 1][M + 1];
int main()
{
    for(int i = 0; i <= M; ++i)
       dp[1][i] = 1;

    for(int i = 2; i <= M; ++i)
    {
       dp[i][0] = 1;
       for(int j = 1; j <= M; ++j)
                 dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % 1000000LL;  
    }
    
    /*for(int i = 0; i < 10; ++i)
    {for(int j = 0; j <= 20; ++j)
       printf("%lld ", dp[i][j]);NL;}
    */
    
    int n, k;
    while(scanf("%d%d", &n, &k))
    {
        if(n + k == 0)
           break;
        printf("%lld\n", dp[k][n]);                
    }
    return 0;
}
