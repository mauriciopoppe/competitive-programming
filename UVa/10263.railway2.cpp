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

double distance_two_points(point &p1, point &p2)
{
       return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double cross_product(point &p1, point &p2)
{
       return p1.x * p2.y - p2.x * p1.y;       
}

double length(point &p1)
{
       return sqrt(p1.x * p1.x + p1.y * p1.y);       
}

double dot_product(point &p1, point &p2)
{
       return p1.x * p2.x + p1.y * p2.y;              
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

double distance_segment_point_insegment_point(point &p1, point &p2, point &p3, point &answer)
{
    //line segment AB is composed of two points p1 and p2
    //point answer holds the closest point on the line segment AB 
    point AB;
    point AC;
    AB.x = p2.x - p1.x;
    AB.y = p2.y - p1.y;
    AC.x = p3.x - p1.x;
    AC.y = p3.y - p1.y;
 
    double distance;
 
    //calculate r    
    double r = dot_product(AB, AC) / length(AB) / length(AB);
 
    //point p3 is between points p1 and p2
    if(0 <= r && r <= 1)
    {
          answer.x = p1.x + r * (AB.x);
          answer.y = p1.y + r * (AB.y);
          distance = distance_line_point(p1, p2, p3);
    }
 
    //the point is beyond p1 or p2
    else
    {
          if(r < 0)          //point p3 is beyond point p1
          {
               answer.x = p1.x;
               answer.y = p1.y;
               distance = distance_two_points(p1, p3);
          }
          else if(r > 1)     //point p3 is beyond point p2
          {
               answer.x = p2.x;
               answer.y = p2.y;
               distance = distance_two_points(p2, p3);
          }
    }
    return distance;
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
               double tmp=distance_segment_point_insegment_point(v[i-1],v[i],p,ans);
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
