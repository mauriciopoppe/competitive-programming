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
#define E 1e-9
struct point{
       double x, y;
} p0;

double distance_two_points(const point &p1, const point &p2)
{
     return (p2.x - p1.x) * (p2.x - p1.x)
             + (p2.y - p1.y) * (p2.y - p1.y);
}
 
double cross_product(const point &p1, const point &p2, const point &p3)
{
     return (p2.x - p1.x) * (p3.y - p1.y)
            - (p3.x - p1.x) * (p2.y - p1.y);
}
 
bool compare_angle_points(const point &p, const point &q)
{
    double cross = cross_product(p0, p, q);
    if(fabs(cross) < E)     
       //p and q are collinear with p0 so return the one with lowest distance to p0
       return distance_two_points(p0, p) < distance_two_points(p0, q);
    if(cross > 0)
       //p is clockwise from q
       return true;
    return false;
}
 
vector<point> graham_scan(vector<point> polygon)
{
     //first let's find the smallest y_coordinate point
     //in case of a tie the smallest x_coordinate point
     int size;
     int i, j;
 
     size = polygon.size();
      //find the smallest point
     for(i = 1; i < size; ++i)
     {
          if(polygon[i].y < polygon[0].y ||
              (polygon[i].y == polygon[0].y && polygon[i].x < polygon[0].x))
          {
              swap(polygon[0], polygon[i]);
          }
     }
 
     //the smallest point is p[0]
     p0 = polygon[0];
 
     //sort the remaining points based on their angle with p0
     //points are sorted in counterclockwise order from p0
     sort(polygon.begin() + 1, polygon.end(), compare_angle_points);
 
     //find the points that have the same angle starting from the last position of the array
     //these points will be part of the "last segment"
     for (i = size-2; i > 0; i--)
     {
        double cross = cross_product(p0,polygon[i],polygon[size-1]);
        if (fabs(cross) > E )
           break;
     }
 
     // reverse the order of the points belonging to the "last segment"
     // so that the points are now well sorted
     reverse (polygon.begin() + i + 1, polygon.end());
     //the three first sorted point form part of the convex hull
     //j is the size of the convex_hull - 1
     return polygon;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas, n;
    char w[5];
    int x, y;
    scanf("%d", &cas);
    while(cas--)
    {
         scanf("%d", &n);
         vector<point> P;
         point p;
         for(int i = 0; i < n; ++i)
         {
             scanf("%lf%lf%s", &p.x, &p.y, w);
             if(w[0] == 'N')
                continue;
             P.push_back(p);
         }
         //printf("%d\n", P.size());
         vector<point> ch = graham_scan(P);
         int ind = 0;
         int size = ch.size();
         for(int i = size - 1; i >= 0; --i)
            if(ch[i].x < ch[ind].x)
               ind = i;
            else
               break;
         
         printf("%d\n", size);         
         for(int i = ind, j = 0; j < size; i = (i + 1) % size, ++j)
            printf("%.0lf %.0lf\n", ch[i].x, ch[i].y);
    }
    return 0;
}
