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
#define E 1e-9
struct point{
       double x, y;
}p, p0;

point operator-(point &p1, point &p2)
{
      point ans = {p1.x - p2.x, p1.y - p2.y};
      return ans;
}

point operator+(point &p1, point &p2)
{
      point ans = {p1.x + p2.x, p1.y + p2.y};
      return ans;
}

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
 
     //the three first sorted point form part of the convex hull
     //j is the size of the convex_hull - 1
     vector<point> convex_hull;
     j = 0;
 
     //build the convex hull with the remaining points
     for(i = 0; i < size; ++i, ++j)
     {
          while(j >= 2 && cross_product(convex_hull[j - 2], convex_hull[j - 1], polygon[i]) <= 0)
          {
              convex_hull.pop_back();
              --j;
          }
          convex_hull.push_back(polygon[i]);
     }
     return convex_hull;
}

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

void print(point &p1)
{
    printf("%lf %lf\n", p1.x, p1.y);      
}

int main()
{
    int cas, npoints;
    double angle, w, h;
    scanf("%d", &cas);
    point p1, p2, p3, p4;
    point np1, np2, np3, np4;
    while(cas--)
    {
        scanf("%d", &npoints);
        vector<point> P;
        
        double rect_area = 0;
        
        for(int i = 0; i < npoints; ++i)
        {
           scanf("%lf%lf%lf%lf%lf", &p.x, &p.y, &w, &h, &angle);
           
           //calc points
           double hyp = sqrt(h * h + w * w);
           double xmid = w * 0.5;
           double ymid = h * 0.5;
           rect_area += h * w;
           
           //first point
           p1.x = p.x + xmid; p1.y = p.y + ymid;
           p2.x = p.x + xmid; p2.y = p.y - ymid;
           p3.x = p.x - xmid; p3.y = p.y + ymid;
           p4.x = p.x - xmid; p4.y = p.y - ymid;
           
           //fix angle
           angle = angle * PI / 180.0;           
           
           //fix points
           //x' = x * cos(a) - y * sin(a)
           //y' = y * cos(a) + x * sin(a)
           
           //mid point will never change           
           p1 = p1 - p;
           np1.x = p1.x * cos(angle) - p1.y * sin(angle);
           np1.y = p1.y * cos(angle) + p1.x * sin(angle);
           np1 = np1 + p;
           
           p2 = p2 - p;
           np2.x = p2.x * cos(angle) - p2.y * sin(angle);
           np2.y = p2.y * cos(angle) + p2.x * sin(angle);
           np2 = np2 + p;
           
           p3 = p3 - p;
           np3.x = p3.x * cos(angle) - p3.y * sin(angle);
           np3.y = p3.y * cos(angle) + p3.x * sin(angle);
           np3 = np3 + p;
                 
           p4 = p4 - p;
           np4.x = p4.x * cos(angle) - p4.y * sin(angle);
           np4.y = p4.y * cos(angle) + p4.x * sin(angle);
           np4 = np4 + p;
                
           //print
           /*print(np1);
           print(np2);
           print(np3);
           print(np4);*/
           //SP;
           
           P.push_back(np1);
           P.push_back(np2);
           P.push_back(np3);
           P.push_back(np4);
           
           //SP;  
        }
        /*printf("%d\n", P.size());
        TR(P, it)
           printf("%lf %lf\n", it->x, it->y);*/
        //printf("here");
        vector<point> ch = graham_scan(P);
        //printf("here");
        double area_polygon = polygon_area(ch);
        
        printf("%.1lf %c\n", rect_area / area_polygon * 100.0, '%');
    }
    return 0;
}
