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
bool b[10000];
int courses[150][150];
int size[150], needed[150];
int k, m;
int solve()
{
    for(int i = 0; i < m; ++i)
    {
        int total = 0;
        for(int j = 0; j < size[i]; ++j)
           if(b[courses[i][j]])
              ++total;
        if(total < needed[i])
           return false;
    }
    return true;
}

int main()
{
    int n;
    while(scanf("%d", &k) && k)
    {
        scanf("%d", &m);
        memset(b, 0, sizeof b);
        for(int i = 0; i < k; ++i)
           scanf("%d", &n), b[n] = 1;
        for(int i = 0; i < m; ++i)
        {
           scanf("%d%d", &size[i], &needed[i]);
           for(int j = 0; j < size[i]; ++j)
              scanf("%d", &courses[i][j]);
        }
        if(solve()) puts("yes");
        else puts("no");
    }
    return 0;
}
