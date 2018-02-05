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
#define E 1e-10
int main()
{
    double l, w, k;
    int r1, r2;
    int cas = 1;
    while(scanf("%d : %d", &r1, &r2) != EOF)
    {
         double low = 0, up = 400.0;
         while(1)
         {
             double mid = (low + up) / 2.0;
             w = mid;
             l = (double)r1 / (double)r2 * w;
             //printf("%lf %lf\n", l, w);
             double d = sqrt(l * l + w * w);
             double r = d * 0.5;
             double angle = acos(1.0 - w * w / (2. * r * r));
             
             double k = l * 2.0 + 2.0 * angle * r - 400.0;
             //printf(">%lf %lf\n", 2.0 * angle * r, k);
             if(fabs(k) < E)
                 break;
             if(k > 0)
                 up = mid;
             else
                 low = mid;
         }
         printf("Case %d: %.10lf %.10lf\n", cas++, l, w);         
    }
    return 0;
}
