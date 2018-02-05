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
    int n;
    int a[32],b[32];
    while(scanf("%d",&n) && n)
    {
          bool f=0;
          int k=0;
          memset(a,0,sizeof a);
          memset(b,0,sizeof b);

          while(n)
          {
               if(n&1)
               {
                    if(!f)a[k]=1;  
                    else b[k]=1;
                    f=1-f;
               }
               ++k;
               n>>=1;
          }
          int x=0,y=0;
          for(int i=32;i>=0;i--)
            x=x*2+a[i],y=y*2+b[i];
          printf("%d %d\n",x,y);
            
    }
    return 0;
}
