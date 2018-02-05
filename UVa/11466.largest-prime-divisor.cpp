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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int main()
{
    LL a;
    while(scanf("%lld",&a))
    {
         if(!a)break;
         a=abs(a);
         int c=0;
         LL best=-1,i=3;                  
         if(a%2==0)
         {
             ++c;
             best=2;
             while(a%2==0)
                a/=2;
         }
         //printf("%lld\n",a);
         for(;i*i<=a;i+=2)
            if(a%i==0)
            {
               best=i;
               ++c;
               while(a%i==0)
                 a/=i;
            }
         if(a>1LL)++c,best=a;
         if(c==1)printf("-1\n");
         else printf("%lld\n",best);
    }
    return 0;
}
