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
#define M 100001
LL a[M];
char b[1000008];
int n;

int main()   
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    LL k,c;
    int cas;
    scanf("%d",&cas);
    F(z,cas)
    {
          scanf("%lld%lld%d%lld",&k,&c,&n,&a[0]);
          ++b[a[0]];
          for(int i=1;i<n;++i)
             ++b[a[i]=(k*a[i-1]+c)%1000007LL];
          LL s=0;
          int j=-1;
          for(int i=1000006;i>=0;--i) 
             if(b[i])
               s+=(LL)b[i]*(LL)i*(LL)(n-(j+=2)), b[i]=0;

          printf("Case %d: %lld\n",z+1,s);
    }
    return 0;
}
