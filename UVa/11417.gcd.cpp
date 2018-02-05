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
#define M 502
int dp[M][M];
int a[M];
int gcd(int a, int b)
{
    if(!b)return a;
    return gcd(b,a%b);    
}

int main()
{
    int t;
    while(scanf("%d",&t) && t)
    {
         if(!a[t])
         {
            int r=0;                           
            for(int i=1;i<t;i++)
               for(int j=i+1;j<=t;j++)
               {
                  if(!dp[i][j])dp[i][j]=gcd(i,j);
                  r+=dp[i][j];
               }   
            a[t]=r;
         }
         printf("%d\n",a[t]);
    }
    return 0;
}
