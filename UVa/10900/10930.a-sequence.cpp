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
#define M 1001
int a[35];
int dp[M];
int main()
{
    int t,cas=1;
    while(scanf("%d",&t)!=EOF)
    {          
         memset(dp,0,sizeof(dp));
         dp[0]=1;
         int ant=0,f=0;
         F(i,t)
         {
               scanf("%d",&a[i]);
               for(int j=1000;j>=0;j--)
                  if(dp[j] && j+a[i]<=1000)++dp[j+a[i]];
         }
         if(a[0]<1)f=1;
         FOR(i,1,t)
               if(a[i-1]>=a[i]){f=1;break;}

         F(i,t)
               if(dp[a[i]]>1){f=1;break;}
         
         printf("Case #%d:",cas++);
         F(i,t)
               printf(" %d",a[i]);
         NL;
         if(!f)printf("This is an A-sequence.\n");
         else printf("This is not an A-sequence.\n");
    }
    return 0;
}
