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
int ans[1005];

int main()
{
    for(int i = 1; i <= 1000; ++i)
    {
        ans[i] = IMAX;
        for(int x = 1; x <= i; ++x)
           for(int y = x; x * y <= i; ++y)
           {
              int z = i / (x * y);
              if(i % (x * y) != 0)
                continue;
              if(!z || !x || !y)continue;
              //printf("%d %d %d = %d\n", x, y, z, 2 * (x * y + x * z + y * z));
              ans[i] = min(ans[i], 2 * (x * y + x * z + y * z));
           }
           
        //printf("%d %d\n", i, ans[i]);
        //SP;
    }
    //SP;
    int cas, n;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}
