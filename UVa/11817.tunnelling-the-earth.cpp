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
double great_circle_distance(double lat1, double lon1,
        double lat2, double lon2, double r)
{
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double TO_RAD = PI / 180.0;
 
    //to radians
    dlat = dlat * TO_RAD;
    dlon = dlon * TO_RAD;
    lat1 = lat1 * TO_RAD;
    lat2 = lat2 * TO_RAD;
 
    double sin_dlat = sin(dlat / 2.0);
    double sin_dlon = sin(dlon / 2.0);
    double a = sin_dlat * sin_dlat +
               sin_dlon * sin_dlon *
               cos(lat1) * cos(lat2);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    return r * c;
}

int main()
{
    int cas;
    double lat1, lon1, lat2, lon2;
    double r = 6371009;
    scanf("%d", &cas);
    while(cas--)
    {
         scanf("%lf%lf%lf%lf", &lat1, &lon1, &lat2, &lon2);
         double arc = great_circle_distance(lat1, lon1, lat2, lon2, r);
         double angle = arc / r;
         printf("%lld\n", (LL)round(arc - 2.0 * r * sin(angle * 0.5)));         
    }
    return 0;
}
