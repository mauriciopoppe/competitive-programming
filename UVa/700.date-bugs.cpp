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

int range[25][2];
int year[25], possible[25];
int n, mx;

int check_equal(int k)
{
    //printf("%d\n", k);
    for(int i = 0; i < n; ++i)
    {
       int t = range[i][0] + (k - range[i][0]) % (range[i][1] - range[i][0]);
       //printf("%d %d\n", year[i], t);
       if(year[i] != t)
          return 0;
    }
    return 1;
}

int solve()
{
    for(int i = mx; i < 10000; ++i)
    {
        if(check_equal(i))
           return i;
        //SP;
    }    
    return 1000000;
}


int main()
{
    int cas = 1, k;
    while(scanf("%d", &n) && n)
    {
        mx = -1;
        for(int i = 0; i < n; ++i)
           scanf("%d%d%d", &year[i], &range[i][0], &range[i][1]),
           mx = max(mx, year[i]);
        printf("Case #%d:\n", cas++);
        if((k = solve()) < 10000)
           printf("The actual year is %d.\n", k);
        else
           puts("Unknown bugs detected.");
        NL;
    }    
    return 0;
}
