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
    int x, y;   
} p0;

vector<point> t1(3), t2(3);

int distance_two_points(const point &p1, const point &p2)
{
     return (p2.x - p1.x) * (p2.x - p1.x)
             + (p2.y - p1.y) * (p2.y - p1.y);
}
 
int cross_product(const point &p1, const point &p2, const point &p3)
{
     return (p2.x - p1.x) * (p3.y - p1.y)
            - (p3.x - p1.x) * (p2.y - p1.y);
}
 
bool compare_angle_points(const point &p, const point &q)
{
    int cross = cross_product(p0, p, q);
    if(cross == 0)     
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

int point_in_triangle(point &p1, point &p2, point &p3, point &in)
{
    return abs(cross_product(p1, p2, p3)) ==
           abs(cross_product(p1, p2, in)) + 
           abs(cross_product(p1, p3, in)) +
           abs(cross_product(p2, p3, in));
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

int segment_intersection(point p1, point p2, point p3, point p4)
{
    int a = cross_product(p1, p2, p3);    
    int b = cross_product(p1, p2, p4);    
    int c = cross_product(p3, p4, p1);    
    int d = cross_product(p3, p4, p2);
    return a * b < 0 && c * d < 0;
}

int solve()
{
    vector<point> res;
    
    //segment intersection
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if(segment_intersection(t1[i], t1[(i + 1) % 3], t2[j], t2[(j + 1) % 3]))
                return 1;

    for(int i = 0; i < 3; ++i)
    {
        if(point_in_triangle(t1[0], t1[1], t1[2], t2[i]))
           res.push_back(t2[i]);        
    }
    for(int i = 0; i < 3; ++i)
        if(point_in_triangle(t2[0], t2[1], t2[2], t1[i]))
           res.push_back(t1[i]);
    if(res.size() < 3)
        return 0;
    vector<point> cv = graham_scan(res);
    if(polygon_area(cv) > 1e-7)
        return 1;
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    scanf("%d", &cas);
    for(int z = 0; z < cas; ++z)
    {
         for(int i = 0; i < 3; ++i)
             scanf("%d%d", &t1[i].x, &t1[i].y);       
         for(int i = 0; i < 3; ++i)
             scanf("%d%d", &t2[i].x, &t2[i].y);
         printf("pair %d: ", z + 1);
         if(solve())
             puts("yes");
         else
             puts("no");             
    }
    return 0;
}
