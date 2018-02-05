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
int bank[25], banks;
int solve()
{
    for(int i = 1; i <= banks; ++i)
       if(bank[i] < 0)
          return 0;
    return 1;
}

int main()
{
    int debts, from, to, money;
    while(scanf("%d%d", &banks, &debts) && banks && debts)
    {
        for(int i = 1; i <= banks; ++i)
           scanf("%d", &bank[i]);
        for(int i = 0; i < debts; ++i)
        {
           scanf("%d%d%d", &from, &to, &money);
           bank[to] += money;
           bank[from] -= money;
        }
        if(solve())
           puts("S");
        else
           puts("N");
    }
    return 0;
}
