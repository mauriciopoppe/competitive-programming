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
#define INF 2147483640
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 11
bool dis[M];
int d[M], par[M];

struct node{
       int n, d;
       bool operator<(const node &x)const
       {
            return x.d<d;
       }
};

void printPath(int k)
{
     if(par[k]==-1){printf(" %d",k); return;}
     printPath(par[k]);
     printf(" %d",k);
}

int main()
{
    int n,k,to,val,s,e,cas=1;
    node p, r;
    while(1)
    {   
         scanf("%d",&n);
         if(!n)break;
         
         vector<vector<node> > g;         
         g.resize(n+1);
                  
         for(int i=1;i<=n;i++)
         {
             scanf("%d",&k);
             g[i].resize(k);
             F(j,k)
             {
                  scanf("%d%d",&p.n,&p.d);
                  g[i][j]=p;                         
             }
         }
         scanf("%d%d",&s,&e);
         F(i,M)
            d[i]=INF, dis[i]=0, par[i]=-1;
         
         priority_queue<node> q;
         p.n=s, p.d=0;
         q.push(p);
         d[s]=0;
         
         while(!q.empty())
         {
                p=q.top();
                q.pop();
                dis[p.n]=1;
                if(dis[e])break;
                TR(g[p.n],it)
                {
                     int t=d[p.n]+it->d;
                     if(!dis[it->n] && t<d[it->n])
                     {
                          d[it->n]=t;
                          par[it->n]=p.n;
                          r.n=it->n, r.d=t;
                          q.push(r);         
                     }
                }
         }
         printf("Case %d: Path =",cas++);
         printPath(e);
         printf("; %d second delay\n",d[e]);
    }
    return 0;
}
