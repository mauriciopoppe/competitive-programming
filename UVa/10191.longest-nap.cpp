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
bool b[500];
int main()
{
    int n;
    int sh, sm, eh, em;
    char w[300];
    int cas = 1;
    while(scanf("%d", &n) != EOF)
    {
        memset(b, 0, sizeof b);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d:%d %d:%d", &sh, &sm, &eh, &em);
            gets(w);
            int start = (sh - 10) * 60 + sm;
            int end = (eh - 10) * 60 + em;
            for(int j = start; j < end; ++j)
               b[j] = 1;
        }
        int mx = 0;
        int start = -1, new_start;
        int k;
        for(int i = 0; i < 480; ++i)
        {
            if(!b[i])
            {
                new_start = i;
                k = 0;
                while(i < 480 && !b[i])
                  ++k, ++i;
                --i;
                
                if(k > mx)
                   mx = k, start = new_start;
            }
        }
        if(k > mx)
           mx = k, start = new_start;

        printf("Day #%d: the longest nap starts at %02d:%02d and will last for ", cas++, (start / 60) + 10, start % 60);
        if(mx >= 60)
           printf("%d hours and ", mx / 60);
        printf("%d minutes.\n", mx % 60);
    }
    return 0;
}
