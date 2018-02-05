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

struct point{
       double x, y;
} p;

double polygon_area(vector<point> &P)
{
    //size will hold the number of points of the polygon
    int size;
    int i,j;
    double area;
 
    size = P.size();
    area = 0.0;
 
    for(i = 0, j = size - 1; i < size; j = i++)
         area += P[j].x * P[i].y - P[i].x * P[j].y;
    return fabs(area) * 0.5;
}

int main()
{
    int n_pol;
    double thick, r;
    while(scanf("%d", &n_pol) && n_pol)
    {
         double area = 0.0;
         for(int i = 0; i < n_pol; ++i)
         {
             vector<point> P;
             scanf("%lf%lf%lf", &thick, &p.x, &p.y);
             P.push_back(p);
             while(1)
             {
                  scanf("%lf%lf", &p.x, &p.y);
                  if(p.x == P[0].x && p.y == P[0].y)
                      break;
                  P.push_back(p);
             }
             area += polygon_area(P) * thick;
         }
         scanf("%lf%lf", &r, &thick);
         printf("%.0lf\n", floor(area / (PI * r * r * thick)));
    }
    return 0;
}
