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
#define M 1001
#define INF 999999999
struct edge{
       int to, w, gas;
       bool operator<(const edge &other)const
       {
           return other.w < w; 
       }
};

int price[M], d[M][M], disc[M];

int main()
{
    int cities, roads;
    while(scanf("%d%d", &cities, &roads) != EOF)
    {
         if(cities + roads == 0) 
             return 0;

         vector<vector<edge> > graph(cities);
             
         for(int i = 0; i < cities; ++i)
             scanf("%d", &price[i]),
             graph[i].clear();
 
         //for(int i = 0; i < cities; ++i)
         //    printf("%d ", graph[i].size());NL;
         
         int from, to;
         edge e, t, temp;
         for(int i = 0; i < roads; ++i)
         {
             scanf("%d%d%d", &from, &to, &e.w);
             e.to = to;
             graph[from].push_back(e);
             e.to = from;
             graph[to].push_back(e);
         }
         
         //for(int i = 0; i < cities; ++i)
         //    printf(" %d", graph[i].size());NL;
         
         int query, start, end, tank;
         scanf("%d", &query);
         while(query--)
         {
             scanf("%d%d%d", &tank, &start, &end);
             
             for(int i = 0; i < cities; ++i)
                for(int j = 0; j < tank; ++j)
                   d[i][j] = INF;
             
             priority_queue<edge> q;
             e.to = start;
             e.w = 0;
             e.gas = 0;
             q.push(e);
             d[start][0] = 0;
             
             while(!q.empty())
             {
                  t = q.top();
                  q.pop();
                  
                  //printf("%d %d %d\n", t.to, t.w, t.gas);
                  //printf("to = %d  [%d] [%d]\n", t.to, td, t.gas + i - it->w);
                  
                  //disc[t.to] = 1;
                  if(t.to == end)
                      break;
                  
                  TR(graph[t.to], it)
                  {                              
                      if(it->w <= tank)
                      {                                       
                           for(int i = 0; tank >= i + t.gas; i++)
                           {
                               if(t.gas + i < it->w)
                                  continue;
                               
                               int td = d[t.to][t.gas] + i * price[t.to];
                               //printf("%d %d %d %d total = %d\n", d[t.to][t.gas], td, i, price[t.to], i * price[t.to]);
                               if(td < d[it->to][t.gas + i - it->w])
                               {
                                   //printf("%d %d gas = %d\n", it->to, td, t.gas + i - it->w);
                                   //SP;
                                   d[it->to][t.gas + i - it->w] = td;
                                   temp.to = it->to;
                                   temp.w = td;
                                   temp.gas = t.gas + i - it->w;
                                   q.push(temp);
                               }
                           }
                      }
                  }
                  //SP;
             }
             int mn = INF;
             for(int i = 0; i < tank; ++i)
                mn = min(mn, d[end][i]);
             if(mn != INF)
                printf("%d\n", mn);
             else
                puts("impossible");
         }
    }
    return 0;
}
