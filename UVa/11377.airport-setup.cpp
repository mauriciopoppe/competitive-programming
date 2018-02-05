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
#define M 2001

vector<vector<int> > g;
bool airport[M], dis[M];
int par[M];
int from, to;

int main()
{
    int cas,n,m,k,t;
    scanf("%d",&cas);
    F(z,cas)
    {   
         scanf("%d%d%d",&n,&m,&k);
         memset(airport,0,sizeof(airport));
         memset(dis,0,sizeof(dis));
         memset(par,0,sizeof(par));
         g.clear();
         g.resize(n+1);
         
         F(i,k)scanf("%d",&t), airport[t]=1;           
         F(i,m)
         {
              scanf("%d%d",&from,&to);
              g[from].push_back(to);
              g[to].push_back(from);              
         }   
         printf("Case %d:\n",z+1);
         int que;
         scanf("%d",&que);
         F(i,que)
         {
               scanf("%d%d",&from,&to);
               queue<int> q;
               q.push(from);
               dis[from]=1;
               
               while(!q.empty())
               {
                    int x=q.front();
                    q.pop();
                    TR(g[x],it)
                    {
                        if(!dis[*it])
                        {
                            dis[*it]=1;
                            par[*it]=x;
                            q.push(*it);         
                        }
                    }            
               }
               
               if(dis[to])
               {
                    int c=0;
                    while(par[to]!=-1)
                    {
                         if(!airport[to])c++;
                         to=par[to];
                    }
                    printf("%d\n",c);
               }
               else printf("-1\n");               
         }         
    }
    return 0;
}
