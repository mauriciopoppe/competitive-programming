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
char w[15];
int n;

int dp[1<<13];

void pm(int mask)
{
     for(int i = 0; i < 12; ++i)
        if(mask & (1 << i))
           putchar('1');
        else
           putchar('0');
     NL;
}

int solve(int mask)
{
     if(dp[mask] == -1){                 
         int best = 0;
         for(int i = 0; i < 12; ++i){  
            if(i + 2 < 12 && 
                 ((1 << i) & mask) != 0 && 
                 ((1 << (i + 1)) & mask) != 0 && 
                 ((1 << (i + 2)) & mask) == 0)
                     best = max(solve(mask - (1 << i) - (1 << (i + 1)) + (1 << (i + 2))) + 1, best);
            if(i - 2 >= 0 && 
                 ((1 << i) & mask) != 0 && 
                 ((1 << (i - 1)) & mask) != 0 && 
                 ((1 << (i - 2)) & mask) == 0)
                     best = max(solve(mask - (1 << i) - (1 << (i - 1)) + (1 << (i - 2))) + 1, best);
         }
         dp[mask] = best;
     }
     return dp[mask];
}

int main()
{
    int cas;
    scanf("%d", &cas);
    gets(w);
    while(cas--)
    {
         gets(w);
         int mask = 0, total = 0;
         memset(dp, -1, sizeof dp);
         for(int i = 0; i < 12; ++i)
             if(w[i] == 'o')
                mask |= (1 << i),
                ++total;
         printf("%d\n", total - solve(mask));
    }
    return 0;
}
