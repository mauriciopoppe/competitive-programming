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

struct point{
       int x, y;
};

struct bound{
       int lx, ly, ux, uy;
} p;

void read(bound &P)
{
    int lx, ly, ux, uy;
    scanf("%d%d%d%d", &P.lx, &P.ly, &P.ux, &P.uy);
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
         bound pa, pb;
         read(pa);
         read(pb);
         point mx, mn;
         mn.x = max(pa.lx, pb.lx);
         mn.y = max(pa.ly, pb.ly);
         mx.x = min(pa.ux, pb.ux);
         mx.y = min(pa.uy, pb.uy);
         
         if(mn.x >= mx.x || mn.y >= mx.y)
            puts("No Overlap");
         else
            printf("%d %d %d %d\n", mn.x, mn.y, mx.x, mx.y);
         if(cas)NL;   
    }
    return 0;
}
