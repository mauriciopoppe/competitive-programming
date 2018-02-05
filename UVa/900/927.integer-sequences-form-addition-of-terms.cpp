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
#define M 20
LL c[M+1];
int main()
{
    int cas,g;
    LL d,k;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d",&g);
         for(int i=0;i<=g;i++)scanf("%d",&c[i]);
         scanf("%lld%lld",&d,&k);
         double x=(-d+sqrt((double)(d*d+8LL*d*k)))/2.0/d;
         LL n=(LL)ceil(x);
         //printf("n = %lld\n",n);
         LL r=0;
         for(int i=g;i>=0;i--)
             r=r*n+c[i];
         printf("%lld\n",r);
    }
    return 0;
}
