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
#define M 20
#define INF 999999999
struct edge{
       int to, w;
       bool operator<(const edge &other)const
       {
            return w > other.w;
       }
};

int graph[M][M];
int total_ways[M];
bool disc[M];
int d[M];
int mn, n, end;

int main()
{
    int cas, roads;
    int from, to, w;
    int start;
    scanf("%d", &cas);
    while(cas--)
    {
         memset(graph, 0, sizeof graph),
         memset(disc, 0, sizeof disc);
         memset(total_ways, 0, sizeof total_ways);
         scanf("%d%d", &n, &roads);
         F(i, n)
            d[i] = INF;
         F(i, roads){
             scanf("%d%d%d", &from, &to, &w);
             from--;
             to--;
             graph[from][to] = graph[to][from] = w;
         }
         start = 0;
         end = n - 1;
         edge s = {start, 0};
         d[start] = 0;
         total_ways[start] = 1;
         priority_queue<edge> q;
         q.push(s);
         
         while(!q.empty())
         {
              edge t = q.top();
              q.pop();
              if(disc[t.to]) continue;
              disc[t.to] = 1;
              for(int i = 0; i < n; ++i)
              {
                  if(!disc[i] && graph[t.to][i])
                  {
                      int td = d[t.to] + graph[t.to][i];
                      if(td < d[i])
                      {
                          total_ways[i] = total_ways[t.to];
                          d[i] = td;
                          s.w = td;
                          s.to = i;
                          q.push(s);
                      }
                      else if(td == d[i])
                          total_ways[i] += total_ways[t.to];
                  }    
              }
         }
         printf("%d\n", total_ways[end]);
    }
    return 0;
}
