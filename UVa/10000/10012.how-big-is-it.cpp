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
#define pow2(a) ((a)*(a))
int dis[10];
int ind[10], num[10];
int n;
double r[10], best;
double center[10];

void check()
{
     double res = 0;
     memset(center, 0, sizeof center);
     if(n)center[0] = r[ind[0]];
     //printf("%lf\n", center[0]);
     
     for(int i = 1; i < n; ++i)
     {
         for(int j = 0; j < i; ++j)    
         {
             double dist = r[ind[i]] + r[ind[j]];
             double height = fabs(r[ind[i]] - r[ind[j]]);
             center[i] = max(center[i], center[j] + sqrt(pow2(dist) - pow2(height)));         
             //printf("%lf %lf   %lf\n", dist, height, center[j] + sqrt(pow2(dist) - pow2(height)));
             //SP;
         }
         center[i] = max(center[i], r[ind[i]]);
         //printf("%lf\n", center[i]);
     }
     if(n)
         for(int i = 0; i < n; ++i)
             center[n] = max(center[n], center[i] + r[ind[i]]);
     //printf("%lf\n", center[n]);
     best = min(best, center[n]);   
}

void bt(int c)
{
     if(c == n)
     {
        memcpy(ind, num, sizeof num);
        check();
        //SP;
     }
     else
     {
         for(int i = 0; i < n; ++i)
            if(!dis[i])
            {
                dis[i] = 1;
                num[c] = i;
                bt(c + 1);
                dis[i] = 0;       
            }         
     }
}

int main()
{    
    memset(dis,0, sizeof dis);
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d", &n);        
        F(i, n)
            scanf("%lf", &r[i]);
        best = 999999999.;
        bt(0);       
        printf("%.3lf\n", best);
    }
    return 0;
}
