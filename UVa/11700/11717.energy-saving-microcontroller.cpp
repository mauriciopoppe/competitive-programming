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
LL v[10000];
int main()
{
    int cas;
    int inst;
    LL time_to_inactive, time_to_activate;
    scanf("%d", &cas);
    F(z, cas)
    {
        scanf("%d%lld%lld", &inst, &time_to_inactive, &time_to_activate);
        LL start = 0;
        int k = 0;
        for(int i = 0; i < inst; ++i)
            scanf("%lld", &v[i]);
        int inactive_state = 0, ignored = 0;
        int is_active = 1;
        while(k < inst)
        {
            if(is_active)
            {
                //try to run next instruction
                if(v[k] - start < time_to_inactive)
                    start = v[k++];
                else
                {
                    is_active = 0;
                    inactive_state++;
                    start = v[k++];
                }
            }
            else
            {
                if(v[k] < start + time_to_activate)
                   ignored++, ++k;
                else
                   start = start + time_to_activate,
                   is_active = 1;
            }
        }
        printf("Case %d: %d %d\n", z + 1, inactive_state, ignored);
    }
    return 0;
}
