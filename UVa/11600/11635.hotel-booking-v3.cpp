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
#define M 10005
#define MINF 127
struct node{
       int to,w;
       bool operator<(const node &x)const{
            return x.w<w;
            }
       };

vector<vector<node> > g;             //main graph
vector<vector<int> > bfs;            //bfs graph
bool isHotel[M];
int dis[M], n, h[M];
int d[M];

void breadthFirstSearch()
{
    memset(dis,0,sizeof dis);
    queue<int> q;
    q.push(1), dis[1]=1;
    
    while(!q.empty())
    {
         int x=q.front();
         q.pop();
         TR(bfs[x],it)
         {
               if(!dis[*it])
               {
                    dis[*it]=dis[x]+1;
                    if(*it==n)return;
                    q.push(*it);
               }
         }
    }    
}

void dijkstra(int h)
{
     priority_queue<node> q;
     memset(d,MINF,sizeof d);
     node t,p;
     t.to=h, t.w=0;
     d[h]=0;
     
     q.push(t);
     while(!q.empty())
     {
           p=q.top();
           if(p.w>600)break;
           q.pop();
           TR(g[p.to],it)
           {
                int td=d[p.to]+it->w;
                if(td<=600 && td<d[it->to])
                {     
                      t.to=it->to, t.w=d[it->to]=td;
                      q.push(t);
                      if(isHotel[it->to])
                          bfs[h].push_back(it->to),
                          bfs[it->to].push_back(h);
                }
           }
     }
}

int main()
{
    int hotel,k,edg,from,to,val;
    node t,p;
    while(scanf("%d",&n) && n)
    {
         g.clear();
         g.resize(n+1);
         
         bfs.clear();
         bfs.resize(n+1);
         
         memset(isHotel,0,sizeof isHotel);
         
         scanf("%d",&hotel);
         F(i,hotel)
              scanf("%d",&h[i]), isHotel[h[i]]=1;
         
         h[hotel++]=1;
         h[hotel++]=n;         
         isHotel[1]=isHotel[n]=1;

         
         scanf("%d",&edg);
         F(i,edg)
         {
                 scanf("%d%d%d",&from,&to,&t.w);
                 t.to=to;
                 g[from].push_back(t);
                 
                 t.to=from;
                 g[to].push_back(t);                 
         }
         
         //run H dijkstras
         F(i,hotel)
               dijkstra(h[i]);
         //run final BFS
         breadthFirstSearch();
         
         if(dis[n])printf("%d\n",dis[n]-2);
         else printf("-1\n");
    }
    return 0;
}
