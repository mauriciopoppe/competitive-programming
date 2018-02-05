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

int main()
{
    map<LL, bool> m;
    LL limit = (1 << 30) * 4LL;
    printf("%lld\n", limit);
    for(int i = 0; i < 31; ++i)
    {
        LL a = 1 << i;
        for(int j = 0; j <= 20; ++j)
        {
           LL b = (LL) pow(3, (double)j);
           if(a < limit / b)
           {
              //printf("%lld %lld = %lld\n", a, b, a * b);
              //SP;
              m[a * b] = 1;
           }
        }
    }
    m[2147483648LL] = 1;
    LL n;
    vector<LL> v;
    TR(m, it)
       v.push_back(it->first);
    
    while(scanf("%lld", &n) && n)
        if(m[n])
           printf("%lld\n", n);
        else
           printf("%lld\n", *(upper_bound(v.begin(), v.end(), n)));
    return 0;
}
