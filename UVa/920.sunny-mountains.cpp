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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define PI 3.141592653589793238
#define EP 1e-5

struct point{
       double x,y;
       bool operator<(const point &p)const
       {
            return p.x>x;
       }
};

struct line{
       double y,x,b;
       };

void makeLine(point &p1, point &p2, line &l)
{
     if(p1.x==p2.x)
     {
           l.y=0;
           l.x=1;
           l.b=-p1.x;  
     }
     else
     {   
           l.y=1;
           l.x=(p1.y-p2.y)/(p1.x-p2.x);
           l.b=-p1.x*l.x+p1.y; 
     }
}

void getIntersectionPoint(line &l1, line &l2, point &p)
{
     if(l1.y && l2.y)
     {
         p.x=(l2.b-l1.b)/(l1.x-l2.x);
         p.y=l1.x*p.x+l1.b;
     }
     else if(l1.y)
     {
         p.x=-l2.b;
         p.y=l1.x*p.x+l1.b;           
     }
     else
     {
         p.x=-l1.b;
         p.y=l2.x*p.x+l2.b;
     }
}

bool arePerpendicular(line &l1, line &l2)
{
     return (l1.x*l2.x==-1);     
}

bool areParalel(line &l1, line &l2)
{
     return fabs(l1.y-l2.y)<=EP && fabs(l1.x-l2.x)<=EP;
}

double ds(point &p1, point &p2)
{
     double dx=p1.x-p2.x;
     double dy=p1.y-p2.y;  
     return sqrt(dx*dx+dy*dy);         
}

int main()
{
    line l1,l2;
    point p1, p2, ip;
    int cas,n;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d",&n);
         vector<point> p(n);   

         F(i,n)
             scanf("%lf%lf",&p[i].x,&p[i].y);
         sort(p.begin(),p.end());
         //F(i,n)
         //   printf("%.0lf %.0lf\n",p[i].x,p[i].y);
         
         point last=p[n-1];
         double s=0;
         for(int i=n-2;i>=0;i--)
         {
             if(p[i].y>last.y)
             {
                   makeLine(p[i],p[i+1],l1);
                   l2.y=1, l2.x=0, l2.b=last.y;
                   getIntersectionPoint(l1,l2,ip);
                   //printf("%d %lf %lf\n",i,ip.x,ip.y);
                   s+=ds(p[i],ip);
                   last=p[i];
             }    
         }
         printf("%.2lf\n",s);
    }    
    return 0;
}
