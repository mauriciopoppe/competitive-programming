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

int v[50];
int n;

int my_pow(int i, int k)
{
    int t = i;
    for(int z = 1; z < k; ++z)
       t *= i;
    return t;    
}

int solve()
{
    sort(v, v + n);
    int left = 5000000;
    for(int i = n; i >= 1; --i)
    {
       //printf("%d %lf\n", v[n - i], i * log10(v[n - i]));
       if(i * log10(2 + v[n - i]) > log10(left))
          return -1;
       printf(">>%d\n", 2 * my_pow(v[n - i], i));
       left -= 2 * my_pow(v[n - i], i);
    }
    return left;
}

int main()
{
    int cas, k;
    scanf("%d", &cas);
    while(cas--)
    {
        n = 0;
        while(scanf("%d", &v[n]) && v[n])
           ++n;
        if((k = solve()) == -1)
           puts("Too expensive");
        else
           printf("%d\n", 5000000 - k);     
    }
    return 0;
}
