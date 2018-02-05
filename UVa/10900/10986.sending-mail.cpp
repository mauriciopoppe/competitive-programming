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
#define INF 2147400000
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 20001
struct node{
       int to, w;
       bool operator<(const node &x)const
       {return x.w<w;}
       };

int d[M];
bool dis[M];
vector<vector<node> > g;

void printG(int n)
{
     F(i,n)
     {
          if(g[i].size()) 
          {TR(g[i],it)
          {
               printf("%d[%d] ",it->to,it->w);     
          }       
          NL;}
     }    
}

int main()
{
    int cas,n,m,s,t,from,to,val;
    scanf("%d",&cas);
    node p;
    F(z,cas)
    {
         scanf("%d%d%d%d",&n,&m,&s,&t);
         
         g.clear();
         g.resize(n+1);
         
         F(i,m)
         {
             scanf("%d%d%d",&from,&to,&val);             
             p.to=to, p.w=val;
             g[from].push_back(p);
             p.to=from;
             g[to].push_back(p);             
         }
         
         F(i,n+1)
            d[i]=INF, dis[i]=0;
         //printG(n+1);
         //dijkstra
         priority_queue<node> q;
         p.to=s, p.w=0;
         q.push(p);
         d[s]=0;
         
         while(!q.empty())
         {
               p=q.top();
               q.pop();
               dis[p.to]=1;
               if(dis[t])break;
               TR(g[p.to],it)
               {
                   if(!dis[it->to])
                   {
                       int td=d[p.to]+it->w;
                       if(td<d[it->to])
                       {
                           d[it->to]=td;
                           node x;
                           x.to=it->to, x.w=td;
                           q.push(x);
                       }
                   }          
               }                            
         }         
         printf("Case #%d: ",z+1);
         if(d[t]==INF)printf("unreachable\n");
         else printf("%d\n",d[t]);
    }
    return 0;
}
