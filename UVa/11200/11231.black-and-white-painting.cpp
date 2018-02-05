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
    int m,n,c;
    while(scanf("%d%d%d",&n,&m,&c))
    {
          if(m==0 && n==0 && c==0)break;
          int x=n-7;
          int y=m-7;
          int a=x/2;
          int b=y/2;
          printf("%d %d\n",a,b);
          int w=a*b+(x-a)*(y-b);
          if(c==1)printf("%d\n",w);
          else printf("%d\n",x*y-w);
    }
    return 0;
}
