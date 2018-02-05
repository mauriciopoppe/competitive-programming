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
#define M 2001
#define MINF 2000000000
typedef long long LL;

struct edge{
       int source,dest,val;
       };

int n, m;
edge edges[M];
int d[M];

bool bellman_ford()
{
     F(i,n-1)
       F(j,m)
       {
           int td=d[edges[j].source]+edges[j].val;     
           if(td<d[edges[j].dest])
               d[edges[j].dest]=td;
       }
     //check negative cycle
     F(j,m)
        if(d[edges[j].source]+edges[j].val<d[edges[j].dest])
           return true;
     return false;
}

int main()
{
    int cas,x,y,val;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d%d",&n,&m);
         F(i,m)
               scanf("%d%d%d",&edges[i].source,&edges[i].dest,&edges[i].val);
         fill(d,d+n,MINF);
         if(bellman_ford())printf("possible\n");
         else printf("not possible\n");
    }
    return 0;
}
