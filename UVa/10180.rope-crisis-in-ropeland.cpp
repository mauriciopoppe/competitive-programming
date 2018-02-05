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
#define pow2(a) ((a)*(a))
#define PI (2*acos(0))

struct point 
    {
       double x, y;
    };

double closest_point_on_line_segment_to_a_point(point &a, point &b, point &p, point &ans)
{
     double num=(p.x-a.x)*(b.x-a.x)+(p.y-a.y)*(b.y-a.y);
     double den=(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
     double r=num/den;
     double s=((a.y-p.y)*(b.x-a.x)-(a.x-p.x)*(b.y-a.y))/den;
	 ans.x=a.x+r*(b.x-a.x);
     ans.y=a.y+r*(b.y-a.y);
     //printf("%lf\n",r);
     if(r>=0 && r<=1)return fabs(s)*sqrt(den);
     else
     {
         double d=0.0;
         double d1=(p.x-a.x)*(p.x-a.x)+(p.y-a.y)*(p.y-a.y);    
         double d2=(p.x-b.x)*(p.x-b.x)+(p.y-b.y)*(p.y-b.y);    
         if(d1<d2)ans.x=a.x, ans.y=a.y, d=sqrt(d1);
         else ans.x=b.x, ans.y=b.y, d=sqrt(d2);
         return d;
     }
}  

double getDistance(point &p0, point &p1)
{
     return sqrt((p0.x-p1.x)*(p0.x-p1.x)+(p0.y-p1.y)*(p0.y-p1.y));
}

int main ()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int n;
   point p1,p2,ans,ori={0,0};
   double r,d1,d2,x1,x2,a1,a2;
   scanf("%d",&n);   
   while(n--)
   {
      scanf("%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&r);
      if(fabs(p1.x-p2.x)<1e-5 && fabs(p1.y-p2.y)<1e-5)
      {
         printf("0.000\n");
         continue;
      }
      
      closest_point_on_line_segment_to_a_point(p1,p2,ori,ans);
      double dd=sqrt(ans.x*ans.x+ans.y*ans.y);
      double l3=getDistance(p1,p2);
        
      if(dd>=r)               
      {
          printf("%.3lf\n",l3);
          continue;
      }
      
      //get distances to tangent points
      d1=getDistance(p1,ori);
      x1=sqrt(pow2(d1)-pow2(r));
      a1=acos(r/d1);
      
      d2=getDistance(p2,ori);
      x2=sqrt(pow2(d2)-pow2(r));
      a2=acos(r/d2);
      
      //using dot product here
      double dot=p1.x*p2.x+p1.y*p2.y;
      double angle=acos(dot/(d1*d2));
      printf("angle = %lf\n",180.0*angle/PI);
      double res;
      angle-=(a1+a2);
      if(fabs(angle)<1e-5)
         res = sqrt(pow2(p1.x-p2.x)+pow2(p1.y-p2.y));
      else
         res = x1+angle*r+x2;      
      printf("%.3lf\n",res);
   }
   return 0;
}
