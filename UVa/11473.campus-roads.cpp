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
#define E 1e-9
#define pow2(a) ((a) * (a))
struct point{
       double x, y;
};

bool operator==(point p1, point p2)
{
    return fabs(p1.x - p2.x) < E &&
           fabs(p1.y - p2.y) < E;
}

double d2p(point &p1, point &p2)
{
    return sqrt(pow2(p1.x - p2.x) + pow2(p1.y - p2.y));          
}

int main()
{
    int cas;
    int n;
    double trees;
    scanf("%d", &cas);
    F(z, cas)
    {
         scanf("%d%lf", &n, &trees);
         vector<point> P(n);
         double sum = 0;
         for(int i = 0; i < n; ++i)
         {
             scanf("%lf%lf", &P[i].x, &P[i].y);
             if(i) sum += d2p(P[i], P[i - 1]);
         }
         P.push_back(P[0]);
         //P.push_back(P[0]);
         
         double len = sum / (trees - 1);
         double dis;
         point p = P[0];
         int i = 0;
         //printf("%lf len = %lf\n", sum, len);
         printf("Road #%d:\n", z + 1);
         while(1)
         {
             //print point
             printf("%.2lf %.2lf\n", p.x, p.y);
             if(p == P[n - 1])
                break;
             //advance
             double k = len;
             while(i < n && (dis = d2p(p, P[i + 1])) < k)
                k -= dis, p = P[++i];
             double px = p.x, py = p.y;
             p.x = px + k / dis * (P[i + 1].x - px);
             p.y = py + k / dis * (P[i + 1].y - py);
             //SP;             
         }
         NL;
    }
    return 0;
}
