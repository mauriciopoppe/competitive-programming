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

int v[5000], n;

int solve()
{
    for(int i = 1; i < n; ++i)
       if(v[i] - v[i - 1] > 200)
          return 0;
    if((v[n - 1] - v[n - 2]) * 2 > 200)
       return 0;
    for(int i = n - 2; i > 0; --i)
       if(v[i] - v[i - 1] > 200)
          return 0;
    return 1;       
}

int main()
{
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; ++i)
           scanf("%d", &v[i]);
        v[n++] = 1422;
        sort(v, v + n);
        if(solve()) puts("POSSIBLE");
        else puts("IMPOSSIBLE");
    }
    return 0;
}
