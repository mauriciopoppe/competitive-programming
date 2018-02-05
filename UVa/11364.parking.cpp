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
int v[25];
int main()
{
    int cas, n;
    scanf("%d", &cas);
    while(cas--)
    {
       int mn = 999999999;
       scanf("%d", &n);
       for(int i = 0; i < n; ++i)
           scanf("%d", &v[i]);
       sort(v, v + n);
       for(int i = v[0]; i <= v[n - 1]; ++i)
           mn = min(mn, v[n - 1] - v[0] + i - v[0] + v[n - 1] - i);
       printf("%d\n", mn);
          
    }
    return 0;
}
