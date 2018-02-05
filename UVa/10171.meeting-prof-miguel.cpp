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
#define M 30
#define INF 999999999
struct edge{
       int to, w;
       bool operator<(const edge &other)const
       {
            return other.w < w;
       }
};

int manzoor[M][M], miguel[M][M];
int d_manzoor[M], dis_manzoor[M];
int d_miguel[M], dis_miguel[M];

void dijkstra(int m[][M], int d[], int dis[], int start)
{
    edge t, e;
    priority_queue<edge> q;
    e.to = start, e.w = 0;
    q.push(e);
    d[start] = 0;
    while(!q.empty())
    {
        e = q.top();
        q.pop();
        dis[e.to] = 1;
        for(int i = 0; i < M ; ++i)
        {
            if(!dis[i] && m[e.to][i] != INF)
            {
                int td = d[e.to] + m[e.to][i];
                if(td < d[i])
                {
                    d[i] = td;
                    t.to = i;
                    t.w = td;
                    q.push(t);  
                }          
            }
        }             
    }
}


int main()
{
    int con, w, k;
    char age[2], kind[2], from[2], to[2];
    char s_manzoor[2], s_miguel[2];
    while(scanf("%d", &con) && con)
    {
        for(int i = 0; i < M; ++i)
        {
           d_manzoor[i] = d_miguel[i] = INF;
           dis_manzoor[i] = dis_miguel[i] = 0;    
           for(int j = 0; j < M; ++j)
               manzoor[i][j] = miguel[i][j] = INF;
        }
        
        for(int i = 0; i < con; ++i)
        {
           scanf("%s %s %s %s %d", age, kind, from, to, &w);
           if(age[0] == 'Y')
           {
               k = manzoor[from[0] - 'A'][to[0] - 'A'];
               manzoor[from[0] - 'A'][to[0] - 'A'] = min(k, w);
               if(kind[0] == 'B')
               {
                   k = manzoor[to[0] - 'A'][from[0] - 'A'];
                   manzoor[to[0] - 'A'][from[0] - 'A'] = min(k, w);
               }
           }
           else
           {
               k = miguel[from[0] - 'A'][to[0] - 'A'];
               miguel[from[0] - 'A'][to[0] - 'A'] = min(k, w);
               if(kind[0] == 'B')
               {
                   k = miguel[to[0] - 'A'][from[0] - 'A'];
                   miguel[to[0] - 'A'][from[0] - 'A'] = min(k, w);
               }
           }
        }
        scanf("%s %s", s_manzoor, s_miguel);
        dijkstra(manzoor, d_manzoor, dis_manzoor, s_manzoor[0] - 'A');
        dijkstra(miguel, d_miguel, dis_miguel, s_miguel[0] - 'A');
        
        int mn = 999999999;
        for(int i = 0; i < M; ++i)
        //{
        //   printf("%d %d\n", d_manzoor[i], d_miguel[i]);     
           mn = min(mn, d_manzoor[i] + d_miguel[i]);
        //}
        
        if(mn == 999999999)
           puts("You will never meet.");
        else
        {
            printf("%d", mn);
            for(int i = 0; i < M; ++i)
               if(d_manzoor[i] + d_miguel[i] == mn)
                  printf(" %c", i + 'A');
            printf("\n");
        }
        
    }    
    return 0;
}
