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
#define M 100005
int dp[M];
int coins[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

int main()
{
    fill(dp, dp + M, IMAX);
    dp[0] = 0;
    for(int i = 0; i < 12; ++i)
       for(int j = coins[i]; j < M; ++j)
          dp[j] = min(dp[j], dp[j - coins[i]] + 1);
    int cas, n;
    scanf("%d", &cas);
    while(cas--){
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}
