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
#define pow2(a) ((a) * (a))
struct point{
       double x, y;
};

struct line{
       double y, x, b;
};

double distance_two_points(point &p1, point &p2)
{
     return sqrt(pow2(p1.x - p2.x) + pow2(p1.y - p2.y));
}

void make_line(point &p1, point &p2, line &line_l)
{
     if(p1.x == p2.x)
     {
           line_l.y = 0;
           line_l.x = 1;
           line_l.b = -p1.x;  
     }
     else
     {   
           line_l.y = 1;
           line_l.x = (p2.y - p1.y) / (p2.x - p1.x);
           line_l.b = p1.y - p1.x * line_l.x; 
     }
}

void intersection_point(line &l1, line &l2, point &p)
{
     //l1 and l2 are the lines which are not collinear
     //p is the intersection point
     if(l1.y && l2.y)
     {
         p.x = (l2.b - l1.b) / (l1.x - l2.x);
         p.y = l1.x * p.x + l1.b;
     }
     else if(l1.y)
     {
         p.x = -l2.b;
         p.y = l1.x * p.x + l1.b;           
     }
     else
     {
         p.x = -l1.b;
         p.y = l2.x * p.x + l2.b;
     }
}

double polygon_area(vector<point> &P)
{
    int size = P.size();
    double area = 0;
    for(int i = 0, j = size - 1; i < size; j = i++)
        area += P[j].x * P[i].y - P[i].x * P[j].y;
    return fabs(area) * 0.5;
}

int main()
{
    double cut_size;
    int n;
    while(scanf("%lf%d", &cut_size, &n))
    {
        if(cut_size < E && n == 0)
            break;
        
        vector<point> P(n);
        for(int i = 0; i < n; ++i)
           scanf("%lf%lf", &P[i].x, &P[i].y);
        
        if(cut_size < E)
        {
            printf("%.3lf\n", polygon_area(P));
            continue; 
        }  
        
        //get all pair of points that make a line
        double d;         //distance two points
        point p1, p2;
        line l1;
        vector<line> v_line;
        for(int i = 0, j = n - 1; i < n; j = i++)
        {
             d = distance_two_points(P[j], P[i]);
             p1.x = P[i].x + cut_size / d * (P[i].y - P[j].y);
             p1.y = P[i].y - cut_size / d * (P[i].x - P[j].x);
             
             p2.x = P[j].x + cut_size / d * (P[i].y - P[j].y);
             p2.y = P[j].y - cut_size / d * (P[i].x - P[j].x);
             
             make_line(p1, p2, l1);
             v_line.push_back(l1);
        }
        
        //calculate the lines' intersection points
        vector<point> cut(n);
        
        for(int i = 0, j = n - 1; i < n; j = i++)
           intersection_point(v_line[j], v_line[i], cut[i]);
        
        printf("%.3lf\n", polygon_area(cut));
    }
    return 0;
}
