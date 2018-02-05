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
#define PI 3.141592653589793
#define M 105
#define INF 999999999
struct edge{
       int to;
       int w;
       bool operator<(const edge &other)const
       {
            return other.w < w;
       }
};

double great_circle_distance(double lat1, double lon1,
        double lat2, double lon2, double r)
{
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double TO_RAD = PI / 180.0;
 
    //to radians
    dlat = dlat * TO_RAD;
    dlon = dlon * TO_RAD;
    lat1 = lat1 * TO_RAD;
    lat2 = lat2 * TO_RAD;
 
    double sin_dlat = sin(dlat / 2.0);
    double sin_dlon = sin(dlon / 2.0);
    double a = sin_dlat * sin_dlat +
               sin_dlon * sin_dlon *
               cos(lat1) * cos(lat2);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    return r * c;
}

double ll[M][2];
int d[M];
int dis[M];

int main()
{
    /*printf("%lf %lf\n", great_circle_distance(23.8500, 90.4000, 22.2500, 91.8333, 6378.0), 
                        great_circle_distance(22.2500, 91.8333, 23.8500, 90.4000, 6378.0));
                        
    printf("%lf %lf\n", great_circle_distance(23.8500, 90.4000, 22.5333, 88.3667, 6378.0), 
                        great_circle_distance(22.5333, 88.3667, 23.8500, 90.4000, 6378.0));*/
    
    
    int n, con, q;
    double lat, lon;
    double r = 6378.0;
    int cas = 0;
    while(scanf("%d%d%d", &n, &con, &q))
    {
        if(n + con + q == 0)
            break;
        if(cas)NL;
        vector<string> name(n);
        vector<vector<edge> > edges(n);
        map<string, int> m;
        for(int i = 0; i < n; ++i)
        {
            cin >> name[i];
            scanf("%lf%lf", &ll[i][0], &ll[i][1]);
            m[name[i]] = i;
        }
        
        string from, to;
        for(int i = 0; i < con; ++i)
        {
            cin >> from >> to;
            int nfrom = m[from], nto = m[to];
            int dis = (int)(round)(great_circle_distance(ll[nfrom][0], ll[nfrom][1], ll[nto][0], ll[nto][1], r));
            edge e; e.to = nto, e.w = dis;
            edges[nfrom].push_back(e);          
        }
        
        edge e, t;
        printf("Case #%d\n", ++cas);
        for(int z = 0; z < q; ++z)
        {
            cin >> from >> to;
            int start = m[from], end = m[to];
            priority_queue<edge> q;
            for(int i = 0; i < n; ++i)
               d[i] = INF, dis[i]= 0;
               
            d[start] = 0;
            e.to = start;
            e.w = 0;
            q.push(e);
            
            while(!q.empty())
            {
                e = q.top();
                q.pop();
                dis[e.to] = 1;
                if(dis[end]) 
                    break;
                
                TR(edges[e.to], it)
                {
                    if(!dis[it->to])
                    {
                         int td = d[e.to] + it->w;
                         if(td < d[it->to])
                         {
                             d[it->to] = td;
                             t.to = it->to;
                             t.w = td;
                             q.push(t);
                         }
                    }            
                }
            }
            
            if(dis[end])
               printf("%d km\n", d[end]);
            else
               puts("no route exists");
        }
    }
    
    return 0;
}
