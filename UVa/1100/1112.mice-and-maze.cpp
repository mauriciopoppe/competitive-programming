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
#define M 105
#define INF 2000000000
struct node{
       int to,w;
       bool operator<(const node& x)const
       {
            return x.w<w;
       }
};
vector<vector<node> > g;
int d[M],dis[M];
int main()
{
    int n,e,t,con,from;
    node p,temp;
    while(scanf("%d%d%d%d",&n,&e,&t,&con)!=EOF)
    {
         g.clear();
         g.resize(n+1);
         //printf("here");
         F(i,con)
         {
              scanf("%d%d%d",&from,&p.to,&p.w);
              g[from].push_back(p);   
         }
         int c=1;
         //dijkstra
         for(int i=1;i<=n;++i)
         {
              if(i==e)continue;   
                 
              for(int j=1;j<=n;j++)
                 d[j]=INF, dis[j]=0;
              
              priority_queue<node> q;
              d[i]=0, p.to=i, p.w=0;
              q.push(p);
              while(!q.empty())
              {
                   p=q.top();
                   q.pop();
                   dis[p.to]=1;
                   if(dis[e])break;
                   TR(g[p.to],it)
                        if(!dis[it->to])
                        {
                             int td=d[p.to]+it->w;
                             if(td<d[it->to])
                             {
                                  d[it->to]=td;
                                  temp.to=it->to, temp.w=td;
                                  q.push(temp);
                             }
                        }         
              }
              if(d[e]<=t)++c;
         }
         printf("%d\n",c);
    }
    return 0;
}
