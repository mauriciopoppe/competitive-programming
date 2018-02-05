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
struct point{
       double x, y;
};

double polygon_area(vector<point> &polygon)
{
    //size will hold the number of points of the polygon
    int size;
    int i,j;
    double area;
 
    size = polygon.size();
    area = 0;
 
    for(i = 0; i < size; i++)
    {
         j =  (i + 1) % size;
         area += polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y;
    }
    return fabs(area) * 0.5;
}

int main()
{
    int cas, n;
    double per, sub, add;
    double w;
    scanf("%d", &cas);
    while(cas--)
    {
         scanf("%d", &n);
         vector<point> P(n);
         for(int i = 0; i < n; ++i)
            scanf("%lf%lf", &P[i].x, &P[i].y);
         scanf("%lf %lf%lf%lf", &w, &per, &sub, &add);
         double area = polygon_area(P) * w;
         double initial_area = area * per / 100.0;
         //printf("%lf %lf\n", area, initial_area);
         int j = 0;
         
         initial_area -= sub;
         if(initial_area < 0)
            printf("Lack of water."), j = 1, initial_area = 0;
            
         initial_area += add;
         if(initial_area > area)
         {
            if(j)printf(" ");
            printf("Excess of water."), j = 1, initial_area = area;             
         }
         
         if(j)printf(" ");
         printf("Final percentage: %d%%\n", (int)(initial_area / area * 100.0));
    }
    return 0;
}
