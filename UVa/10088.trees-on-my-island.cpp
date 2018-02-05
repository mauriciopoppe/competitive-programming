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
#define M 1 << 10
LL x[M], y[M];

LL LLabs(LL x)
{
   if(x < 0)
      x = -x;
   return x;
}

int main()
{
    int n;
    
    while(scanf("%d", &n) && n)
    {
         for(int i = 0; i < n; ++i)
            scanf("%lld%lld", &x[i], &y[i]);
         
         x[n] = x[0], y[n] = y[0];
         
         LL area = 0, boundary_points = 0;
         for(int i = 0; i < n; ++i)
         {
             area += x[i] * y[i + 1] - x[i + 1] * y[i];
             //calculate visible points in the segment (x[i], y[i]), (x[i + 1], y[i + 1])
             //excluding point (x[i], y[i])
             boundary_points += __gcd(LLabs(x[i + 1] - x[i]), LLabs(y[i + 1] - y[i]));
         }
         printf("%lld\n", 1 + (LLabs(area) - boundary_points) / 2);
    }
    return 0;
}
