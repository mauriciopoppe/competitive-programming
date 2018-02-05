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
    int n, m, k;
    while(scanf("%d%d", &n, &m))
    {
        if(n == 0 && m == 0) break;
        map<int, int> mp;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &k);    
            ++mp[k];
        }
        for(int i = 0; i < m; ++i)
        {
            scanf("%d", &k);    
            ++mp[k];
        }
        int total = 0;
        TR(mp, it)
           if(it->second == 2)
              ++total;
        printf("%d\n", total);
    }
    return 0;
}
