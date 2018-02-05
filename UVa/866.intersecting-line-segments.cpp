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
#define LEFT 0
#define RIGHT 1

struct point{
       double x, y;
};

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

struct segment{
       point p1, p2;
       bool operator<(const segment &other)const
       {
            return p1.y < other.p1.y;
       }
};

struct event{
    double x;
    int type;
    segment seg;
    event(double a, int b, const segment &c)
    {
        x = a;
        type = b;
        seg = c;
    }
    
    bool operator<(const event &other)const
    {
        if(x != other.x)
            return other.x < x;
        return other.type < type;
    }
};     

double cross_product(point &p1, point &p2, point &p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) -
           (p3.x - p1.x) * (p2.y - p1.y);
}

bool segment_intersection(point p1, point p2, point p3, point p4)
{
    double c1 = cross_product(p1, p2, p3);
    double c2 = cross_product(p1, p2, p4);
    double c3 = cross_product(p3, p4, p1);
    double c4 = cross_product(p3, p4, p2);
    if((fabs(c1 * c2) < E && fabs(c3 * c4) < E) ||
       c1 * c2 > E || c3 * c4 > E)
        return false;
    return true;
}

point intersect_segments(point p1, point p2, point p3, point p4)
{
    line l1, l2;
    point p;
    
    make_line(p1, p2, l1);
    make_line(p3, p4, l2);
    intersection_point(l1, l2, p);
    return p;      
}

int sweeping_line(vector<segment> &seg)
{
     int size;
     
     priority_queue<event> q;
     size = seg.size();
     
     for(int i = 0; i < size; ++i)
     {
         double x1 = seg[i].p1.x;
         double x2 = seg[i].p2.x;
         q.push(event(min(x1, x2), LEFT, seg[i]));    
         q.push(event(max(x1, x2), RIGHT, seg[i]));
     }
     
     int cnt = size;

     set<segment> sl;
     set<segment>::iterator it;
     point p;
     
     while(!q.empty())
     {
         event e = q.top();
         q.pop();
         if(e.type == LEFT)
         {
             for(it = sl.begin(); it != sl.end(); ++it)
                if(segment_intersection(it->p1, it->p2, e.seg.p1, e.seg.p2))
                   cnt += 2;
             sl.insert(e.seg);
         }
         else
             sl.erase(e.seg);
     }
     return cnt;
}

int main()
{
    int n, cas;
    scanf("%d", &cas);
    while(cas--)
    {
         scanf("%d", &n);       
         vector<segment> seg(n);
         F(i, n)
            scanf("%lf %lf %lf %lf", &seg[i].p1.x, &seg[i].p1.y, &seg[i].p2.x, &seg[i].p2.y);
         printf("%d\n", sweeping_line(seg));
         if(cas)NL;
    }
    return 0;
}
