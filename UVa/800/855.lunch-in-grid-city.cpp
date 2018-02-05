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
int st[50005], av[50005];
int main()
{
    int cas;
    int x, y;
    int n;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d%d", &x, &y, &n);
        for(int i = 0; i < n; ++i)        
           scanf("%d%d", &st[i], &av[i]);
        sort(st, st + n);
        sort(av, av + n);
        if(n & 1)  printf("(Street %d, Avenue %d)\n", st[n / 2], av[n / 2]);
        else  printf("(Street %d, Avenue %d)\n", st[(n - 1) / 2], av[(n - 1) / 2]);
    }
    return 0;
}
