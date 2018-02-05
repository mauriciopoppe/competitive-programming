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
LL a, b, c, d, gcd;
double n;

int find_c()
{
    c = (int) d * a / b - 10;
    while(a * d >= c * b)
       ++c;
    return c;
}

int main()
{
    while(scanf("%lld%lld%lf", &a, &b, &n) != EOF)
    {
         gcd = __gcd(a, b);
         a /= gcd;
         b /= gcd;
         for(d = 1; ; ++d)
         {
             c = find_c();
             if(c * b - a * d < n * b * d + 1e-15)
                break;
         }
         printf("%lld %lld\n", c, d);
    }
    return 0;
}
