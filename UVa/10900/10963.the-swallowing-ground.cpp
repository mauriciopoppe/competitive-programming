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
    int n, diff, x, y;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        int f = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            if(f) continue;
            if(i == 0)
               diff = x - y;
            else
               f = (x - y) != diff;
        }
        if(f) puts("no");
        else puts("yes");
        if(cas)NL;
    }
    return 0;
}
