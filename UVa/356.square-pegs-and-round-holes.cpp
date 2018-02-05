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

int main()
{
    LL dp[151];
    for(int k = 1; k <= 150; ++k)
    {
        double r = k - 0.5;
        int cnt = 0;    
        for(int i = 1; i <= k; ++i)
           for(int j = 1; j <= k; ++j)
               if(i * i + j * j < r * r)
                  cnt++;
        dp[k] = 4 * cnt;         
    }
    
    int cas = 0, n;
    while(scanf("%d", &n) != EOF)
    {
        if(cas)NL;
        cas = 1;
        printf("In the case n = %d, %d cells contain segments of the circle.\n", n, 8 * (n - 1) + 4); 
        printf("There are %d cells completely contained in the circle.\n", dp[n]);
    }
    return 0;
}
