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
#define E 1e-7

struct point{
       double x, y;
};

double distance_two_points(point &p1, point &p2)
{
     return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double dot_product(point &p1, point &p2)
{
    return p1.x * p2.x + p1.y * p2.y;       
}

double cross_product(point &p1, point &p2)
{
    return p1.x * p2.y - p2.x * p1.y;       
}

double distance_line_point(point &p1, point &p2, point &p3)
{
    //p1 is point A
    //p2 is point B
    //p3 is point C
    //line segment AB is composed of two points p1 and p2
    //line segment AC is composed of two points p1 and p3
    point AB;
    point AC;
    AB.x = p2.x - p1.x;
    AB.y = p2.y - p1.y;
    AC.x = p3.x - p1.x;
    AC.y = p3.y - p1.y;
 
    return fabs( cross_product(AB, AC) / distance_two_points(p1, p2));
}

double distance_segment_point(point &p1, point &p2, point &p3)
{
    //line segment AB is composed of two points p1 and p2
    //first let's assume that the point is in between
    double distance;
    distance = distance_line_point(p1, p2, p3);
 
    point AB;
    point BC;
    AB.x = p2.x - p1.x;
    AB.y = p2.y - p1.y;
    BC.x = p3.x - p2.x;
    BC.y = p3.x - p2.y;
    if(dot_product(AB,BC) >= 0)
    {
        distance = distance_two_points(p2, p3);
    }
 
    point BA;
    point AC;
    BA.x = p1.x - p2.x;
    BA.y = p1.y - p2.y;
    AC.x = p3.x - p1.x;
    AC.y = p3.x - p1.y;
    if(dot_product(BA, AC) >= 0)
    {
        distance = distance_two_points(p1, p3);
    }
    return fabs(distance);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    point p1, p2;
    point ori = {0.0, 0.0};
    double r;
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &r);
         //printf("%.15lf %.15lf\n",distance_segment_point(p1, p2, ori), r);
         if(distance_segment_point(p1, p2, ori) - r >= 0)
         {
             printf("%.3lf\n", distance_two_points(p1, p2));
             continue;
         }
         
         double d1 = distance_two_points(p1, ori);
         double side1 = sqrt(d1 * d1 - r * r);
         double angle1 = acos(r / d1);
         //printf("%lf %lf %lf\n", d1, r, angle1);
         double d2 = distance_two_points(p2, ori);
         double side2 = sqrt(d2 * d2 - r * r);
         double angle2 = acos(r / d2);
         
         //printf("%lf %lf\n", angle1, angle2);
         
         double angle = acos(dot_product(p1, p2) / (d1 * d2));
         //printf("%lf\n",angle);
         angle -= (angle1 + angle2);         
         if(fabs(angle) < E)
             printf("%.3lf\n", distance_two_points(p1, p2));
         else
             printf("%.3lf\n", side1 + side2 + angle * r);
    }
    return 0;
}
