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
#define PI 2 * acos(0)
int main()
{
    double r, a;
    char w[5];
    while(scanf("%lf%lf%s", &r, &a, w) != EOF)
    {
         if(w[0] != 'm')
         {
            if(a > 180)
                a = 360 - a;
            a = PI * a / 180.0;
         }
         else
            a = PI * a / 10800.0;
         
         r += 6440.0;
         
         double arc = r * a;
         double chord = 2.0 * sin(a / 2.0) * r;
         printf("%.6lf %.6lf\n", arc, chord);
         
    }
    return 0;
}
