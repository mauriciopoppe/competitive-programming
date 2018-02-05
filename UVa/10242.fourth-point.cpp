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
double x[10],y[10];

bool cmp(int i, int j)
{
     return (x[i]==x[j] && y[i]==y[j]);     
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int p1,p2,px;
    while(scanf("%lf%lf",&x[0],&y[0])!=EOF)
    {         
         FOR(i,1,4)scanf("%lf%lf",&x[i],&y[i]);     
         if(cmp(0,2))
         {
             px=2;
             p1=1;
             p2=3;
         }
         else if(cmp(0,3))
         {
             px=3;
             p1=1;
             p2=2;
         }
         
         else if(cmp(1,2))
         {
             px=2;
             p1=0;
             p2=3;
         }
         else
         {
             px=3;
             p1=0;
             p2=2;
         }
         printf("%.3lf %.3lf\n",x[p1]+x[p2]-x[px],y[p1]+y[p2]-y[px]);
    }
    return 0;
}
