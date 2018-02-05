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
#define M 10
typedef long long LL;
LL dp[M], dp2[M];
int main()
{
    dp[0]=6;
    dp[1]=35;
    FOR(i,2,M)dp[i]=dp[i-1]*6LL-dp[i-2];
    
    F(i,M)
    {
       LL n=dp[i];
       LL down=n*(n-1LL);
       LL total=n*(n+1LL);
       while(1)
       {
           ++n;
           LL temp=n*(n+1LL);
           if(temp-total==down){dp2[i]=n;break;}
       }
    }  
    
    F(i,M)printf("%10lld%10lld\n",dp[i],dp2[i]);
    //system("pause");
    return 0;
}
