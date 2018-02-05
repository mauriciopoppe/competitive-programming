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
int v[10000];
int main()
{
    int n, cas;
    scanf("%d", &cas);
    while(cas--)
    {
         scanf("%d", &n);
         int sum = 0;
         for(int i = 0; i < n; ++i)
         {
             scanf("%d", &v[i]);
             for(int j = 0; j < i; ++j)
                sum += v[j] <= v[i] ? 1 : 0;   
         }
         printf("%d\n", sum);
    }
    return 0;
}
