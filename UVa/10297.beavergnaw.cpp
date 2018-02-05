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
#define PI (2.0 * acos(0))
int main()
{
    double D, V;
    while(scanf("%lf%lf", &D, &V))
    {
         if(D < 1e-9 && V < 1e-9)break;
         double d = D * D * D - 6.0 * V / PI;
         d = log(d) / 3.0;
         d = exp(d);
         printf("%.3lf\n", d);
    }
    return 0;
}
