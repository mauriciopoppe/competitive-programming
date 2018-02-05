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
#define INF 2000000000
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 101
#define MI 127
struct node{
       int to,w;
       bool f;
       bool operator<(const node& x)const
       {
           return x.w<w; 
       }
};
node g[M][M],t,p;
int par[M],size[M],d[M],n;
bool dis[M];
int dijkstra()
{
     memset(d,MI,sizeof d);
     memset(dis,0,sizeof dis);
     priority_queue<node> q;
     t.to=1, t.w=0;
     q.push(t);
     d[1]=0;
     
     while(!q.empty())
     {
          p=q.top();
          //printf("%d %d\n",p.to,p.w);
          q.pop();
          if(p.to==n)return false;
          dis[p.to]=1;
          F(i,size[p.to])
          {
              node *it=&g[p.to][i];           
              if(it->f)continue;
              if(!dis[it->to])
              {
                   int td=d[p.to]+it->w;
                   if(td<d[it->to])
                   {
                        d[it->to]=td;
                        par[it->to]=p.to;
                        t.to=it->to, t.w=td;
                        q.push(t);           
                   }
              }
          }
     }
     return true;
}

void killEdges()
{
     int k=n;
     /*printf("PAR ");
     F(i,n)
        printf("%d ",par[i+1]);NL;*/
     while(1)
     {
           //mark node x
           int x=par[k], y=k;
           int mn=INF, best=-1;
           F(i,size[x])
               if(g[x][i].to==y && g[x][i].w<mn)
                  mn=g[x][i].w, best=i;
           g[x][best].f=1;
           
           //mark node y
           F(i,size[y])
               if(g[y][i].to==x && g[y][i].w==mn)
               {
                    g[y][i].f=1;
                    break;
               }
           if(x==1)break;
           k=par[k];
     }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int con;
    int x,y,val;
    while(scanf("%d",&n) && n)
    {
         memset(size,0,sizeof size);
         scanf("%d",&con);
         t.f=0;
         F(i,con)
         {
              scanf("%d%d%d",&x,&y,&t.w);
              t.to=y;
              g[x][size[x]++]=t;
              t.to=x;
              g[y][size[y]++]=t;              
         }         
         memset(par,0,sizeof par);
         int total=0;
         if(dijkstra()){printf("Back to jail\n");continue;}
         killEdges();
         total+=d[n];
         if(dijkstra()){printf("Back to jail\n");continue;}
         total+=d[n];
         printf("%d\n",total);
    }
    return 0;
}
