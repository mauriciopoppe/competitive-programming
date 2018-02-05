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
#define pow2(a) ((a)*(a))
#define EP 1e-7
typedef long long LL;

struct point{
       double x,y;
       };

point p;
double r;
//points p1,p2,p3
//returns p->center of the circle, r->radius
double circle_out_of_three_points(point &p1, point &p2, point &p3)
{
     double dy_a=p2.y-p1.y;
     double dx_a=p2.x-p1.x;
     double dy_b=p3.y-p2.y;
     double dx_b=p3.x-p2.x;
     if(fabs(dx_a)<=EP && fabs(dy_b)<=EP)
     {
           p.x=(p2.x+p3.x)/2.0;
           p.y=(p1.y+p2.y)/2.0;
           r=sqrt(pow2(p1.x-p.x)+pow2(p1.y-p.y));
           return 1;
     }
     
     double ma=(p2.y-p1.y)/(p2.x-p1.x);
     double mb=(p3.y-p2.y)/(p3.x-p2.x);
     
     if(fabs(mb-ma)<=EP)return -1;
     
     p.x=(ma*mb*(p1.y-p3.y)+mb*(p1.x+p2.x)-ma*(p2.x+p3.x))/(2.0*(mb-ma));
     p.y=-(p.x-(p1.x+p2.x)/2.0)/ma+(p1.y+p2.y)/2.0;
     r=sqrt(pow2(p1.x-p.x)+pow2(p1.y-p.y));
     return 1;
}

bool is_perpendicular(point &p1, point &p2, point &p3)
{
     double dy_a=p2.y-p1.y;
     double dx_a=p2.x-p1.x;
     double dy_b=p3.y-p2.y;
     double dx_b=p3.x-p2.x;
     if(fabs(dx_a)<=EP && fabs(dy_b)<=EP)return false;
     if(fabs(dy_a)<=EP)return true;
     if(fabs(dy_b)<=EP)return true;
     if(fabs(dx_a)<=EP)return true;
     if(fabs(dx_b)<=EP)return true;
     return false;
}

int main()
{
    point p1,p2,p3;
    int n;
    while(scanf("%d",&n) && n)
    {
         vector<point> v;
         v.resize(n+1);
         F(i,n)scanf("%lf%lf",&v[i].x,&v[i].y);
         int mx=0;
         for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
               for(int k=j+1;k<n;k++)
               {                
                     p1.x=v[i].x, p1.y=v[i].y;          
                     p2.x=v[j].x, p2.y=v[j].y;          
                     p3.x=v[k].x, p3.y=v[k].y;          
                     
                     if(!is_perpendicular(p1,p2,p3))circle_out_of_three_points(p1,p2,p3);
                     else if(!is_perpendicular(p1,p3,p2))circle_out_of_three_points(p1,p3,p2);
                     else if(!is_perpendicular(p2,p1,p3))circle_out_of_three_points(p2,p1,p3);
                     else if(!is_perpendicular(p2,p3,p1))circle_out_of_three_points(p2,p3,p1);
                     else if(!is_perpendicular(p3,p1,p2))circle_out_of_three_points(p3,p1,p2);
                     else circle_out_of_three_points(p3,p2,p1);
                     
                     int c=0;
                     r*=r;
                     F(x,n)
                        if(pow2(p.x-v[x].x)+pow2(p.y-v[x].y)-r==0)c++;
                     if(c>mx)mx=c;                                                                       
               }
         printf("%d\n",mx);
    }    
    return 0;
}
