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
#define M 101
#define MINF 2000000000
typedef long long LL;

int n, k;
bool g[M][M],t[M];
int d[M],weight[M];

void printD()
{
     F(x,n)
       printf("%d ",d[x+1]);
     NL;     
}

bool bellman_ford()
{
     queue<int> q;
     q.push(1);
     d[1]=100;
     int cnt=0;
     while(!q.empty())
     {
          int x=q.front();
          t[x]=0;
          q.pop();
          for(int i=1;i<=n;i++)
          {
              if(!g[x][i])continue;
              int td=d[x]+weight[i];
              if(d[x]>0 && td>d[i])
              {
                   d[i]=td;
                   if(!t[i])
                   {
                       t[i]=1;
                       q.push(i);
                       cnt++;
                   }
              }
          }
          if(d[n]>0)return true;
          if(cnt>500000)return false;
     }
     return false;
}

int main()
{
    int cas,x,y,val,con;
    while(scanf("%d",&n))
    {
         if(n==-1)break;         
         k=0;         
         memset(g,0,sizeof g);
         memset(t,0,sizeof t);
         for(int i=1;i<=n;i++)
         {
              scanf("%d%d",&weight[i],&con);
              F(j,con)
                 scanf("%d",&y),
                 g[i][y]=1;
         }
         fill(d,d+n+1,0);
         if(bellman_ford())printf("winnable\n");
         else printf("hopeless\n");
    }
    return 0;
}
