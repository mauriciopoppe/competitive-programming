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

int a, b, n;
int x[101], y[101];
void solve()
{
     int ca, cb;
     for(a = 0; a <= 100; ++a)
     {
        for(b = -100; b <= 100; ++b)
        {
            ca = 0, cb = 0;
            for(int i = 0; i < 2 * n; ++i)  
            {
                int k = a * x[i] + b * y[i];           
                if(k < 0)
                    ++ca;
                else if(k > 0)
                    ++cb;
            }
            //printf("%d %d\n",ca,cb);
            if(ca == n && cb == n)
                return;
        }
     }
}

int main()
{
    while(scanf("%d",&n) && n)
    {
        for(int i = 0; i < 2 * n; ++i)
           scanf("%d%d", &x[i], &y[i]);
        solve();
        printf("%d %d\n", a, b);
    }
    return 0;
}
