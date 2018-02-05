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

int main()
{
    int cas;
    double d,v,u;
    scanf("%d",&cas);
    F(z,cas)
    {
            
         scanf("%lf%lf%lf",&d,&v,&u);
         printf("Case %d: ",z+1);
         if(u==0 || v>=u){printf("can\'t determine\n");continue;}
         //fastest path
         double t1=d/u;
         
         //shortest path
         double t2=d/sqrt(u*u-v*v);
         if(t1!=t2)printf("%.3lf\n",fabs(t1-t2));
         else printf("can\'t determine\n");
    }
    return 0;
}
