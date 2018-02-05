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
#define M 30
int dp[M],t,total;

int main()
{
    while(scanf("%d",&t) && t)
    {
          if(!dp[t])
          {
              total=t*2;      
              for(int i=t+1;;i++)
              {    
                  int now=1,c=0;
                  while(1)
                  {
                      int np=(now+i-1)%(total-c);
                      if(!np)np=total-c;
                      if(np<=t)break;
                      ++c;
                      now=np;
                      if(now==total-c+1)now=1;
                  }                      
                  end:
                      //SP;
                  if(c==t){dp[t]=i;break;}
              }
          }
          printf("%d\n",dp[t]);
    }
    return 0;
}
