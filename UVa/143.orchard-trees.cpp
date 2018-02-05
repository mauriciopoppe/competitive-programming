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
#define EP 1e-9

struct point{
       double x, y;
} triangle[3];

double A;

double cross_product_3points(point &p1, point &p2, point &p3)
{
     point p2_a, p3_a;
     p2_a.x = p2.x - p1.x;
     p2_a.y = p2.y - p1.y;
     p3_a.x = p3.x - p1.x;
     p3_a.y = p3.y - p1.y;
     return p2_a.x * p3_a.y - p2_a.y * p3_a.x;
}
 
bool point_inside_triangle(point &p1, point &p2, point &p3, point &check)
{
     //A is the area of the triangle
     //a1, a2, a3 are the three little areas
     double a1, a2, a3;
     
     a1 = fabs(cross_product_3points(check,p1,p2)) / 2.0;
     a2 = fabs(cross_product_3points(check,p2,p3)) / 2.0;
     a3 = fabs(cross_product_3points(check,p1,p3)) / 2.0;
     if(fabs(A - a1 - a2 - a3) < EP)
        return 1;
     return 0;
}

int main()
{
    point mn, mx;
    while(scanf("%lf%lf%lf%lf%lf%lf", &triangle[0].x, &triangle[0].y, 
       &triangle[1].x, &triangle[1].y, &triangle[2].x, &triangle[2].y))
    {
          if(triangle[0].x < EP && triangle[0].y < EP &&
          triangle[1].x < EP && triangle[1].y < EP &&
          triangle[2].x < EP && triangle[2].y < EP)
               break;
          A = fabs(cross_product_3points(triangle[0], triangle[1], triangle[2])) / 2.0;
          for(int i = 0; i < 3; ++i)
          {
              mn.x = min(mn.x, triangle[i].x);
              mn.y = min(mn.y, triangle[i].y);    
              mx.x = max(mx.x, triangle[i].x);
              mx.y = max(mx.y, triangle[i].y);    
          }
          
          point p;
          mn.x = ceil(mn.x);
          mn.y = ceil(mn.y);
          mx.x = floor(mx.x);
          mx.y = floor(mx.y);
          int c = 0;
          printf("%.15lf %.15lf %.15lf %.15lf\n", mn.x, mn.y, mx.x, mx.y);
          for(int i = (int)mn.x; i <= (int)mx.x; ++i)
              for(int j = (int)mn.y; j <= (int)mx.y; ++j)
              {
                   p.x = i;
                   p.y = j;   
                   if(point_inside_triangle(triangle[0], triangle[1], triangle[2], p))
                      ++c;
              }
          printf("%4d\n", c);
    }
    return 0;
}
