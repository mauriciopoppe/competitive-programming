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

int main()
{
    int cas, n;
    int x1, y1, x2, y2;
    int cx1, cy1, cx2, cy2;
    scanf("%d", &cas);
    F(z, cas)
    {
        scanf("%d", &n);
        bool f = 1;
        for(int i = 0; f && i < n; ++i)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if(x1 >= x2 || y1 >= y2)
                f = 0;
            if(i == 0)
                cx1 = x1, cy1 = y1, cx2 = x2, cy2 = y2;
            else
            {
                int lx = max(x1, cx1);
                int ux = min(x2, cx2);
                int ly = max(y1, cy1);
                int uy = min(y2, cy2);
                if(lx >= ux || ly >= uy)
                   f = 0;
                cx1 = lx, cy1 = ly, cx2 = ux, cy2 = uy;
            }    
        }
        int area;
        if(!f) 
           area = 0;
        else
           area = (cx2 - cx1) * (cy2 - cy1);
        printf("Case %d: %d\n", z + 1, area);
    }
    return 0;
}
