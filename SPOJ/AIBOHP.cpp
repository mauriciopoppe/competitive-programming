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
#define M 6001
int dp[2][M];
char a[M],b[M];
int main()
{
    string s;
    int cas;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
        gets(a);
        int n = strlen(a);
        
        memset(dp,0,sizeof dp);
        for(int i = 0; i < n; j++)
        {
            for(int j = i; j > 0; --j)
            {
                if(a[0] == a[j])
                   dp[1][j] = dp[0][j-1];
                else
                   dp[1][j] = min(dp[0][])
            }
            memcpy(dp[0],dp[1],sizeof dp[1]);
        }
        printf("%d\n",dp[0][n]);
    }
    return 0;
}
