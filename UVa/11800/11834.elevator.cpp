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
int main()
{
    int w, h, r1, r2;
    while(scanf("%d%d%d%d", &w, &h, &r1, &r2))
    {
        if(r1 + r2 + w + h == 0) 
           break;
        
        if(2 * r1 > w || 2 * r1 > h || 2 * r2 > h  || 2 * r2 > w)
        {
           puts("N");
           continue;  
        }
        
        int cx1 = r1, cy1 = r1;
        int cx2 = w - r2, cy2 = h - r2;
        
        if(pow2(r1 + r2) <= pow2(cx1 - cx2) + pow2(cy1 - cy2))
           puts("S");
        else
           puts("N");
    }
    return 0;
}
