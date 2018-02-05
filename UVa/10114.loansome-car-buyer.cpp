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

double dep[8000];

int main()
{
    int m, dep_records, month;
    double down, amount, k;
    while(scanf("%d%lf%lf%d", &m, &down, &amount, &dep_records) && m > 0)
    {
         memset(dep, -1, sizeof dep);
         for(int i = 0; i < dep_records; ++i)
            scanf("%d%lf", &month, &k),
            dep[month] = k;
         
         double owe = amount;
         double ini = down + amount;
         down = amount / (double) m;
         //printf("%lf\n", down);
         ini *= (1 - dep[0]);
         int i = 1;
         double old = dep[0];
         while(owe > ini)
         {
             if(dep[i] > 0)
                old = dep[i];
             //printf("%d %lf %lf dep = %lf\n", i, owe, ini, old);             
             owe -= down;
             ini *= (1 - old);
             ++i;
         }
         //printf("%lf %lf\n", owe, ini);
         if(--i != 1) printf("%d months\n", i);
         else puts("1 month");
    }
    return 0;
}
