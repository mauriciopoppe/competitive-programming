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
#define M 1000004
int b[M];

int main()
{
    int books, k, price;
    while(scanf("%d", &books) != EOF)
    {
        memset(b, 0, sizeof b);
        int mx = 0, mn = M + 1;
        for(int i = 0; i < books; ++i)              
        {
            scanf("%d", &k);
            ++b[k], mx = max(mx, k), mn = min(mn, k);            
        }
        scanf("%d", &price);
        int mid = price / 2;
        int i;
        for(i = mid; i >= mn; --i)
        {
           if(i == price - i)
           {
              if(b[i] >= 2)
                 break;
           }
           else if(b[i] && b[price - i])
              break;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", i, price - i);
    }    
    return 0;
}
