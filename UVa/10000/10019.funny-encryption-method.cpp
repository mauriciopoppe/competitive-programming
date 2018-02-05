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
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
          scanf("%d",&n);
          int b1=0,b2=0;
          for(int i=0;1<<i <= n;i++)
             if(n&1<<i)++b1;   
          
          int k=0;
          int b16=1;
          while(n>0)
          {
               k+=b16*(n%10);
               n/=10;
               b16*=16;     
          }
          
          for(int i=0;1<<i <= k;i++)
             if(k&1<<i)++b2;   

          printf("%d %d\n",b1,b2);       
    }
    return 0;
}
