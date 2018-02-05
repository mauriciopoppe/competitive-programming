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

struct point{
       double x,y;
       };

double getD(point &a, point &b)
{
       return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);       
}

int main()
{
    point g,d,p,t;
    int holes;
    while(cin>>holes)
    {
          scanf("%lf%lf%lf%lf",&g.x,&g.y,&d.x,&d.y);
          int i=0,f=0;
          
          for(;i<holes;i++)
          {
               scanf("%lf%lf",&p.x,&p.y);
               if(!f && getD(p,g)*4.0<=getD(p,d)){t=p;f=1;}
          }
          if(f)printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",t.x,t.y);
          else printf("The gopher cannot escape.\n");
    }    
    return 0;
}
