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
char b[1000008];
int main()   
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    LL k,c,fl,last;
    int cas,n;
    //F(i,1000007)printf("%d\n",b[i]);
    scanf("%d",&cas);
    F(z,cas)
    {
          scanf("%lld%lld%d%lld",&k,&c,&n,&last);
          ++b[last];
          for(int i=1;i<n;++i)
             ++b[last=(k*last+c)%1000007LL];
          LL s=0;
          LL j=n+1;
          for(int i=1000006;i>0;--i)
             while(b[i])
               s+=(LL)i*(j-=2), --b[i];
          //b[fl]=0;
          printf("Case %d: %lld\n",z+1,s);
    }
    return 0;
}

