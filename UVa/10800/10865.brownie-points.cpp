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
LL v[200005][2];

int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; ++i)
           scanf("%lld%lld", &v[i][0], &v[i][1]);
        int mid = n / 2;
        int stan = 0, ollie = 0;
        for(int i = 0; i < n; ++i)
           if(i != mid)
           {
              LL x = v[i][0] - v[mid][0], y = v[i][1] - v[mid][1];
              if((LL)x * (LL)y > 0)
                  ++stan;
              else if((LL)x * (LL)y < 0)
                  ++ollie;              
           }
        printf("%d %d\n", stan, ollie);                 
    }    
    return 0;
}
