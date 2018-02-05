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
#define E 1e-7
typedef long long LL;
struct point{
       double x, y;
} p0;

point operator-(point &p1, point &p2)
{
     point c = {p1.x - p2.x, p1.y - p2.y};
     return c;  
}

struct line{
       double A,B,C;
       };
 
void make_line(point &p1, point &p2, line &l)
{
     l.A = p2.y - p1.y;
     l.B = p1.x - p2.x;
     l.C = l.A * p1.x + l.B * p1.y;
}

double cp(point p1, point p2)
{
     return p1.x * p2.y - p2.x * p1.y;
}

void intersection_point(line &l1, line &l2, point &p)
{
     double det = l1.A * l2.B - l2.A * l1.B;
     p.x = (l2.B * l1.C - l1.B * l2.C) / det;
     p.y = (l1.A * l2.C - l2.A * l1.C) / det;     
}

double relative_direction(point &p0, point &p1, point &p2)
{
    //this method is the same as consecutive_segment_line_turn
    //but instead it returns the cross value directly
    point AB;
    point AC;
    AB.x = p1.x - p0.x;
    AB.y = p1.y - p0.y;
    AC.x = p2.x - p0.x;
    AC.y = p2.y - p0.y;
    return cp(AC, AB);
}
 
bool on_segment(point &p0, point &p1, point &p2)
{
    double min_x, max_x;
    double min_y, max_y;
 
    min_x = p0.x;
    max_x = p1.x;
    if(min_x > max_x)
       swap(min_x, max_x);
 
    min_y = p0.y;
    max_y = p1.y;
    if(min_y > max_y)
       swap(min_y, max_y);
 
    if((min_x <= p2.x && p2.x <= max_x) &&
       (min_y <= p2.y && p2.y <= max_y))
           return true;
    return false;   
}
 
bool line_intersection(point &p1, point &p2, point &p3, point &p4)
{
    double d1, d2, d3, d4;          //relative orientations of a point respect to a line
    d1 = relative_direction(p3 ,p4 ,p1);
    d2 = relative_direction(p3, p4, p2);
    d3 = relative_direction(p1, p2, p3);
    d4 = relative_direction(p1, p2, p4);
 
    //line segments intersect
    /*
        if all direction are nonzero it's kinda easy test if the segments intersect
        if we do cross product of p3, p4, p1 we're testing if the line segment p3p1
        is clockwise or counterclockwise respect to the line segment p3p4
        if p3p1 x p3p4 > 0 that means that segment p3p1 is clockwise respect to p3p4
        if p3p1 x p3p4 < 0 that means that segment p3p1 is counterclockwise respect to p3p4
        if p3p1 x p3p4 = 0 that means that segments are colinear
    */
    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
       ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
            return true;
 
    // there may be a point of any segment which lies on the others points' line
    else if(d1 == 0 && on_segment(p3, p4, p1))
        return true;
    else if(d2 == 0 && on_segment(p3, p4, p2))
        return true;
    else if(d3 == 0 && on_segment(p1, p2, p3))
        return true;
    else if(d4 == 0 && on_segment(p1, p2, p4))
        return true;
 
    //no success
    return false;
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    double N, W, H, x, y;    
    point p, p1, p2, c, ip;
    line l1, l2;
    int cas = 1;
    while(scanf("%lf%lf%lf%lf%lf", &N, &W, &H ,&c.x, &c.y) != EOF)
    {
         //initial points
         vector<point> P;
         p.x = 0, p.y = 0, P.push_back(p);
         p.x = W, p.y = 0, P.push_back(p);
         p.x = W, p.y = H, P.push_back(p);         
         p.x = 0, p.y = H, P.push_back(p);
                  
         for(int z = 0; z < N; ++z) 
         {
             scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
             
             //initial location of the center
             double ini = cp(p2 - p1, c - p1);
             int sign = ini > 0 ? 1 : -1; 
             vector<point> in_hull;
             vector<point> solved;
             in_hull.push_back(c);
             int size = P.size();
             int cnt = 0;
             for(int i = 0, j = size - 1; i < size; j = i++)
             {
                 if(line_intersection(p1, p2, P[j], P[i])) 
                 {
                     make_line(p1, p2, l1);
                     make_line(P[j], P[i], l2);
                     intersection_point(l1, l2, ip);
                     /*printf("INTERSECTION :");
                     printf("%lf %lf - %lf %lf\n", P[j].x, P[j].y, P[i].x, P[i].y);
                     printf("At %lf %lf\n", ip.x, ip.y);*/
                     solved.push_back(ip);   
                 }
                 in_hull.push_back(P[i]);
             }
             
             if(!solved.size())
                continue;
             //printf("%d\n", in_hull.size());
             
             size = in_hull.size();
             P = solved;
             for(int i = 0; i < size; ++i)
             {
                 double k = cp(p2 - p1, in_hull[i] - p1);
                 int sign_k = k > 0 ? 1 : -1;
                 //printf("(%lf,%lf) %lf\n", in_hull[i].x, in_hull[i].y, k);
                 if(sign == sign_k || fabs(k) < E)
                     P.push_back(in_hull[i]);
             }
             P = graham_scan(P);
             /*for(int i = 0; i < P.size(); ++i)
                printf("%lf %lf\n", P[i].x, P[i].y);*/
         }
         printf("Case #%d: %.3lf\n", cas++, polygon_area(P));
    }
    return 0;
}
