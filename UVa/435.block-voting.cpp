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
int a[25],s,dp[1001],n,may;

int powerIndex(int x)
{
    memset(dp,0,sizeof dp);
    dp[0]=1;
    F(i,n)
    {
         if(x==i)continue;
         for(int j=s-a[i];j>=0;j--)
             dp[j+a[i]]+=dp[j];
    }
    int k=0;
    for(int i=0;i<may;i++)
       if(dp[i] && i+a[x]>=may)
          k+=dp[i];
    return k;
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d",&n);
         s=0;
         F(i,n)scanf("%d",&a[i]),s+=a[i];
         may=s/2+1;
         F(i,n)             
              printf("party %d has power index %d\n",i+1,powerIndex(i));
         NL;
    }
    return 0;
}
