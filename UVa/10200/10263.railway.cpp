#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cfloat>
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

struct point{
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

point v[1000000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    point s,e,p,ans,total;
    int n;
    while(cin>>p.x>>p.y)
    {
          cin>>n;
          n++;
          F(i,n)scanf("%lf%lf",&v[i].x,&v[i].y);
          
          double mx=DBL_MAX;
          FOR(i,1,n)
          {
               double tmp=closest_point_on_line_segment_to_a_point(v[i-1],v[i],p,ans);
               //printf("%lf %lf [%lf]\n",ans.x,ans.y,tmp);     
               if(tmp<mx)
               {
                    mx=tmp;
                    total=ans;
               }
          }          
          printf("%.4lf\n%.4lf\n",total.x,total.y);
    }
    return 0;
}
