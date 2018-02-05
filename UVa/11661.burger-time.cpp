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
char w[2000005];
int n;
#define INF 1000000000
int solve()
{
    int d = INF, r = INF;
    int mn = INF;
    for(int i = 0; w[i]; ++i)
    {
       if(w[i] == 'Z') return 0;
       if(w[i] == 'D')
       {
          mn = min(mn, abs(i - r));
          d = i;
       }
       if(w[i] == 'R')
       {
          mn = min(mn, abs(i - d));
          r = i;     
       }
    }
    return mn;
}

int main()
{
    while(scanf("%d", &n) && n)
    {
       scanf("%s", w);
       printf("%d\n", solve());
    }
    return 0;
}
