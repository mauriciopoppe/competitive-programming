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
#define EP 1e-5
typedef long long LL;

struct point{
       double x,y;
       };

struct line{
       double y,x,b;
       };
       
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

bool areParalel(line &l1, line &l2)
{
     return fabs(l1.y-l2.y)<=EP && fabs(l1.x-l2.x)<=EP;
}
       
int main()
{
    double x1,y1,b1,x2,y2,b2;
    line l1,l2;
    while(scanf("%lf%lf%lf %lf%lf%lf",&x1,&y1,&b1,&x2,&y2,&b2))
    {
          if(!x1 && !y1 && !b1 && !x2 && !y2 && !b2)break;
          
          if(y1)
          {
              l1.y=1;
              l1.x=-x1/y1;
              l1.b=b1/y1;
          }
          else
          {
              l1.y=0;
              l1.x=1;
              l1.b=-b1/x1;
          }
          
          if(y2)
          {
              l2.y=1;
              l2.x=-x2/y2;
              l2.b=b2/y2;
          }
          else
          {
              l2.y=0;
              l2.x=1;
              l2.b=-b2/x2;
          }
          
          if(areParalel(l1,l2))printf("No fixed point exists.\n");
          else 
          {
               point p;
               getIntersectionPoint(l1,l2,p);
               printf("The fixed point is at %.2lf %.2lf.\n",p.x,p.y);     
          }
    }
    return 0;
}
