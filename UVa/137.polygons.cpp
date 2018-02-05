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

#define E 1e-4
struct point{
       double x, y;
       bool operator==(const point &other)const
       {
            return fabs(other.x - x) < E && fabs(other.y - y) < E;
       }
} p0;

point operator-(point &a, point &b)
{
    point p = {a.x - b.x, a.y - b.y};
    return p;
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

void intersection_point(line &l1, line &l2, point &p)
{
     double det = l1.A * l2.B - l2.A * l1.B;
     p.x = (l2.B * l1.C - l1.B * l2.C) / det;
     p.y = (l1.A * l2.C - l2.A * l1.C) / det;     
}

double distance_two_points(const point &p1, const point &p2)
{
     return (p2.x - p1.x) * (p2.x - p1.x)
             + (p2.y - p1.y) * (p2.y - p1.y);
}
 
double cross_product(const point p1, const point p2, const point p3)
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
     double cross;
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
     //printf("1");
     //the smallest point is p[0]
     p0 = polygon[0];
     
     //sort the remaining points based on their angle with p0
     //points are sorted in counterclockwise order from p0
     sort(polygon.begin() + 1, polygon.end(), compare_angle_points);
     //printf("2");
     
     //find the points that have the same angle starting from the last position of the array
     //these points will be part of the "last segment"
     for (i = size-2; i > 0; i--)
     {
        cross = cross_product(p0,polygon[i],polygon[size-1]);
        if (fabs(cross) > E )
           break;
     }
 
     // reverse the order of the points belonging to the "last segment"
     // so that the points are now well sorted
     reverse (polygon.begin() + i + 1, polygon.end());
     
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
     //printf("3");

     return convex_hull;
}

double polygon_area(vector<point> &P)
{
    //size will hold the number of points of the polygon
    int size;
    int i,j;
    double area;
 
    size = P.size();
    area = 0;
 
    for(i = 0, j = size - 1; i < size; j = i++)
         area += P[i].x * P[j].y - P[j].x * P[i].y;
    return fabs(area) * 0.5;
}

int point_in_polygon(vector<point> &polygon, point &p)
{
    //C is the number of times a line from point t
    //towards the polygon intersect segments of the polygon
    //if C is even = the point is outside the polygon
    //if C is odd = the point is inside the polygon
    int i, j;
    int size;
    int c;
 
    c = 0;    //assume the point is not inside the polygon
    size = polygon.size();
 
    for (i = 0, j = size - 1; i < size; j = i++) 
    {
      //the point crosses the segment's y-bound
      if ( ((polygon[i].y > p.y) != (polygon[j].y > p.y)) &&        
      //the point passes through a vertex
        (p.x < (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) 
                / (polygon[j].y - polygon[i].y) + polygon[i].x) ) 
           c = !c;
 
    }
    return c;
}

bool in_bound(point &p1, point &p2, point &p3)
{
     return max(p1.x, p2.x) >= p3.x && p3.x >= min(p1.x, p2.x) &&
            max(p1.y, p2.y) >= p3.y && p3.y >= min(p1.y, p2.y);
}

vector<point> line_segment_intersection(point &p1, point &p2, point &p3, point &p4)
{
     //printf("%lf %lf\n", cross_product(p1, p2, p3) * cross_product(p1, p2, p4),
     //                    cross_product(p3, p4, p1) * cross_product(p3, p4, p2));
     //                    SP;

     vector<point> ip;
     line l1, l2;
     point p;
     if((p1 == p3 || p1 == p4) && (p2 == p4 || p2 == p3))
     {
         ip.push_back(p1);
         ip.push_back(p2);            
         return ip;
     }
     
     double c1 = cross_product(p1, p2, p3);
     double c2 = cross_product(p1, p2, p4);
     double c3 = cross_product(p3, p4, p1);
     double c4 = cross_product(p3, p4, p2);
     
     //printf("%lf %lf %lf %lf\n", c1, c2, c3, c4);
     
     if(fabs(c1) < E)
     {
         if(in_bound(p1, p2, p3))
            ip.push_back(p3);
     }

     if(fabs(c2) < E)
     {
         if(in_bound(p1, p2, p4))
            ip.push_back(p4);
     }
     
     if(fabs(c3) < E)
     {
         if(in_bound(p3, p4, p1))
            ip.push_back(p1);
     }
     
     if(fabs(c4) < E)
     {
         if(in_bound(p3, p4, p2))
            ip.push_back(p2);
     }
     
     /*for(int i = 0; i < ip.size(); ++i)
         printf("%lf %lf\n", ip[i].x, ip[i].y); */
                       
     if(ip.size())
         return ip;
     //printf("here");
     if(c1 * c2 < 0 && c3 * c4 < 0)
     {
         make_line(p1, p2, l1);
         make_line(p3, p4, l2);
         intersection_point(l1, l2, p);
         ip.push_back(p);
         return ip;
     }
     
     return ip;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int na, nb;
    while(scanf("%d", &na) && na)
    {
         //read input
         vector<point> pa(na);
         for(int i = 0; i < na; ++i)
             scanf("%lf%lf", &pa[i].x, &pa[i].y);
         scanf("%d", &nb);
         vector<point> pb(nb);
         for(int i = 0; i < nb; ++i)
             scanf("%lf%lf", &pb[i].x, &pb[i].y);
             
         unique(pa.begin(), pa.end());
         unique(pb.begin(), pb.end());
         if (pa.size() < 3 || pb.size() < 3) {
             printf("%8.2lf", 0.0f);
         }

    
         vector<point> pc;
         for(int i = 0; i < na; ++i)
              if(point_in_polygon(pb, pa[i]))
                 pc.push_back(pa[i]);

         for(int i = 0; i < nb; ++i)
              if(point_in_polygon(pa, pb[i]))
                 pc.push_back(pb[i]);
         
         line l1, l2;
         point p;
         for(int i = 0; i < na; ++i)
         {
             int i2 = (i + 1) % na;
             for(int j = 0; j < nb; ++j)
             {
                  int j2 = (j + 1) % nb;   
                  vector<point> vp = line_segment_intersection(pa[i], pa[i2], pb[j], pb[j2]);
                  /*printf("(%lf %lf - %lf %lf) ", pa[i].x ,pa[i].y, pa[i2].x, pa[i2].y);
                  printf("(%lf %lf - %lf %lf)\n", pb[j].x ,pb[j].y, pb[j2].x, pb[j2].y);
                  for(int i = 0; i < vp.size(); ++i)
                       printf("%lf %lf\n", vp[i].x, vp[i].y);         
                  SP;*/
                  int size = vp.size();
                  for(int k = 0; k < size; ++k)
                     pc.push_back(vp[k]);
             }
         }
         //printf("here");
         vector<point> cv;
         double area = 0;
         if(pc.size() > 2)
         {
            cv = graham_scan(pc);
            if(cv.size() >= 3)
               area = polygon_area(cv);
         }
         //for(int i = 0; i < cv.size(); ++i)
         //   printf("%lf %lf\n", cv[i].x, cv[i].y);
         
        // printf("%d %lf\n", cv.size(), polygon_area(cv));
         printf("%8.2lf", polygon_area(pa) + polygon_area(pb) - 2.0 * area);
         //printf("%8.2lf\n", polygon_area(pa) + polygon_area(pb));
    }
    NL;
    return 0;
}
