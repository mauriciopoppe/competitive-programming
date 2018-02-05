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
int v[10005][2];
char name[10005][25];
int cas, n, k;

int solve()
{
    int c = 0, ind = -1;
    for(int i = 0; c < 2 && i < n; ++i)
        if(v[i][0] <= k && k <= v[i][1])
           ind = i, ++c;
    if(c == 1)
       return ind;
    return -1;    
}

int main()
{   
    int q;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%s%d%d", name[i], &v[i][0], &v[i][1]);
        scanf("%d", &q);
        for(int i = 0; i < q; ++i)
        {
            scanf("%d", &k);
            int f;
            if((f = solve()) >= 0)
               printf("%s\n", name[f]);
            else
               puts("UNDETERMINED");
        } 
        if(cas)putchar(10);
    }
    return 0;
}
