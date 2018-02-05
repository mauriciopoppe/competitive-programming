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
int n, k;
LL m[150][150];

int check()
{
    for(int i = k; i < n - k; ++i)
       if(m[k][i] != m[n - k - 1][n - i - 1]) 
          return 0;
    //printf("%d\n", k);
    for(int i = k + 1; i <= n - k - 2; ++i)
       if(m[i][k] != m[n - i - 1][n - k - 1])
          return 0;
   // printf("%d\n", k);
    return 1;
}

int main()
{
    int cas;
    scanf("%d", &cas);
    F(z, cas)
    {
        scanf("%*s %*s %d", &n);
        int f = 1;
        for(int i = 0; i < n; ++i)
           for(int j = 0; j < n; ++j)        
              scanf("%lld", &m[i][j]),
              f = f & (m[i][j] >= 0);
        printf("Test #%d: ", z + 1);
        if(f)
        {
            int lev = (n + 1) / 2;
            for(k = 0; k < lev && f; ++k)
               f = check();
        }
        if(f) puts("Symmetric.");
        else puts("Non-symmetric.");
    }
    return 0;
}
