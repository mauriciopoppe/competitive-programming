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
    int cas;
    int k, h, m, walk;
    scanf("%d", &cas);
    for(int z = 0; z < cas; ++z)
    {
        scanf("%d %d:%d", &k, &h, &m);
        int t = 60 * h + m;
        int mn = 999999999;
        for(int i = 0; i < k; ++i)
        {
            scanf("%d:%d %d", &h, &m, &walk);
            int arrival = h * 60 + m;
            if(t > arrival) arrival += 1440;
            arrival += walk;
            mn = min(mn, arrival - t);
        }
        printf("Case %d: %d\n", z + 1, mn);
    }
    return 0;
}
